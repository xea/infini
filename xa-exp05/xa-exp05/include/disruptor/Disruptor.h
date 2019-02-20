#pragma once

#ifndef XA_DISRUPTOR_H
#define XA_DISRUPTOR_H


#include <iostream>
#include <cstdint>
#include <chrono>
#include <thread>
#include <atomic>
#include <mutex>
#include <array>
#include <vector>
#include <condition_variable>
#include <unordered_map>
#include <cmath>

#include "EventFactory.hpp"
#include "Sequence.hpp"
#include "SequenceBarrier.hpp"
#include "WaitStrategy.hpp"
#include "BlockingWaitStrategy.hpp"
#include "Sequencer.hpp"
#include "ProcessingSequenceBarrier.hpp"
#include "MultiProducerSequencer.hpp"
#include "EventHandler.hpp"

using namespace std::chrono_literals;

namespace Disruptor {

	// --------------------- DATA PROVIDER

	template <class T>
	class DataProvider {
	public:
		//virtual std::shared_ptr<T> get(uint64_t sequence) = 0;
		virtual T& get(int64_t sequence) = 0;
	};

	// --------------------- EVENT PROCESSOR

	class EventProcessor {
	public:
		virtual std::shared_ptr<Sequence> getSequence() = 0;
		virtual void run() = 0;
	};

	// --------------------- BATCH EVENT PROCESSOR
	template <class T>
	class BatchEventProcessor : public EventProcessor {
	public:
		BatchEventProcessor(std::shared_ptr<DataProvider<T>> dataProvider, std::shared_ptr<SequenceBarrier> barrier, std::shared_ptr<EventHandler<T>> eventHandler) :
			dataProvider(dataProvider),
			sequenceBarrier(barrier),
			eventHandler(eventHandler),
			sequence(std::make_shared<Sequence>()) {};
		void run() override;
		std::shared_ptr<Sequence> getSequence() override;
	private:
		void processEvents();

		std::shared_ptr<DataProvider<T>> dataProvider;
		std::shared_ptr<SequenceBarrier> sequenceBarrier;
		std::shared_ptr<EventHandler<T>> eventHandler;
		std::shared_ptr<Sequence> sequence;
	};

	template <class T>
	void BatchEventProcessor<T>::run() {
		// TODO checking stuff
		processEvents();
	}

	template <class T>
	void BatchEventProcessor<T>::processEvents() {
		int64_t nextSequence = sequence->get() + 1;

		while (true) {
			int64_t availableSequence = sequenceBarrier->waitFor(nextSequence);
			// TODO batch processing code would come here
            /*
            
             if (batchStartAware != null)
             {
             batchStartAware.onBatchStart(availableSequence - nextSequence + 1);
             }
             
             */
			while (nextSequence <= availableSequence) {
				auto event = dataProvider->get(nextSequence);
				eventHandler->onEvent(event, nextSequence, nextSequence == availableSequence);
				nextSequence++;
			}
            
            sequence->set(availableSequence);
		}
	}

	template<class T>
	std::shared_ptr<Sequence> BatchEventProcessor<T>::getSequence() {
		return sequence;
	}

	// --------------------- RING BUFFER

	template<class T, size_t N = DEFAULT_SEQUENCER_SIZE>
	class RingBuffer : public DataProvider<T> {
	public:
		RingBuffer(std::unique_ptr<EventFactory<T>> factory, const uint32_t bufferSize) : 
			sequencer(std::make_shared<MultiProducerSequencer<N>>(bufferSize, std::make_unique<BlockingWaitStrategy>())), 
			factory(std::move(factory)),
			entries(std::array<T, N>()) {

			indexMask = N - 1;

			for (uint32_t i = 0; i < N; i++) {
				entries[i] = this->factory->newInstance();
			}
		};
		void publishEvent();
		void publishEvent(int64_t sequence);
        void addGatingSequences(std::vector<std::shared_ptr<Sequence>> sequences);
		static std::unique_ptr<RingBuffer> createMultiProducer(std::unique_ptr<EventFactory<T>> factory, int bufferSize);
		T elementAt(long sequence);
		std::shared_ptr<SequenceBarrier> newBarrier();
		T& get(int64_t sequence) override;
		int64_t next();
		T& operator[](int64_t sequence);
	private:
		std::shared_ptr<Sequencer> sequencer;
		std::unique_ptr<EventFactory<T>> factory;
		std::array<T, N> entries;
		uint32_t indexMask;
	};

	template<class T, size_t N> void RingBuffer<T, N>::publishEvent() {
		const long sequence = sequencer->next();
        // TODO do translation
		sequencer->publish(sequence);
	}

	template<class T, size_t N> void RingBuffer<T, N>::publishEvent(int64_t sequence) {
		sequencer->publish(sequence);
	}
    
    template<class T, size_t N> void RingBuffer<T, N>::addGatingSequences(std::vector<std::shared_ptr<Sequence>> sequences) {
        sequencer->addGatingSequences(move(sequences));
    }

	template<class T, size_t N>
	std::unique_ptr<RingBuffer<T, N>> RingBuffer<T, N>::createMultiProducer(std::unique_ptr<EventFactory<T>> factory, int bufferSize) {
		return std::make_unique<RingBuffer>(std::move(factory), bufferSize);
	}

	template<class T, size_t N>
	T RingBuffer<T, N>::elementAt(long sequence) {
		return entries[sequence & indexMask];
	}

	template<class T, size_t N>
	std::shared_ptr<SequenceBarrier> RingBuffer<T, N>::newBarrier() {
		return sequencer->newBarrier();
	}

	template<class T, size_t N>
	T& RingBuffer<T, N>::get(int64_t sequence) {
		return entries[sequence & indexMask];
	}

	template<class T, size_t N>
	int64_t RingBuffer<T, N>::next() {
		return sequencer->next();
	}

	template<class T, size_t N>
	T& RingBuffer<T, N>::operator[](int64_t sequence) {
		return entries[sequence & indexMask];
	}

	// ------------ EXECUTOR
	class Executor {
	public:
		void execute(std::shared_ptr<EventProcessor> eventProcessor);
	private:
		std::vector<std::thread> threads;
	};

	void Executor::execute(std::shared_ptr<EventProcessor> eventProcessor) {
		std::thread newThread([eventProcessor]() {
			eventProcessor->run();
		});

		threads.push_back(std::move(newThread));
	}

	// ----------------- CONSuMER INFO

	class ConsumerInfo {
	public:
		virtual void start(std::shared_ptr<Executor> executor) = 0;
	};

	// ----------------- EVENT PROCESSOR INFO
	template<class T>
	class EventProcessorInfo : public ConsumerInfo {
	public:
		EventProcessorInfo(std::shared_ptr<EventProcessor> eventProcessor, std::shared_ptr<EventHandler<T>> handler, std::shared_ptr<SequenceBarrier> barrier) :
			eventProcessor(eventProcessor),
			handler(handler),
			barrier(barrier) {};
		inline void start(std::shared_ptr<Executor> executor) override { executor->execute(eventProcessor); }
	private:
		std::shared_ptr<EventProcessor> eventProcessor;
		std::shared_ptr<EventHandler<T>> handler;
		std::shared_ptr<SequenceBarrier> barrier;
		bool endOfChain{ true };
	};

	// ----------------- CUSTOMER REPOSITORY

	template<class T>
	class ConsumerRepository {
	public:
		void add(std::shared_ptr<EventProcessor> eventProcessor, std::shared_ptr<EventHandler<T>> handler, std::shared_ptr<SequenceBarrier> barrier);
		std::vector<std::shared_ptr<ConsumerInfo>> items();
	private:
		std::unordered_map<std::shared_ptr<EventHandler<T>>, EventProcessorInfo<T>> consumerInfosByEventHandler;
		std::vector<std::shared_ptr<ConsumerInfo>> consumerInfos;
	};

	template<class T>
	void ConsumerRepository<T>::add(std::shared_ptr<EventProcessor> eventProcessor, std::shared_ptr<EventHandler<T>> handler, std::shared_ptr<SequenceBarrier> barrier) {
		auto consumerInfo = std::make_shared<EventProcessorInfo<T>>(eventProcessor, handler, barrier);
		// TODO maps
		consumerInfos.push_back(consumerInfo);
	}

	template<class T>
	std::vector<std::shared_ptr<ConsumerInfo>> ConsumerRepository<T>::items() {
		return consumerInfos;
	}

	// ----------------- DISRUPTOR

	template<class T>
	class Disruptor {
	public:
		Disruptor(std::unique_ptr<EventFactory<T>> factory, int bufferSize);
		void handleEventsWith(std::initializer_list<std::shared_ptr<EventHandler<T>>> eventHandlers);
		void start();
		std::shared_ptr<RingBuffer<T>> getRingBuffer();
	private:
		std::shared_ptr<RingBuffer<T>> ringBuffer;
		std::unique_ptr<ConsumerRepository<T>> consumerRepository;
		std::shared_ptr<Executor> executor;
	};

	template<class T> Disruptor<T>::Disruptor(std::unique_ptr<EventFactory<T>> factory, int bufferSize) {
		consumerRepository = std::make_unique<ConsumerRepository<T>>();
		ringBuffer = RingBuffer<T>::createMultiProducer(std::move(factory), bufferSize);
		executor = std::make_shared<Executor>();
	}

	template<class T> void Disruptor<T>::handleEventsWith(std::initializer_list<std::shared_ptr<EventHandler<T>>> eventHandlers) {
		std::vector<std::shared_ptr<Sequence>> processorSequences;//(eventHandlers.size());
		auto barrier = ringBuffer->newBarrier(/*barrierSequences*/);

		for (auto& eventHandler : eventHandlers) {
			auto batchEventProcessor = std::make_unique<BatchEventProcessor<T>>(ringBuffer, barrier, eventHandler);
			// TODO set exception handler

			auto nextSequence = batchEventProcessor->getSequence();

			consumerRepository->add(std::move(batchEventProcessor), eventHandler, barrier);

			processorSequences.push_back(nextSequence);
		}

        if (processorSequences.size() > 0) {
            ringBuffer->addGatingSequences(move(processorSequences));
        }
		// TODO (optional) return new event handler group
	}

	template<class T> void Disruptor<T>::start() {
		for (auto& consumerInfo : consumerRepository->items()) {
			consumerInfo->start(executor);
		}
	}

	template<class T> std::shared_ptr<RingBuffer<T>> Disruptor<T>::getRingBuffer() {
		return ringBuffer;
	}

	// ---------------- EVENT FACTORY

	class LongEvent {
	public:
		long value;
	};

	class LongEventFactory : public EventFactory<LongEvent> {
	public:
		LongEvent newInstance() override;
	};

	LongEvent LongEventFactory::newInstance() {
		return LongEvent();
	}

	class LongEventHandler : public EventHandler<LongEvent> {
	public:
		LongEventHandler(std::string id, int seq) : id(id), seq(seq) {};
		void onEvent(LongEvent& event, int64_t sequence, bool endOfBatch) override;
	private:
		std::string id;
		uint64_t counter{ 0 };
		int seq;
	};

	void LongEventHandler::onEvent(LongEvent& event, int64_t sequence, bool endOfBatch) {
		counter++;

		//if (counter % 100000 == 0) {
			std::cout << id << "-" << sequence << std::endl;
		//}
	}


	// ----------------- MAIN

	int main2(int argc, char** argv) {
		auto factory = std::make_unique<LongEventFactory>();
        auto disruptor = std::make_unique<Disruptor<LongEvent>>(std::move(factory), 4);

        disruptor->handleEventsWith({
            std::make_shared<LongEventHandler>("A", 1),
//            std::make_shared<LongEventHandler>("B", 2)
        });

        disruptor->start();

        auto ringBuffer = disruptor->getRingBuffer();

        auto publisher = [ringBuffer]() {
            int64_t nextSequence;
            
            std::cout << "Start publishing" << std::endl;

            for (long i = 0; i < 10000; i++) {
                nextSequence = ringBuffer->next();
                (*ringBuffer)[nextSequence].value = i;
                ringBuffer->publishEvent(nextSequence);
                //std::cout << "P-" << i << std::endl;
            }

            std::cout << "Publishing done" << std::endl;

            nextSequence = 0;
        };

        std::thread t1(publisher);
 //       std::thread t2(publisher);

        t1.join();
  //      t2.join();
        std::this_thread::sleep_for(10000s);
        

		return 0;
	}
}

/*
uint64_t counter{0};
std::mutex write_mutex;
std::atomic_uint64_t acounter{0};

const uint64_t MAX_VALUE = 500000;

enum class test_type : uint8_t {
normal,
locked,
atomic
};

void doLoop();
void doLockLoop();
void doAtomicLoop();

void testCore(uint16_t threadCount, test_type type);


int main(int argc, const char * argv[]) {
// insert code here...
std::cout << "Hello, World!\n";

std::cout << "Lockless 1 thread" << std::endl;
testCore(1, test_type::normal);
testCore(1, test_type::locked);
testCore(1, test_type::atomic);
std::cout << "Lockless 2 threads" << std::endl;
testCore(2, test_type::normal);
testCore(2, test_type::locked);
testCore(2, test_type::atomic);
std::cout << "Lockless 4 threads" << std::endl;
testCore(4, test_type::normal);
testCore(4, test_type::locked);
testCore(4, test_type::atomic);

return 0;
}

void testCore(uint16_t threadCount, test_type type) {
auto start = std::chrono::high_resolution_clock::now();
auto threads = std::vector<std::thread>();

for (uint16_t i = 0; i < threadCount; i++) {
auto t = std::thread([&type](){
switch (type) {
case test_type::normal:
doLoop();
break;
case test_type::atomic:
doAtomicLoop();
break;
case test_type::locked:
doLockLoop();
break;
}
});

threads.push_back(std::move(t));
}

for (auto& thread : threads) {
thread.join();
}

auto end = std::chrono::high_resolution_clock::now();

std::chrono::duration<double> diff = end - start;

std::cout << diff.count() << " seconds" << std::endl;

}

void doLoop() {
for (uint64_t i = 0; i < MAX_VALUE; i++) {
counter++;
}
}

void doLockLoop() {
for (uint64_t i = 0; i < MAX_VALUE; i++) {
std::lock_guard<std::mutex> lock(write_mutex);
counter++;
}
}

void doAtomicLoop() {
for (uint64_t i = 0; i < MAX_VALUE; i++) {
acounter++;
}
}
*/


#endif // XA_DISRUPTOR_H

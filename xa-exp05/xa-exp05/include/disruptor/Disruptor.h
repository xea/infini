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
#include "DataProvider.hpp"
#include "EventProcessor.hpp"
#include "BatchEventProcessor.hpp"
#include "RingBuffer.hpp"
#include "Executor.hpp"
#include "ConsumerInfo.hpp"
#include "EventProcessorInfo.hpp"
#include "ConsumerRepository.hpp"
#include "Disruptor.hpp"

using namespace std::chrono_literals;

namespace Disruptor {

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

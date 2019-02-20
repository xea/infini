#ifndef XA_DISRUPTOR_DISRUPTOR_HPP
#define XA_DISRUPTOR_DISRUPTOR_HPP

#include <memory>
#include <vector>
#include "EventFactory.hpp"
#include "RingBuffer.hpp"
#include "Executor.hpp"
#include "ConsumerRepository.hpp"
#include "Sequence.hpp"

namespace Disruptor {

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

}

#endif // XA_DISRUPTOR_DISRUPTOR_HPP
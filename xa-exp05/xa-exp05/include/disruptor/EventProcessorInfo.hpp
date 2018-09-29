#ifndef XA_DISRUPTOR_EVENT_PROCESSOR_INFO_HPP
#define XA_DISRUPTOR_EVENT_PROCESSOR_INFO_HPP

#include <memory>
#include "ConsumerInfo.hpp"
#include "EventProcessorInfo.hpp"
#include "SequenceBarrier.hpp"
#include "EventHandler.hpp"

namespace Disruptor {

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

}

#endif // XA_DISRUPTOR_EVENT_PROCESSOR_INFO_HPP
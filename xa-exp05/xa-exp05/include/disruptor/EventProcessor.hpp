#ifndef XA_EVENT_PROCESSOR_HPP
#define XA_EVENT_PROCESSOR_HPP

#include <memory>
#include "Sequence.hpp"

namespace Disruptor {

	class EventProcessor {
	public:
		virtual std::shared_ptr<Sequence> getSequence() = 0;
		virtual void run() = 0;
	};

}

#endif // XA_EVENT_PROCESSOR_HPP
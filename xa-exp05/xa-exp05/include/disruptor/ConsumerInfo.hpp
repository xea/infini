#ifndef XA_DISRUPTOR_CONSUMER_INFO_HPP
#define XA_DISRUPTOR_CONSUMER_INFO_HPP

#include <memory>
#include "Executor.hpp"

namespace Disruptor {

	class ConsumerInfo {
	public:
		virtual void start(std::shared_ptr<Executor> executor) = 0;
	};

}

#endif // XA_DISRUPTOR_CONSUMER_INFO_HPP
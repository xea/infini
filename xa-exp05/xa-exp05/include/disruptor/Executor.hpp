#ifndef XA_DISRUPTOR_EXECUTOR_HPP
#define XA_DISRUPTOR_EXECUTOR_HPP

#include <memory>
#include <vector>
#include <thread>
#include "EventProcessor.hpp"

namespace Disruptor {

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

}

#endif // XA_DISRUPTOR_EXECUTOR_HPP

#ifndef XA_BLOCKING_WAIT_STRATEGY_HPP
#define XA_BLOCKING_WAIT_STRATEGY_HPP

#include <atomic>
#include <condition_variable>
#include "Sequence.hpp"
#include "WaitStrategy.hpp"

namespace Disruptor {
	// Blocking WaitStrategy implementation that uses a lock-based mechanism to make processors wait on a barrier.
	// Because this WaitStrategy is using locks, it can be used to limit CPU usage when the disruptor is idle but this comes
	// at a cost of latency and throughput.
	class BlockingWaitStrategy : public WaitStrategy {
	public:
		void signalAllWhenBlocking() override;
		uint64_t waitFor(uint64_t sequence, std::shared_ptr<Sequence> cursorSequence, std::shared_ptr<Sequence> dependentSequence, std::shared_ptr<SequenceBarrier> barrier) override;
	private:
		std::condition_variable processorNotifyCondition;
		std::mutex m;
	};

	uint64_t BlockingWaitStrategy::waitFor(uint64_t sequence, std::shared_ptr<Sequence> cursorSequence, std::shared_ptr<Sequence> dependentSequence, std::shared_ptr<SequenceBarrier> barrier) {
		uint64_t availableSequence;

		if (cursorSequence->get() < sequence) {
			// Acquire a unique lock for the duration of the entire action
			std::unique_lock<std::mutex> lock(m);

			// We wait for producers until we reach the desired sequence number
			while (cursorSequence->get() < sequence) {
				barrier->checkAlert();
				processorNotifyCondition.wait(lock);
			}

			// The lock is released automatically when it goes out of the scope
		}

		while ((availableSequence = dependentSequence->get()) < sequence) {
			 barrier->checkAlert();
			// TODO: emulate onspinwait to save resources
		}

		return availableSequence;
	}

	void BlockingWaitStrategy::signalAllWhenBlocking() {
		// Acquire a unique lock to avoid interfering with potentially waitFor()-ing consumers
		std::unique_lock<std::mutex> lock(m);

		// Let consumers know that this item is free for taking
		processorNotifyCondition.notify_all();
	}

}

#endif // XA_BLOCKING_WAIT_STRATEGY_HPP
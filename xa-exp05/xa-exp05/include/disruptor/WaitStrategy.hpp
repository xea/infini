#ifndef XA_WAIT_STRATEGY_HPP
#define XA_WAIT_STRATEGY_HPP

#include <cstdint>
#include <memory>
#include "Sequence.hpp"
#include "SequenceBarrier.hpp"

namespace Disruptor {
	// A WaitStrategy implementation will define how a consumer (ie. an EventProcessor) has to behave when producers can't
	// generate entries quick enough. Typical implementations will be either locking (which is somewhat odd in a lockless
	// environment but easy to implement) or running a spin lock (at the cost of higher cpu usage).
	class WaitStrategy {
	public:
		// Fires a signal at waiting consumers telling them that the producer has made progress, emitting new elements to read
		virtual void signalAllWhenBlocking() = 0;
		/**
		* Waits until the given sequence has an entry to read.
		* \param sequence to be waited on
		* \param cursorSequence the main sequence from the ring buffer. wait/notify strategies will need this
		* \param dependentSequence on which to wait (whatever this means)
		* \returns the sequence that is available which may be greater than the requested sequence.
		*/
		virtual int64_t waitFor(int64_t sequence, std::shared_ptr<Sequence> cursorSequence, std::shared_ptr<Sequence> dependentSequence, std::shared_ptr<SequenceBarrier> barrier) = 0;
	};
}

#endif // XA_WAIT_STRATEGY_HPP

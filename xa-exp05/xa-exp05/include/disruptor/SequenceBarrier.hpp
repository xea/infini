#ifndef XA_SEQUENCE_BARRIER_HPP
#define XA_SEQUENCE_BARRIER_HPP

#include <memory>

namespace Disruptor {
	/**
	 * This struct can be thrown as an interrupt indicator internally whenever a shutdown request was
	 * issued to a running Disruptor instance.
	 */
	struct ShutdownAlert {};

	/**
	 * A Sequence Barrier provides coordination between producers and consumers.
	 */
	class SequenceBarrier : public std::enable_shared_from_this<SequenceBarrier> {
	public:
		// Wait for the given sequence to have an available entry to read.
		virtual int64_t waitFor(int64_t sequence) = 0;

		// Trigger an alert on this barrier
		virtual void alert() = 0;

		// Indicate whether this barrier has been alerted
		virtual bool isAlerted() = 0;

		// Check wherher an alert has been raised and throws an exception in case there has been one
		virtual void checkAlert() = 0;
	};
}

#endif // XA_SEQUENCE_BARRIER_HPP

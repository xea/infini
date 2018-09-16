#ifndef XA_SEQUENCE_H
#define XA_SEQUENCE_H

#include <atomic>
#include <cstdint>
#include <memory>

namespace Disruptor {
	// -------------- SEQUENCE

	// Sequences are used to keep track of the progress of individual components (ie. consumers and producers). Each component
	// maintains it's own sequence that indicates how far each component has got in processing entries.
	class Sequence {
	public:
		inline uint64_t get() { return offset; }
		inline bool compareAndSet(uint64_t expected, uint64_t newValue) {
			// TODO make sure this is the right CAS operation for our purposes here
			return offset.compare_exchange_weak(expected, newValue, std::memory_order_release, std::memory_order_relaxed);
		}
	private:
		// Note: having an initial value of 0 means that the first slot in the ring buffer will be skipped but it'll also
		// allow us to have the complete value range of a 64bit integer without having a sign bit unnecessarily
		std::atomic_uint64_t offset{ 0 };
	};


}

#endif // XA_SEQUENCE_H

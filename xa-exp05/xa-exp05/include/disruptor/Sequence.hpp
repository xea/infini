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
        inline int64_t get() { return offset; }
        inline void set(int64_t new_value) { offset.store(new_value); }
		inline bool compareAndSet(int64_t expected, int64_t newValue) {
			// TODO make sure this is the right CAS operation for our purposes here
			return offset.compare_exchange_weak(expected, newValue, std::memory_order_release, std::memory_order_relaxed);
		}
	private:
		std::atomic_int64_t offset{ -1 };
	};


}

#endif // XA_SEQUENCE_H

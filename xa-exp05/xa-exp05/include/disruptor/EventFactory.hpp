#ifndef XA_EVENT_FACTORY_HPP
#define XA_EVENT_FACTORY_HPP

namespace Disruptor {

	// Implementations of EventFactory are used to pre-populate the entries in the RingBuffer. Objects created by EventFactory
	// instances are expected to be uninitialised or initialised with sane default values that can be safely overwritten.
	template <class T>
	class EventFactory {
	public:
		// Creates a new instance of the specified type T that can be used as an empty 'slot' in the ring buffer. It is
		// going to be called once for each entry during construction.
		virtual T newInstance() = 0;
		virtual ~EventFactory() = default;
	};
}

#endif // XA_EVENT_FACTORY_HPP
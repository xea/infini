#ifndef XA_EVENT_HANDLER_HPP
#define XA_EVENT_HANDLER_HPP

#include <cstdint>

namespace Disruptor {
    
    /**
     * Implementations of EventHandler can be used by the disruptor to have entries processed as they become available.
     * Each event handler is excepted to handle a single type of events
     */
    template<class T>
    class EventHandler {
    public:
        /**
         * Processes a single published event.
         * \param event reference to the published event
         * \param sequence the sequence number of the event under processing
         * \param endOfBatch indicates whether the current event is the last one in the batch
         */
        virtual void onEvent(T& event, uint64_t sequence, bool endOfBatch) = 0;
    };
    
}

#endif // XA_EVENT_HANDLER_HPP

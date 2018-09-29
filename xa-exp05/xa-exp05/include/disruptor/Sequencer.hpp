#ifndef XA_SEQUENCER_HPP
#define XA_SEQUENCER_HPP

#include <cstdint>
#include <memory>
#include "Sequence.hpp"
#include "SequenceBarrier.hpp"

namespace Disruptor {

	/**
	* Implementations of Sequencer are responsible for coordinating consumption of entries and producing them.
	*/
	class Sequencer {
	public:
        /**
         * Claim the next entry in the sequence.
         * \return the next available sequence number
         */
		virtual uint64_t next() = 0;
        /**
         * Makes an entry available for consumers.
         * \param sequence the sequence number that is published
         */
		virtual void publish(uint64_t sequence) = 0;
        /**
         * Create a new barrier that can be used by consumers to coordinate reads with writes by publishers.
         * \return a new sequence barrier
         */
		virtual std::shared_ptr<SequenceBarrier> newBarrier() = 0;
        /**
         * Return the highest sequence number that is available for consuming from the ring buffer and the result may
         * range from lowerBound to availableSequence.
         * \param lowerBound  the sequence to start scanning from
         * \param availableSequence the point where scanning should end
         * \return the highest available sequence number
         */
		virtual uint64_t getHighestPublishedSequence(uint64_t lowerBound, uint64_t availableSequence) = 0;
        virtual ~Sequencer() = default;
        
	protected:
		std::shared_ptr<Sequence> cursor{ std::make_shared<Sequence>() };
	};

}

#endif // XA_SEQUENCER_HPP

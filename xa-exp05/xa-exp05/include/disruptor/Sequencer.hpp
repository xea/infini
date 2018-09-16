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
		virtual ~Sequencer() = default;
		virtual uint64_t next() = 0;
		virtual void publish(uint64_t sequence) = 0;
		virtual std::shared_ptr<SequenceBarrier> newBarrier() = 0;
		virtual uint64_t getHighestPublishedSequence(uint64_t lowerBound, uint64_t availableSequence) = 0;
	protected:
		std::shared_ptr<Sequence> cursor{ std::make_shared<Sequence>() };
	};

}

#endif // XA_SEQUENCER_HPP
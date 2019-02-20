#ifndef XA_PROCESSING_SEQUENCE_BARRIER_HPP
#define XA_PROCESSING_SEQUENCE_BARRIER_HPP

#include <cstdint>
#include <memory>
#include "Sequence.hpp"
#include "SequenceBarrier.hpp"
#include "WaitStrategy.hpp"

namespace Disruptor {
    
    class ProcessingSequenceBarrier : public SequenceBarrier {
    public:
        ProcessingSequenceBarrier(std::shared_ptr<Sequencer> sequencer, std::shared_ptr<WaitStrategy> waitStrategy, std::shared_ptr<Sequence> cursor /* sequencesToTrack */) : sequencer(sequencer), waitStrategy(waitStrategy), cursor(cursor) {
            dependentSequence = cursor;
        };
        int64_t waitFor(int64_t sequence) override;
        void alert() override;
        bool isAlerted() override;
        void checkAlert() override;
    private:
        std::shared_ptr<Sequencer> sequencer;
        std::shared_ptr<WaitStrategy> waitStrategy;
        std::shared_ptr<Sequence> cursor;
        std::shared_ptr<Sequence> dependentSequence;
        std::atomic_bool alerted{ false };
    };
    
    int64_t ProcessingSequenceBarrier::waitFor(int64_t sequence) {
        checkAlert();
        
        int64_t availableSequence = waitStrategy->waitFor(sequence, cursor, dependentSequence,
                                                          shared_from_this());
        
        if (availableSequence < sequence) {
            return availableSequence;
        }
        
        return sequencer->getHighestPublishedSequence(sequence, availableSequence);
    }
    
    void ProcessingSequenceBarrier::alert() {
        alerted = true;
        waitStrategy->signalAllWhenBlocking();
    }
    
    bool ProcessingSequenceBarrier::isAlerted() {
        return alerted;
    }
    
    void ProcessingSequenceBarrier::checkAlert() {
        if (alerted) {
            throw ShutdownAlert{};
        }
    }
}

#endif // XA_PROCESSING_SEQUENCE_BARRIER_HPP

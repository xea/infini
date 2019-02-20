#ifndef XA_MULTIPRODUCER_SEQUENCER_HPP
#define XA_MULTIPRODUCER_SEQUENCER_HPP

#include <cstdint>
#include <memory>
#include <valarray>
#include "Sequencer.hpp"
#include "WaitStrategy.hpp"
#include "SequenceBarrier.hpp"
#include "ProcessingSequenceBarrier.hpp"

namespace Disruptor {
    class MultiProducerSequencer : public Sequencer, public std::enable_shared_from_this<Sequencer> {
    public:
        MultiProducerSequencer(uint32_t bufferSize, std::unique_ptr<WaitStrategy> waitStrategy) :
        waitStrategy(std::move(waitStrategy)),
        gatingSequenceCache(std::make_unique<Sequence>()),
        indexMask(bufferSize - 1),
        indexShift((uint32_t) log2(bufferSize)), // IETF754
        availableBuffer(std::valarray<uint8_t>(bufferSize)) {
            for (uint32_t i = 0; i < bufferSize; i++) {
                availableBuffer[i] = -1;
            }
        };
        int64_t next() override;
        void publish(int64_t sequence) override;
        std::shared_ptr<SequenceBarrier> newBarrier() override;
        int64_t getHighestPublishedSequence(int64_t lowerBound, int64_t availableSequence) override;
    private:
        bool isAvailable(int64_t sequence);
        void setAvailable(int64_t sequence);
        std::shared_ptr<WaitStrategy> waitStrategy;
        std::unique_ptr<Sequence> gatingSequenceCache;
        // Used to ensure that sequence numbers bigger than the number of elements get truncated correctly and thus
        // avoid underflows and overflows
        int64_t indexMask;
        // Counts the number of bits in the indexMask. It is used to prevent ringbuffers overwrite unread entries
        int64_t indexShift;
        // Maintains an availability state of the given ring buffer's entries
        std::valarray<uint8_t> availableBuffer;
    };
    
    int64_t MultiProducerSequencer::next() {
        int64_t next;
        int64_t current;
        
        do {
            current = cursor->get();
            next = current + 1;
            
            // calculate wrap points
            int64_t wrapPoint = next - availableBuffer.size(); //bufferSize;
            int64_t cachedGatingSequence = gatingSequenceCache->get();

            if (wrapPoint > cachedGatingSequence || cachedGatingSequence > current) {
                int64_t gatingSequence = current;
                
                // TODO extract this
                for (auto &seq : gatingSequences) {
                    int64_t cseq = seq->get();
                    
                    if (cseq < gatingSequence) {
                        gatingSequence = cseq;
                    }
                }
                
                if (wrapPoint > gatingSequence) {
                    this_thread::sleep_for(10ms);
                    continue;
                }
                
                gatingSequenceCache->set(gatingSequence);
            } else if (cursor->compareAndSet(current, next)) {
                break;
            }
        } while (true);
        
        return next;
    }
    
    void MultiProducerSequencer::publish(int64_t sequence) {
        setAvailable(sequence);
        waitStrategy->signalAllWhenBlocking();
    }
    
    std::shared_ptr<SequenceBarrier> MultiProducerSequencer::newBarrier() {
        auto thisref = shared_from_this();
        return std::make_shared<ProcessingSequenceBarrier>(thisref, waitStrategy, cursor /*, sequencesToTrack */);
    }
    
    int64_t MultiProducerSequencer::getHighestPublishedSequence(int64_t lowerBound, int64_t availableSequence) {
        for (int64_t sequence = lowerBound; sequence <= availableSequence; sequence++) {
            if (!isAvailable(sequence)) {
                return sequence - 1;
            }
        }
        
        return availableSequence;
    }
    
    void MultiProducerSequencer::setAvailable(int64_t sequence) {
        int64_t index = sequence & indexMask;
        int64_t flag = sequence >> indexShift;
        
        availableBuffer[(size_t)index] = (uint8_t) flag;
    }
    
    bool MultiProducerSequencer::isAvailable(int64_t sequence) {
        int64_t index = sequence & indexMask;
        int64_t flag = sequence >> indexShift;
        uint8_t value = availableBuffer[(size_t) index];
        
        return value == flag;
    }
    
}

#endif // XA_MULTIPRODUCER_SEQUENCER_HPP

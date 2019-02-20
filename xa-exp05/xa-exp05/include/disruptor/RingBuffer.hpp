#ifndef XA_RING_BUFFER_HPP
#define XA_RING_BUFFER_HPP

namespace Disruptor {

	template<class T>
	class RingBuffer : public DataProvider<T> {
	public:
		RingBuffer(std::unique_ptr<EventFactory<T>> factory, const uint32_t bufferSize) : 
			sequencer(std::make_shared<MultiProducerSequencer>(bufferSize, std::make_unique<BlockingWaitStrategy>())),
			factory(std::move(factory)),
			entries(std::valarray<T>(bufferSize)) {

			indexMask = bufferSize - 1;

			for (uint32_t i = 0; i < bufferSize; i++) {
				entries[i] = this->factory->newInstance();
			}
		};
		void publishEvent();
		void publishEvent(int64_t sequence);
		void addGatingSequences(std::vector<std::shared_ptr<Sequence>> sequences);
		static std::unique_ptr<RingBuffer> createMultiProducer(std::unique_ptr<EventFactory<T>> factory, int bufferSize);
		T elementAt(long sequence);
		std::shared_ptr<SequenceBarrier> newBarrier();
		T& get(int64_t sequence) override;
		int64_t next();
		T& operator[](int64_t sequence);
	private:
		std::shared_ptr<Sequencer> sequencer;
		std::unique_ptr<EventFactory<T>> factory;
		std::valarray<T> entries;
		uint32_t indexMask;
	};

	template<class T> void RingBuffer<T>::publishEvent() {
		const long sequence = sequencer->next();
		// TODO do translation
		sequencer->publish(sequence);
	}

	template<class T> void RingBuffer<T>::publishEvent(int64_t sequence) {
		sequencer->publish(sequence);
	}

	template<class T> void RingBuffer<T>::addGatingSequences(std::vector<std::shared_ptr<Sequence>> sequences) {
		sequencer->addGatingSequences(move(sequences));
	}

	template<class T>
	std::unique_ptr<RingBuffer<T>> RingBuffer<T>::createMultiProducer(std::unique_ptr<EventFactory<T>> factory, int bufferSize) {
		return std::make_unique<RingBuffer>(std::move(factory), bufferSize);
	}

	template<class T>
	T RingBuffer<T>::elementAt(long sequence) {
		return entries[sequence & indexMask];
	}

	template<class T>
	std::shared_ptr<SequenceBarrier> RingBuffer<T>::newBarrier() {
		return sequencer->newBarrier();
	}

	template<class T>
	T& RingBuffer<T>::get(int64_t sequence) {
		return entries[sequence & indexMask];
	}

	template<class T>
	int64_t RingBuffer<T>::next() {
		return sequencer->next();
	}

	template<class T>
	T& RingBuffer<T>::operator[](int64_t sequence) {
		return entries[sequence & indexMask];
	}
}

#endif // XA_RING_BUFFER_HPP

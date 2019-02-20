#ifndef XA_RING_BUFFER_HPP
#define XA_RING_BUFFER_HPP

namespace Disruptor {

	template<class T, size_t N = DEFAULT_SEQUENCER_SIZE>
	class RingBuffer : public DataProvider<T> {
	public:
		RingBuffer(std::unique_ptr<EventFactory<T>> factory, const uint32_t bufferSize) : 
			sequencer(std::make_shared<MultiProducerSequencer<N>>(bufferSize, std::make_unique<BlockingWaitStrategy>())), 
			factory(std::move(factory)),
			entries(std::array<T, N>()) {

			indexMask = N - 1;

			for (uint32_t i = 0; i < N; i++) {
				entries[i] = this->factory->newInstance();
			}
		};
		void publishEvent();
		void publishEvent(int64_t sequence);
		static std::unique_ptr<RingBuffer> createMultiProducer(std::unique_ptr<EventFactory<T>> factory, int bufferSize);
		T elementAt(long sequence);
		std::shared_ptr<SequenceBarrier> newBarrier();
		T& get(int64_t sequence) override;
		int64_t next();
		T& operator[](int64_t sequence);
	private:
		std::shared_ptr<Sequencer> sequencer;
		std::unique_ptr<EventFactory<T>> factory;
		std::array<T, N> entries;
		uint32_t indexMask;
	};

	template<class T, size_t N> void RingBuffer<T, N>::publishEvent() {
		const long sequence = sequencer->next();
		// TODO do translation
		sequencer->publish(sequence);
	}

	template<class T, size_t N> void RingBuffer<T, N>::publishEvent(int64_t sequence) {
		sequencer->publish(sequence);
	}

	template<class T, size_t N>
	std::unique_ptr<RingBuffer<T, N>> RingBuffer<T, N>::createMultiProducer(std::unique_ptr<EventFactory<T>> factory, int bufferSize) {
		return std::make_unique<RingBuffer>(std::move(factory), bufferSize);
	}

	template<class T, size_t N>
	T RingBuffer<T, N>::elementAt(long sequence) {
		return entries[sequence & indexMask];
	}

	template<class T, size_t N>
	std::shared_ptr<SequenceBarrier> RingBuffer<T, N>::newBarrier() {
		return sequencer->newBarrier();
	}

	template<class T, size_t N>
	T& RingBuffer<T, N>::get(int64_t sequence) {
		return entries[sequence & indexMask];
	}

	template<class T, size_t N>
	int64_t RingBuffer<T, N>::next() {
		return sequencer->next();
	}

	template<class T, size_t N>
	T& RingBuffer<T, N>::operator[](int64_t sequence) {
		return entries[sequence & indexMask];
	}
}

#endif // XA_RING_BUFFER_HPP

#ifndef XA_BATCH_EVENT_PROCESSOR
#define XA_BATCH_EVENT_PROCESSOR

namespace Disruptor {

	template <class T>
	class BatchEventProcessor : public EventProcessor {
	public:
		BatchEventProcessor(std::shared_ptr<DataProvider<T>> dataProvider, std::shared_ptr<SequenceBarrier> barrier, std::shared_ptr<EventHandler<T>> eventHandler) :
			dataProvider(dataProvider),
			sequenceBarrier(barrier),
			eventHandler(eventHandler),
			sequence(std::make_shared<Sequence>()) {};
		void run() override;
		std::shared_ptr<Sequence> getSequence() override;
	private:
		void processEvents();

		std::shared_ptr<DataProvider<T>> dataProvider;
		std::shared_ptr<SequenceBarrier> sequenceBarrier;
		std::shared_ptr<EventHandler<T>> eventHandler;
		std::shared_ptr<Sequence> sequence;
	};

	template <class T>
	void BatchEventProcessor<T>::run() {
		// TODO checking stuff
		processEvents();
	}

	template <class T>
	void BatchEventProcessor<T>::processEvents() {
		uint64_t nextSequence = sequence->get() + 1;

		while (true) {
			uint64_t availableSequence = sequenceBarrier->waitFor(nextSequence);

			// TODO stuff

			while (nextSequence <= availableSequence) {
				auto event = dataProvider->get(nextSequence);
				eventHandler->onEvent(event, nextSequence, nextSequence == availableSequence);
				nextSequence++;
			}
		}
	}

	template<class T>
	std::shared_ptr<Sequence> BatchEventProcessor<T>::getSequence() {
		return sequence;
	}
}

#endif // XA_BATCH_EVENT_PROCESOR
#ifndef XA_DISRUPTOR_CONSUMER_REPOSITORY_HPP
#define XA_DISRUPTOR_CONSUMER_REPOSITORY_HPP

namespace Disruptor {

	template<class T>
	class ConsumerRepository {
	public:
		void add(std::shared_ptr<EventProcessor> eventProcessor, std::shared_ptr<EventHandler<T>> handler, std::shared_ptr<SequenceBarrier> barrier);
		std::vector<std::shared_ptr<ConsumerInfo>> items();
	private:
		std::unordered_map<std::shared_ptr<EventHandler<T>>, EventProcessorInfo<T>> consumerInfosByEventHandler;
		std::vector<std::shared_ptr<ConsumerInfo>> consumerInfos;
	};

	template<class T>
	void ConsumerRepository<T>::add(std::shared_ptr<EventProcessor> eventProcessor, std::shared_ptr<EventHandler<T>> handler, std::shared_ptr<SequenceBarrier> barrier) {
		auto consumerInfo = std::make_shared<EventProcessorInfo<T>>(eventProcessor, handler, barrier);
		// TODO maps
		consumerInfos.push_back(consumerInfo);
	}

	template<class T>
	std::vector<std::shared_ptr<ConsumerInfo>> ConsumerRepository<T>::items() {
		return consumerInfos;
	}

}

#endif // XA_DISRUPTOR_CONSUMER_REPOSITORY_HPP
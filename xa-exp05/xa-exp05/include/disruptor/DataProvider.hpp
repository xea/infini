#ifndef XA_DATA_PROVIDER_HPP
#define XA_DATA_PROVIDER_HPP

namespace Disruptor {

	template <class T>
	class DataProvider {
	public:
		//virtual std::shared_ptr<T> get(uint64_t sequence) = 0;
		virtual T& get(uint64_t sequence) = 0;
	};

}

#endif // XA_DATA_PROVIDER_HPP
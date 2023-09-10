#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_FUTURE_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_FUTURE_HPP

#include <future>
#include "../traits.hpp"

namespace cpp_as_is::ext {
	template <class T> struct as_conversion_traits<std::future<T>, T>
	{
		using arg_type = std::future<T>;
		using return_type = T;

		static inline T convert(arg_type future) noexcept { return future.get(); }

		static inline const T &convert(const arg_type &future) noexcept { return future.get(); }

		static inline T &&convert(arg_type &&future) noexcept { return future.get(); }
	};

	template <class T> struct as_conversion_traits<std::shared_future<T>, T>
	{
		using arg_type = std::shared_future<T>;
		using return_type = T;

		static inline T convert(arg_type future) noexcept { return future.get(); }

		static inline const T &convert(const arg_type &future) noexcept { return future.get(); }

		static inline T &&convert(arg_type &&future) noexcept { return future.get(); }
	};
}// namespace cpp_as_is::ext

#if defined __has_include
#if __has_include(<experimental/future>)
#include <experimental/future>

namespace cpp_as_is::ext {
	template <class T> struct as_conversion_traits<std::experimental::future<T>, T>
	{
		using arg_type = std::experimental::future<T>;
		using return_type = T;

		static inline T convert(arg_type future) noexcept { return future.get(); }

		static inline const T &convert(const arg_type &future) noexcept { return future.get(); }

		static inline T &&convert(arg_type &&future) noexcept { return future.get(); }
	};

	template <class T> struct as_conversion_traits<std::experimental::shared_future<T>, T>
	{
		using arg_type = std::experimental::shared_future<T>;
		using return_type = T;

		static inline T convert(arg_type future) noexcept { return future.get(); }

		static inline const T &convert(const arg_type &future) noexcept { return future.get(); }

		static inline T &&convert(arg_type &&future) noexcept { return future.get(); }
	};
}// namespace cpp_as_is::ext
#endif
#endif

#if defined __has_include
#if __has_include(<boost/fiber/future/future.hpp>)
#include <boost/fiber/future/future.hpp>

template <class T> struct as_conversion_traits<boost::fibers::future<T>, T>
{
	using arg_type = boost::fibers::future<T>;
	using return_type = T;

	static inline T convert(arg_type future) noexcept { return future.get(); }

	static inline const T &convert(const arg_type &future) noexcept { return future.get(); }

	static inline T &&convert(arg_type &&future) noexcept { return future.get(); }
};
#endif
#endif


#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_FUTURE_HPP

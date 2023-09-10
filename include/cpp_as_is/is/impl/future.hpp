#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_FUTURE_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_FUTURE_HPP

#include <chrono>
#include <future>
#include <type_traits>
#include "../traits.hpp"

namespace cpp_as_is::ext {
	template <class T> struct is_conversion_traits<std::future<T>, T>
	{
		using arg_type = std::future<T>;

		static inline bool matches(const arg_type &future) noexcept
		{
			return future.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
		}
	};

	template <class T> struct is_conversion_traits<std::shared_future<T>, T>
	{
		using arg_type = std::future<T>;

		static inline bool matches(const arg_type &future) noexcept
		{
			return future.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
		}
	};
}// namespace cpp_as_is::ext

#if __has_include(<experimental/future>)
#include <experimental/future>
namespace cpp_as_is::ext {
	template <class T> struct is_conversion_traits<std::experimental::future<T>, T>
	{
		using arg_type = std::experimental::future<T>;

		static inline bool matches(const arg_type &future) noexcept { return future.is_ready(); }
	};

	template <class T> struct is_conversion_traits<std::experimental::shared_future<T>, T>
	{
		using arg_type = std::experimental::shared_future<T>;

		static inline bool matches(const arg_type &future) noexcept { return future.is_ready(); }
	};
}// namespace cpp_as_is::ext
#endif// __has_include(<experimental/future>)

#if __has_include(<boost/fiber/future/future.hpp>)
#include <boost/fiber/future/future.hpp>
namespace cpp_as_is::ext {
	template <class T> struct is_conversion_traits<boost::fibers::future<T>, T>
	{
		using arg_type = boost::fibers::future<T>;

		static inline bool matches(const arg_type &future) noexcept
		{
			return future.wait_for(std::chrono::seconds(0)) == boost::fibers::future_status::ready;
		}
	};
}// namespace cpp_as_is::ext
#endif// __has_include(<boost/fiber/future/future.hpp>)

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_FUTURE_HPP

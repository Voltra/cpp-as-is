#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_OPTIONAL_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_OPTIONAL_HPP

#include <optional>
#include <type_traits>
#include "../traits.hpp"

namespace cpp_as_is::ext {
	template <class T> struct is_conversion_traits<std::optional<T>, T>
	{
		using arg_type = std::optional<T>;

		constexpr static inline bool matches(const arg_type &opt) noexcept { return opt.has_value(); }
	};


	template <class T> struct is_conversion_traits<std::optional<T>, std::nullopt_t>
	{
		using arg_type = std::optional<T>;

		constexpr static inline bool matches(const arg_type &opt) noexcept { return !opt.has_value(); }
	};
}// namespace cpp_as_is::ext

#if defined __has_include
#if __has_include(<boost/optional.hpp>)
#include <boost/optional.hpp>

namespace cpp_as_is::ext {
	template <class T> struct is_conversion_traits<boost::optional<T>, T>
	{
		using arg_type = boost::optional<T>;

		constexpr static inline bool matches(const arg_type &opt) noexcept { return opt.has_value(); }
	};


	template <class T> struct is_conversion_traits<boost::optional<T>, boost::none_t>
	{
		using arg_type = boost::optional<T>;

		constexpr static inline bool matches(const arg_type &opt) noexcept { return !opt.has_value(); }
	};
}// namespace cpp_as_is::ext
#endif
#endif

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_OPTIONAL_HPP

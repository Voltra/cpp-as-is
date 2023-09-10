#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_OPTIONAL_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_OPTIONAL_HPP

#include <optional>
#include "../traits.hpp"

namespace cpp_as_is::ext {
	template <class T> struct as_conversion_traits<std::optional<T>, T>
	{
		using arg_type = std::optional<T>;
		using return_type = T;

		constexpr static inline return_type &convert(arg_type &opt) { return opt.value(); }

		constexpr static inline const return_type &convert(const arg_type &opt) { return opt.value(); }

		constexpr static inline return_type &&convert(arg_type &&opt) { return opt.value(); }
	};
}// namespace cpp_as_is::ext

#if __has_include(<boost/optional.hpp>)
#include <boost/optional.hpp>

namespace cpp_as_is::ext {
	template <class T> struct as_conversion_traits<boost::optional<T>, T>
	{
		using arg_type = boost::optional<T>;
		using return_type = T;

		constexpr static inline return_type &convert(arg_type &opt) { return opt.value(); }

		constexpr static inline const return_type &convert(const arg_type &opt) { return opt.value(); }

		constexpr static inline return_type &&convert(arg_type &&opt) { return opt.value(); }
	};
}// namespace cpp_as_is::ext
#endif// __has_include(<boost/optional.hpp>)

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_OPTIONAL_HPP

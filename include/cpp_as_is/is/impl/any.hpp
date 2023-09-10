#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_ANY_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_ANY_HPP

#include <any>
#include "../traits.hpp"

namespace cpp_as_is::ext {
	template <class T> struct is_conversion_traits<std::any, T>
	{
		using arg_type = std::any;

		static inline bool matches(const arg_type &variant) noexcept { return variant.type() == typeid(T); }
	};
}// namespace cpp_as_is::ext

#if __has_include(<boost/any.hpp>)
#include <boost/any.hpp>

namespace cpp_as_is::ext {
	template <class T> struct is_conversion_traits<boost::any, T>
	{
		using arg_type = boost::any;

		static inline bool matches(const arg_type &variant) noexcept { return variant.type() == typeid(T); }
	};
}// namespace cpp_as_is::ext
#endif// __has_include(<boost/any.hpp>)

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_ANY_HPP

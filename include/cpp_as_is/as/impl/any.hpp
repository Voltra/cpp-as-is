#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_ANY_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_ANY_HPP

#include <any>
#include "../traits.hpp"

namespace cpp_as_is::ext {
	template <class T> struct as_conversion_traits<std::any, T>
	{
		using arg_type = std::any;

		static T convert(const arg_type &variant) noexcept { return std::any_cast<T>(variant); }
	};

	template <class T> struct as_conversion_traits<std::any *, T>
	{
		using arg_type = std::any *;
		using const_arg_type = const std::any *;

		static T &convert(arg_type variant) noexcept { return *any_cast<T>(variant); }

		static const T &convert(const_arg_type variant) noexcept { return *any_cast<T>(variant); }
	};
}// namespace cpp_as_is::ext

#if defined __has_include
#if __has_include(<boost/any.hpp>)
#include <boost/any.hpp>

namespace cpp_as_is::ext {
	template <class T> struct as_conversion_traits<boost::any, T>
	{
		using arg_type = boost::any;

		static T convert(const arg_type &variant) noexcept { return any_cast<T>(variant); }
	};

	template <class T> struct as_conversion_traits<boost::any *, T>
	{
		using arg_type = boost::any *;
		using const_arg_type = const boost::any *;

		static T &convert(arg_type variant) noexcept { return *any_cast<T>(variant); }

		static const T &convert(const_arg_type variant) noexcept { return *any_cast<T>(variant); }
	};
}// namespace cpp_as_is::ext
#endif
#endif

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_ANY_HPP

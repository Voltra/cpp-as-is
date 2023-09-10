#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_ANY_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_ANY_HPP

#include <any>
#include "../traits.hpp"

namespace cpp_as_is::ext {
	template <class T> struct as_conversion_traits<std::any, T>
	{
		using arg_type = std::any;
		using return_type = T;

		static return_type convert(const arg_type &variant) noexcept { return std::any_cast<T>(variant); }
	};

	template <class T> struct as_conversion_traits<std::any *, T>
	{
		using arg_type = std::any *;
		using const_arg_type = const std::any *;
		using return_type = T;

		static return_type &convert(arg_type variant) noexcept { return *any_cast<T>(variant); }

		static const return_type &convert(const_arg_type variant) noexcept { return *any_cast<T>(variant); }
	};
}// namespace cpp_as_is::ext

#if defined __has_include
#if __has_include(<boost/any.hpp>)
#include <boost/any.hpp>

namespace cpp_as_is::ext {
	template <class T> struct as_conversion_traits<boost::any, T>
	{
		using arg_type = boost::any;
		using return_type = T;

		static return_type convert(const arg_type &variant) noexcept { return any_cast<T>(variant); }
	};

	template <class T> struct as_conversion_traits<boost::any *, T>
	{
		using arg_type = boost::any *;
		using const_arg_type = const boost::any *;
		using return_type = T;

		static T &convert(arg_type variant) noexcept { return *any_cast<T>(variant); }

		static const return_type &convert(const_arg_type variant) noexcept { return *any_cast<T>(variant); }
	};
}// namespace cpp_as_is::ext
#endif
#endif

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_ANY_HPP

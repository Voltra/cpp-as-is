#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_TRAITS_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_TRAITS_HPP

namespace cpp_as_is::ext {
	/**
	 * Traits for defining a safe conversion operation
	 * @tparam From The type to convert from (also known as the inspected type)
	 * @tparam To The type to convert to
	 */
	template <class From, class To> struct as_conversion_traits;
}// namespace cpp_as_is::ext

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_TRAITS_HPP

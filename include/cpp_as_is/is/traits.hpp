#ifndef CPP_AS_IS_TRAITS_HPP
#define CPP_AS_IS_TRAITS_HPP

namespace cpp_as_is::ext {
/**
 * Traits for defining whether a type can be converted to another
 * @tparam From The type to convert from (also known as the inspected type)
 * @tparam To The type we would want to convert to
 */
template<class From, class To> struct is_conversion_traits;
}// namespace cpp_as_is

#endif// CPP_AS_IS_TRAITS_HPP

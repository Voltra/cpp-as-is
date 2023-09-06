#ifndef CPP_AS_IS_ANY_HPP
#define CPP_AS_IS_ANY_HPP

#include "../traits.hpp"
#include <any>

namespace cpp_as_is {
template<> struct is_traits<std::any>
{
  using object_type = std::any;

  template<class T> static inline bool matches(const object_type &variant) noexcept
  {
    return variant.type() == typeid(T);
  }
};
}// namespace cpp_as_is

#if defined __has_include
#if __has_include(<boost/any.hpp>)
#include <boost/any.hpp>

namespace cpp_as_is {
template<> struct is_traits<boost::any>
{
  using object_type = boost::any;

  template<class T> static inline bool matches(const object_type &variant) noexcept
  {
    return variant.type() == typeid(T);
  }
};
}// namespace cpp_as_is
#endif
#endif

#endif// CPP_AS_IS_ANY_HPP

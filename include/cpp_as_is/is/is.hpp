#ifndef CPP_AS_IS_IS_HPP
#define CPP_AS_IS_IS_HPP

#include "./impl/impl.hpp"
#include "./traits.hpp"

namespace cpp_as_is {
template<class T> bool is(auto &&value)
{
  return cpp_as_is::is_traits<decltype(value)>::template matches_type<T>(value);
}
}// namespace cpp_as_is

#endif// CPP_AS_IS_IS_HPP

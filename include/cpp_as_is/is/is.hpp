#ifndef CPP_AS_IS_IS_HPP
#define CPP_AS_IS_IS_HPP

#include "./impl/impl.hpp"
#include "./traits.hpp"
#include <type_traits>

namespace cpp_as_is {
template<class T> inline bool is(const auto &value)
{
  return cpp_as_is::is_traits<std::remove_cv_t<std::remove_reference_t<decltype(value)>>>::template matches_type<T>(
    value);
}
}// namespace cpp_as_is

#endif// CPP_AS_IS_IS_HPP

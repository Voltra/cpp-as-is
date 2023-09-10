#ifndef CPP_AS_IS_IS_HPP
#define CPP_AS_IS_IS_HPP

#include "./concepts.hpp"
#include "./impl/impl.hpp"
#include "./traits.hpp"
#include <type_traits>

namespace cpp_as_is {
template<class T> using remove_cvref_t = std::remove_cv_t<std::remove_reference_t<T>>;

template<class T> inline bool is(CPP_AS_IS_IS_CONCEPT auto const &value)
{
  return cpp_as_is::ext::is_conversion_traits<remove_cvref_t<decltype(value)>, T>::matches(value);
}
}// namespace cpp_as_is

#endif// CPP_AS_IS_IS_HPP

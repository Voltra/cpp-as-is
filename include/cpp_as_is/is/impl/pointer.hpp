#ifndef CPP_AS_IS_POINTER_HPP
#define CPP_AS_IS_POINTER_HPP

#include "../traits.hpp"
#include <type_traits>

namespace cpp_as_is::ext {
template<class T> struct is_conversion_traits<T *, T>
{
  using arg_type = T *;
  using const_arg_type = const T *;

  constexpr static inline bool matches(const_arg_type ptr) noexcept { return ptr != nullptr; }
};


template<class T> struct is_conversion_traits<T *, std::nullptr_t>
{
  using arg_type = T *;
  using const_arg_type = const T *;

  constexpr static inline bool matches(const_arg_type ptr) noexcept { return ptr == nullptr; }
};
}// namespace cpp_as_is::ext

#endif// CPP_AS_IS_POINTER_HPP

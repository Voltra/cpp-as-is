#ifndef CPP_AS_IS_POINTER_HPP
#define CPP_AS_IS_POINTER_HPP

#include "../traits.hpp"
#include <type_traits>

namespace cpp_as_is {
template<class T> struct is_traits<T *>
{
  using object_type = T *;
  using const_object_type = const T *;

  template<class> constexpr static inline bool matches(const_object_type ptr) noexcept;

  template<> constexpr static inline bool matches<T>(const_object_type ptr) noexcept { return ptr != nullptr; }

  template<> constexpr static inline bool matches<std::nullptr_t>(const_object_type ptr) noexcept
  {
    return ptr == nullptr;
  }
};
}// namespace cpp_as_is

#endif// CPP_AS_IS_POINTER_HPP

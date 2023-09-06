#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_SHARED_PTR_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_SHARED_PTR_HPP

#include "../traits.hpp"
#include <memory>

namespace cpp_as_is {
template<class T> struct is_traits<std::shared_ptr<T>>
{
  using object_type = std::shared_ptr<T>;

  template<class> constexpr static inline bool matches(const object_type &ptr) noexcept;

  template<> constexpr static inline bool matches<T>(const object_type &ptr) noexcept { return bool{ ptr }; }

  template<> constexpr static inline bool matches<std::nullptr_t>(const object_type &ptr) noexcept
  {
    return !(bool{ ptr });
  }
};
}// namespace cpp_as_is

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_SHARED_PTR_HPP

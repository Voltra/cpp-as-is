#ifndef CPP_AS_IS_OPTIONAL_HPP
#define CPP_AS_IS_OPTIONAL_HPP

#include "../traits.hpp"
#include <optional>
#include <type_traits>

namespace cpp_as_is {
template<class T> struct is_traits<std::optional<T>>
{
  template<class U> constexpr static inline bool matches_type(const std::optional<T> &opt) noexcept
  {
    return std::is_same_v<T, U> && opt.has_value();
  }

  template<> constexpr static inline bool matches_type<std::nullopt_t>(const std::optional<T> &opt) noexcept
  {
    return !opt.has_value();
  }
};
}// namespace cpp_as_is

#endif// CPP_AS_IS_OPTIONAL_HPP

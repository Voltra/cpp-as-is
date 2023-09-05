#ifndef CPP_AS_IS_VARIANT_HPP
#define CPP_AS_IS_VARIANT_HPP

#include "../traits.hpp"
#include <variant>

namespace cpp_as_is {
template<class... Variants> struct is_traits<std::variant<Variants...>>
{
  template<class T> constexpr static inline bool matches_type(const std::variant<Variants...> &variant)
  {
    return std::holds_alternative<T>(variant);
  }
};
}// namespace cpp_as_is

#endif// CPP_AS_IS_VARIANT_HPP

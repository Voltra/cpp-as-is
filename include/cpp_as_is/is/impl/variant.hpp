#ifndef CPP_AS_IS_VARIANT_HPP
#define CPP_AS_IS_VARIANT_HPP

#include "../traits.hpp"
#include <variant>

namespace cpp_as_is {
template<class... Variants> struct is_traits<std::variant<Variants...>>
{
  using object_type = std::variant<Variants...>;

  template<class T> constexpr static inline bool matches(const object_type &variant) noexcept
  {
    return holds_alternative<T>(variant);
  }
};
}// namespace cpp_as_is

#if defined __has_include
#if __has_include(<boost/variant.hpp>)
#include <boost/variant.hpp>
namespace cpp_as_is {
template<class... Variants> struct is_traits<boost::variant<Variants...>>
{
  using object_type = boost::variant<Variants...>;

  template<class T> static inline bool matches(const object_type &variant) noexcept
  {
    return variant.type() == typeid(Obj);
  }
};
}// namespace cpp_as_is
#endif
#endif

#if defined __has_include
#if __has_include(<boost/variant2/variant.hpp>)
#include <boost/variant2/variant.hpp>
namespace cpp_as_is {
template<class... Variants> struct is_traits<boost::variant2::variant<Variants...>>
{
  using object_type = boost::variant2::variant<Variants...>;

  template<class T> static inline bool matches(const object_type &variant) noexcept
  {
    return holds_alternative<T>(variant);
  }
};
}// namespace cpp_as_is
#endif
#endif

#endif// CPP_AS_IS_VARIANT_HPP

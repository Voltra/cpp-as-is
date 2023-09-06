#ifndef CPP_AS_IS_OPTIONAL_HPP
#define CPP_AS_IS_OPTIONAL_HPP

#include "../traits.hpp"
#include <optional>
#include <type_traits>

namespace cpp_as_is {
template<class T> struct is_traits<std::optional<T>>
{
  using object_type = std::optional<T>;

  template <class>
  constexpr static inline bool matches(const object_type& opt) noexcept;

  template<> constexpr static inline bool matches<T>(const object_type &opt) noexcept
  {
    return opt.has_value();
  }

  template<> constexpr static inline bool matches<std::nullopt_t>(const object_type &opt) noexcept
  {
    return !opt.has_value();
  }
};
}// namespace cpp_as_is

#if defined __has_include
#if __has_include(<boost/optional.hpp>)
namespace cpp_as_is {
template<class T> struct is_traits<boost::optional<T>>
{
  using object_type = boost::optional<T>;

  template <class>
  constexpr static inline bool matches(const object_type& opt) noexcept;


  template<> constexpr static inline bool matches<T>(const object_type &opt) noexcept
  {
    return opt.has_value();
  }

  template<> constexpr static inline bool matches<boost::none_t>(const object_type &opt) noexcept
  {
    return !opt.has_value();
  }
};
}// namespace cpp_as_is
#endif
#endif

#endif// CPP_AS_IS_OPTIONAL_HPP

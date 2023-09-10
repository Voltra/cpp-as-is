#ifndef CPP_AS_IS_CONCEPTS_HPP
#define CPP_AS_IS_CONCEPTS_HPP

#ifdef __cpp_concepts

#include "./traits.hpp"
#include <concepts>
#include <type_traits>

namespace cpp_as_is {
template<class From, class To>
concept InspectableWithIs = requires(From obj) {
  typename cpp_as_is::ext::is_conversion_traits<std::remove_cvref_t<From>, To>::arg_type;

  {
    cpp_as_is::ext::is_conversion_traits<std::remove_cvref_t<From>, To>::matches(obj)
  } noexcept -> std::same_as<bool>;
};
}

#define CPP_AS_IS_IS_CONCEPT cpp_as_is::InspectableWithIs<T>

#define CPP_AS_IS_REQUIRES(...) requires __VA_ARGS__

#else

#define CPP_AS_IS_IS_CONCEPT
#define CPP_AS_IS_REQUIRES(...)

#endif

#endif// CPP_AS_IS_CONCEPTS_HPP

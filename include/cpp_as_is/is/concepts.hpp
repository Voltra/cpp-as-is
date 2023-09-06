#ifndef CPP_AS_IS_CONCEPTS_HPP
#define CPP_AS_IS_CONCEPTS_HPP

#ifdef __cpp_concepts

#include "./traits.hpp"
#include <concepts>
#include <type_traits>

namespace cpp_as_is {
template<class Obj>
concept InspectableWithIs = requires(Obj obj) {
  typename cpp_as_is::is_traits<std::remove_cvref_t<Obj>>::object_type;

  //  {
  //    cpp_as_is::is_traits<std::remove_cvref_t<Obj>>::matches
  //  };
};
}

#define CPP_AS_IS_IS_CONCEPT cpp_as_is::InspectableWithIs

#else

#define CPP_AS_IS_IS_CONCEPT

#endif

#endif// CPP_AS_IS_CONCEPTS_HPP

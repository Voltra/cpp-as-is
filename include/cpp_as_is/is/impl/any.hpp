#ifndef CPP_AS_IS_ANY_HPP
#define CPP_AS_IS_ANY_HPP

#include "../traits.hpp"
#include <any>

namespace cpp_as_is {
template<> struct is_traits<std::any>
{
  template<class T> static inline bool matches_type(const std::any &variant) { return variant.type() == typeid(T); }
};
}// namespace cpp_as_is

#endif// CPP_AS_IS_ANY_HPP

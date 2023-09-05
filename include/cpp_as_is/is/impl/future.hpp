#ifndef CPP_AS_IS_FUTURE_HPP
#define CPP_AS_IS_FUTURE_HPP

#include <chrono>
#include <future>
#include <type_traits>
#include "../traits.hpp"

namespace cpp_as_is {
template <class T>
struct is_traits<std::future<T>> {
  template <class U>
  static inline bool matches_type(const std::future<U>& future) {
    return std::is_same_v<T, U> && future.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
  }
};
}

#endif// CPP_AS_IS_FUTURE_HPP

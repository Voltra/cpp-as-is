#ifndef CPP_AS_IS_FUTURE_HPP
#define CPP_AS_IS_FUTURE_HPP

#include "../traits.hpp"
#include <chrono>
#include <future>
#include <type_traits>

namespace cpp_as_is {
template<class T> struct is_traits<std::future<T>>
{
  using object_type = std::future<T>;

  template<class> static inline bool matches_type(const object_type &future) noexcept;

  template<> static inline bool matches_type<T>(const object_type &future) noexcept
  {
    return future.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
  }
};

template<class T> struct is_traits<std::shared_future<T>>
{
  using object_type = std::shared_future<T>;

  template<class> static inline bool matches_type(const object_type &future) noexcept;

  template<> static inline bool matches_type<T>(const object_type &future) noexcept
  {
    return future.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
  }
};
}// namespace cpp_as_is

#if defined __has_include
#if __has_include(<experimental/future>)
#include <experimental/future>
namespace cpp_as_is {
template<class T> struct is_traits<std::experimental::future<T>>
{
  using object_type = std::experimental::future<T>;

  template<class> static inline bool matches_type(const object_type &future) noexcept;

  template<> static inline bool matches_type<T>(const object_type &future) noexcept
  {
    return future.is_ready();
  }
};

template<class T> struct is_traits<std::experimental::shared_future<T>>
{
  using object_type = std::experimental::shared_future<T>;

  template<class> static inline bool matches_type(const object_type &future) noexcept;

  template<> static inline bool matches_type<T>(const object_type &future) noexcept
  {
    return future.is_ready();
  }
};
}// namespace cpp_as_is
#endif
#endif

#if defined __has_include
#if __has_include(<boost/fiber/future/future.hpp>)
#include <boost/fiber/future/future.hpp>
namespace cpp_as_is {
template<class T> struct is_traits<boost::fibers::future<T>>
{
  using object_type = boost::fibers::future<T>;

  template<class> static inline bool matches_type(const object_type &future) noexcept;

  template<> static inline bool matches_type<T>(const object_type &future) noexcept
  {
    return future.wait_for(std::chrono::seconds(0)) == boost::fibers::future_status::ready;
  }
};
}// namespace cpp_as_is
#endif
#endif

#endif// CPP_AS_IS_FUTURE_HPP

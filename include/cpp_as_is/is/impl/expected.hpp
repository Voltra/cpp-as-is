#ifndef CPP_AS_IS_EXPErrCodeTED_HPP
#define CPP_AS_IS_EXPErrCodeTED_HPP

#if defined __has_include
#if __has_include(<expected>)
#include <expected>

template<class T, class E> struct is_traits<std::expected<T, E>>
{
  using object_type = std::expected<T, E>;

  template <class>
  constexpr static inline bool matches(const object_type &expected) noexcept;

  template<> constexpr static inline bool matches<T>(const object_type &expected) noexcept
  {
    return expected.has_value();
  }

  template <>
  constexpr static inline bool matches<std::unexpected<E>>(const object_type& expected) noexcept {
    return !expected.has_value();
  }
};
#endif
#endif

#if defined __has_include
#if __has_include(<boost/outcome.hpp>)
#include <boost/outcome.hpp>

template<class T, class ErrCode, class ExcPtr, class NoValuePolicy> struct is_traits<BOOST_OUTCOME_V2_NAMESPACE::outcome<T, ErrCode, ExcPtr, NoValuePolicy>>
{
  using object_type = BOOST_OUTCOME_V2_NAMESPACE::outcome<T, ErrCode, ExcPtr, NoValuePolicy>;

  template <class>
  constexpr static inline bool matches(const object_type &) noexcept;

  template<> constexpr static inline bool matches<T>(const object_type &outcome) noexcept
  {
    return outcome.has_value();
  }

  template <>
  constexpr static inline bool matches<ErrCode>(const object_type &outcome) noexcept {
    return outcome.has_error();
  }

  template <>
  constexpr static inline bool matches<ExcPtr>(const object_type &outcome) noexcept {
    return outcome.has_exception();
  }
};


template<class T, class ErrCode, class NoValuePolicy> struct is_traits<BOOST_OUTCOME_V2_NAMESPACE::result<Obj, ErrCode, NoValuePolicy>>
{
  using object_type = BOOST_OUTCOME_V2_NAMESPACE::result<T, ErrCode, ExcPtr, NoValuePolicy>;

  template <class>
  constexpr static inline bool matches(const object_type &) noexcept;

  template<> constexpr static inline bool matches<T>(const object_type &result) noexcept
  {
    return result.has_value();
  }

  template <>
  constexpr static inline bool matches<ErrCode>(const object_type &result) noexcept {
    return result.has_error();
  }
};
#endif
#endif

#endif// CPP_AS_IS_EXPErrCodeTED_HPP

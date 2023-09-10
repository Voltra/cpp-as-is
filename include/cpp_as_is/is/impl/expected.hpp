#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_EXPECTED_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_EXPECTED_HPP

#include "../traits.hpp"

#if __has_include(<expected>)
#include <expected>

namespace cpp_as_is::ext {

	template <class T, class E> struct is_conversion_traits<std::expected<T, E>, T>
	{
		using arg_type = std::expected<T, E>;

		constexpr static inline bool matches(const arg_type &expected) { return expected.has_value(); }
	};

	template <class T, class E> struct is_conversion_traits<std::expected<T, E>, std::unexpected<E>>
	{
		using arg_type = std::expected<T, E>;

		constexpr static inline bool matches(const arg_type &expected) { return !expected.has_value(); }
	};
}// namespace cpp_as_is::ext
#endif// __has_include(<expected>)

#if __has_include(<boost/outcome.hpp>)
#include <boost/outcome.hpp>

namespace cpp_as_is::ext {
	template <class T, class ErrCode, class ExcPtr, class NoValuePolicy>
	struct is_conversion_traits<BOOST_OUTCOME_V2_NAMESPACE::outcome<T, ErrCode, ExcPtr, NoValuePolicy>, T>
	{
		using arg_type = BOOST_OUTCOME_V2_NAMESPACE::outcome<T, ErrCode, ExcPtr, NoValuePolicy>;

		constexpr static inline bool matches(const arg_type &outcome) noexcept { return outcome.has_value(); }
	};

	template <class T, class ErrCode, class ExcPtr, class NoValuePolicy>
	struct is_conversion_traits<BOOST_OUTCOME_V2_NAMESPACE::outcome<T, ErrCode, ExcPtr, NoValuePolicy>, ErrCode>
	{
		using arg_type = BOOST_OUTCOME_V2_NAMESPACE::outcome<T, ErrCode, ExcPtr, NoValuePolicy>;

		constexpr static inline bool matches(const arg_type &outcome) noexcept { return outcome.has_error(); }
	};

	template <class T, class ErrCode, class ExcPtr, class NoValuePolicy>
	struct is_conversion_traits<BOOST_OUTCOME_V2_NAMESPACE::outcome<T, ErrCode, ExcPtr, NoValuePolicy>, ExcPtr>
	{
		using arg_type = BOOST_OUTCOME_V2_NAMESPACE::outcome<T, ErrCode, ExcPtr, NoValuePolicy>;

		constexpr static inline bool matches(const arg_type &outcome) noexcept { return outcome.has_exception(); }
	};


	template <class T, class ErrCode, class NoValuePolicy>
	struct is_conversion_traits<BOOST_OUTCOME_V2_NAMESPACE::result<T, ErrCode, NoValuePolicy>, T>
	{
		using arg_type = BOOST_OUTCOME_V2_NAMESPACE::result<T, ErrCode, NoValuePolicy>;

		constexpr static inline bool matches(const arg_type &outcome) noexcept { return outcome.has_value(); }
	};

	template <class T, class ErrCode, class NoValuePolicy>
	struct is_conversion_traits<BOOST_OUTCOME_V2_NAMESPACE::result<T, ErrCode, NoValuePolicy>, ErrCode>
	{
		using arg_type = BOOST_OUTCOME_V2_NAMESPACE::result<T, ErrCode, NoValuePolicy>;

		constexpr static inline bool matches(const arg_type &outcome) noexcept { return outcome.has_error(); }
	};
}// namespace cpp_as_is::ext
#endif// __has_include(<boost/outcome.hpp>)

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_EXPECTED_HPP

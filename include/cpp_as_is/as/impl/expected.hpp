#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_EXPECTED_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_EXPECTED_HPP

#include "../traits.hpp"

#if __has_include(<expected>)
#include <expected>

namespace cpp_as_is::ext {
	template <class T, class E> struct as_conversion_traits<std::expected<T, E>, T>
	{
		using arg_type = std::expected<T, E>;
		using result_type = T;

		constexpr static inline result_type &convert(arg_type &expected) noexcept { return expected.value(); }

		constexpr static inline const result_type &convert(const arg_type &expected) noexcept
		{
			return expected.value();
		}

		constexpr static inline result_type &&convert(arg_type &&expected) noexcept { return expected.value(); }
	};

	template <class T, class E> struct as_conversion_traits<std::expected<T, E>, std::unexpected<E>>
	{
		using arg_type = std::expected<T, E>;
		using result_type = std::unexpected<E>;

		constexpr static inline result_type convert(arg_type &expected) noexcept
		{
			return std::unexpected{expected.error()};
		}

		constexpr static inline result_type convert(const arg_type &expected) noexcept
		{
			return std::unexpected{expected.error()};
		}

		constexpr static inline result_type convert(arg_type &&expected) noexcept
		{
			return std::unexpected{expected.error()};
		}
	};
}// namespace cpp_as_is::ext
#endif// __has_include(<expected>)

#if __has_include(<boost/outcome.hpp>)
#include <boost/outcome.hpp>

namespace cpp_as_is::ext {
	template <class T, class ErrCode, class ExcPtr, class NoValuePolicy>
	struct as_conversion_traits<BOOST_OUTCOME_V2_NAMESPACE::outcome<T, ErrCode, ExcPtr, NoValuePolicy>, T>
	{
		using arg_type = BOOST_OUTCOME_V2_NAMESPACE::outcome<T, ErrCode, ExcPtr, NoValuePolicy>;
		using return_type = T;

		constexpr static inline return_type &convert(arg_type &outcome) { return outcome.value(); }

		constexpr static inline const return_type &convert(const arg_type &outcome) { return outcome.value(); }

		constexpr static inline return_type &&convert(arg_type &&outcome) { return outcome.value(); }
	};

	template <class T, class ErrCode, class ExcPtr, class NoValuePolicy>
	struct as_conversion_traits<BOOST_OUTCOME_V2_NAMESPACE::outcome<T, ErrCode, ExcPtr, NoValuePolicy>, ErrCode>
	{
		using arg_type = BOOST_OUTCOME_V2_NAMESPACE::outcome<T, ErrCode, ExcPtr, NoValuePolicy>;
		using return_type = ErrCode;

		constexpr static inline return_type &convert(arg_type &outcome) { return outcome.error(); }

		constexpr static inline const return_type &convert(const arg_type &outcome) { return outcome.error(); }

		constexpr static inline return_type &&convert(arg_type &&outcome) { return outcome.error(); }
	};

	template <class T, class ErrCode, class ExcPtr, class NoValuePolicy>
	struct as_conversion_traits<BOOST_OUTCOME_V2_NAMESPACE::outcome<T, ErrCode, ExcPtr, NoValuePolicy>, ExcPtr>
	{
		using arg_type = BOOST_OUTCOME_V2_NAMESPACE::outcome<T, ErrCode, ExcPtr, NoValuePolicy>;
		using return_type = ExcPtr;

		constexpr static inline return_type &convert(arg_type &outcome) { return outcome.exception(); }

		constexpr static inline const return_type &convert(const arg_type &outcome) { return outcome.exception(); }

		constexpr static inline return_type &&convert(arg_type &&outcome) { return outcome.exception(); }
	};

	template <class T, class ErrCode, class NoValuePolicy>
	struct as_conversion_traits<BOOST_OUTCOME_V2_NAMESPACE::outcome<T, ErrCode, NoValuePolicy>, T>
	{
		using arg_type = BOOST_OUTCOME_V2_NAMESPACE::result<T, ErrCode, NoValuePolicy>;
		using return_type = T;

		constexpr static inline return_type &convert(arg_type &result) { return result.value(); }

		constexpr static inline const return_type &convert(const arg_type &result) { return result.value(); }

		constexpr static inline return_type &&convert(arg_type &&result) { return result.value(); }
	};

	template <class T, class ErrCode, class NoValuePolicy>
	struct as_conversion_traits<BOOST_OUTCOME_V2_NAMESPACE::result<T, ErrCode, NoValuePolicy>, ErrCode>
	{
		using arg_type = BOOST_OUTCOME_V2_NAMESPACE::result<T, ErrCode, NoValuePolicy>;
		using return_type = ErrCode;

		constexpr static inline return_type &convert(arg_type &result) { return result.error(); }

		constexpr static inline const return_type &convert(const arg_type &result) { return result.error(); }

		constexpr static inline return_type &&convert(arg_type &&result) { return result.error(); }
	};
}// namespace cpp_as_is::ext
#endif// __has_include(<boost/outcome.hpp>)

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_EXPECTED_HPP

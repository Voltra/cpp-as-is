#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_VARIANT_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_VARIANT_HPP

#include <type_traits>
#include <variant>
#include "../../utils.hpp"
#include "../concepts.hpp"
#include "../traits.hpp"

namespace cpp_as_is::ext {
	template <class T, class... Variants>
	CPP_AS_IS_REQUIRES(cpp_as_is::details::contains_v<T, Variants...>)
	struct is_conversion_traits<std::variant<Variants...>, T>
	{
		static_assert(cpp_as_is::details::contains_v<T, Variants...>,
			"T expected to be one of the Variants, but wasn't");

		using arg_type = std::variant<Variants...>;

		constexpr static inline bool matches(const arg_type &variant) noexcept { return holds_alternative<T>(variant); }
	};
}// namespace cpp_as_is::ext

#if defined __has_include
#if __has_include(<boost/variant.hpp>)
#include <boost/variant.hpp>
namespace cpp_as_is::ext {
	template <class T, class... Variants>
	CPP_AS_IS_REQUIRES(cpp_as_is::details::contains_v<T, Variants...>)
	struct is_conversion_traits<boost::variant<Variants...>, T>
	{
		static_assert(cpp_as_is::details::contains_v<T, Variants...>,
			"T expected to be one of the Variants, but wasn't");

		using arg_type = boost::variant<Variants...>;

		constexpr static inline bool matches(const arg_type &variant) noexcept { return variant.type() == typeid(T); }
	};
}// namespace cpp_as_is::ext
#endif
#endif

#if defined __has_include
#if __has_include(<boost/variant2/variant.hpp>)
#include <boost/variant2/variant.hpp>
namespace cpp_as_is::ext {

	template <class T, class... Variants>
	CPP_AS_IS_REQUIRES(cpp_as_is::details::contains_v<T, Variants...>)
	struct is_conversion_traits<boost::variant2::variant<Variants...>, T>
	{
		static_assert(cpp_as_is::details::contains_v<T, Variants...>,
			"T expected to be one of the Variants, but wasn't");

		using arg_type = boost::variant2::variant<Variants...>;

		constexpr static inline bool matches(const arg_type &variant) noexcept { return holds_alternative<T>(variant); }
	};
}// namespace cpp_as_is::ext
#endif
#endif

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_VARIANT_HPP

#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_CONCEPTS_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_CONCEPTS_HPP

#ifdef __cpp_concepts

#include <concepts>
#include <type_traits>
#include "./traits.hpp"

namespace cpp_as_is {
	template <class From, class To>
	concept InspectableWithIs = requires(From obj) {
		typename cpp_as_is::ext::is_conversion_traits<std::remove_cvref_t<From>, To>::arg_type;

		{
			cpp_as_is::ext::is_conversion_traits<std::remove_cvref_t<From>, To>::matches(obj)
		} noexcept -> std::same_as<bool>;
	};
}

#define CPP_AS_IS_IS_CONCEPT cpp_as_is::InspectableWithIs<T>

#else

#define CPP_AS_IS_IS_CONCEPT

#endif

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_CONCEPTS_HPP

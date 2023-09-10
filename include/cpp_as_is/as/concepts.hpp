#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_CONCEPTS_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_CONCEPTS_HPP

#ifdef __cpp_concepts
#include <concepts>
#include <type_traits>
#include "../is/concepts.hpp"
#include "./traits.hpp"

namespace cpp_as_is {
	template <class From, class To>
	concept IsConvertibleWithAs = InspectableWithIs<From, To> && requires(From obj) {
		typename cpp_as_is::ext::as_conversion_traits<std::remove_cvref_t<From>, To>::arg_type;
		typename cpp_as_is::ext::as_conversion_traits<std::remove_cvref_t<From>, To>::return_type;

		{
			cpp_as_is::ext::as_conversion_traits<std::remove_cvref_t<From>, To>::matches(obj)
		} noexcept;
	};
}

#define CPP_AS_IS_AS_CONCEPT cpp_as_is::IsConvertibleWithAs<T>

#else
#endif

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_CONCEPTS_HPP

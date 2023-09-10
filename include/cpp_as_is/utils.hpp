#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_UTILS_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_UTILS_HPP

#include <type_traits>

#ifdef __cpp_concepts
#define CPP_AS_IS_REQUIRES(...) requires __VA_ARGS__
#else
#define CPP_AS_IS_REQUIRES(...)
#endif

namespace cpp_as_is::details {
	template <class T> using remove_cvref_t = std::remove_cv_t<std::remove_reference_t<T>>;

	template <class Head, class... Tail> struct contains : std::true_type
	{
	};

	template <class T, class Head, class... Rest>
	struct contains<T, Head, Rest...>
		: std::conditional<std::is_same<T, Head>::value, std::true_type, contains<T, Rest...>>::type
	{
	};

	template <class T> struct contains<T> : std::false_type
	{
	};

	template <class T, class... List> constexpr bool contains_v = contains<T, List...>::value;
}// namespace cpp_as_is::details

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_UTILS_HPP

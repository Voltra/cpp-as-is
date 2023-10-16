#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_POINTER_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_POINTER_HPP

#include <type_traits>
#include "../traits.hpp"

namespace cpp_as_is::ext {
	template <class T> struct is_conversion_traits<T *, T>
	{
		using arg_type = T *;
		using const_arg_type = const T *;

		constexpr static inline bool matches(const_arg_type ptr) noexcept { return ptr != nullptr; }
	};


	template <class T> struct is_conversion_traits<T *, std::nullptr_t>
	{
		using arg_type = T *;
		using const_arg_type = const T *;

		constexpr static inline bool matches(const_arg_type ptr) noexcept { return ptr == nullptr; }
	};

	template <class T, class U>
	struct is_conversion_traits<T*, U> {
		using arg_type = T*;
		using const_arg_type = const T*;

		constexpr static bool can_cast = std::is_base_of_v<U, T> || std::is_base_of_v<T, U>;

		constexpr static inline bool matches(const_arg_type ptr) noexcept {
			return can_cast && ptr != nullptr;
		}
	};


	template <class T, class U>
	struct is_conversion_traits<T*, U*> {
		using arg_type = T*;
		using const_arg_type = const T*;

		constexpr static bool can_cast = std::is_base_of_v<U, T> || std::is_base_of_v<T, U>;

		constexpr static inline bool matches(const_arg_type ptr) noexcept {
			return can_cast && ptr != nullptr;
		}
	};
}// namespace cpp_as_is::ext

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_POINTER_HPP

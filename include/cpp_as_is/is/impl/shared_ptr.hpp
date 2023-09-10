#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_SHARED_PTR_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_SHARED_PTR_HPP

#include <memory>
#include "../traits.hpp"

namespace cpp_as_is::ext {
	template <class T> struct is_conversion_traits<std::shared_ptr<T>, T>
	{
		using arg_type = std::shared_ptr<T>;

		constexpr static inline bool matches(const arg_type &ptr) noexcept { return static_cast<bool>(ptr); }
	};

	template <class T> struct is_conversion_traits<std::shared_ptr<T>, std::nullptr_t>
	{
		using arg_type = std::shared_ptr<T>;

		constexpr static inline bool matches(const arg_type &ptr) noexcept { return !static_cast<bool>(ptr); }
	};
}// namespace cpp_as_is::ext

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_SHARED_PTR_HPP

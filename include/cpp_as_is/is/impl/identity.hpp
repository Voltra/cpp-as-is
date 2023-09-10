#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_IDENTITY_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_IDENTITY_HPP

#include "../traits.hpp"

namespace cpp_as_is::ext {
	template <class T> struct is_conversion_traits<T, T>
	{
		using arg_type = T;

		constexpr static inline bool matches([[maybe_unused]] const T &value) noexcept { return true; }
	};
}// namespace cpp_as_is::ext

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IMPL_IDENTITY_HPP

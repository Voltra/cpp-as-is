#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_IDENTITY_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_IDENTITY_HPP

#include "../traits.hpp"

namespace cpp_as_is::ext {
	template <class T>
	struct as_conversion_traits<T, T> {
		using arg_type = T;

		constexpr static inline T convert(arg_type arg) noexcept {
			return arg;
		}

		constexpr static inline T& convert(arg_type& arg) noexcept {
			return arg;
		}

		constexpr static inline const T& convert(const arg_type& arg) noexcept {
			return arg;
		}

		constexpr static inline T&& convert(arg_type&& arg) noexcept {
			return arg;
		}
	};
}

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_IDENTITY_HPP

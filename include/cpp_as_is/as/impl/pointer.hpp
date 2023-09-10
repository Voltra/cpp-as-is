#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_POINTER_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_POINTER_HPP

#include "../traits.hpp"

namespace cpp_as_is::ext {
	template <class T>
	struct as_conversion_traits<T*, T> {
		using arg_type = T*;
		using const_arg_type = const T*;

		static T& convert(arg_type ptr) noexcept {
			return *ptr;
		}

		static const T& convert(const_arg_type ptr) noexcept {
			return *ptr;
		}
	};

	template <class T>
	struct as_conversion_traits<T*, std::nullptr_t> {
		using arg_type = T*;

		static std::nullptr_t convert([[maybe_unused]] arg_type ptr) { return nullptr; }
	};
}

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_POINTER_HPP

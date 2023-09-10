#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_POINTER_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_POINTER_HPP

#include "../traits.hpp"

namespace cpp_as_is::ext {
	template <class T> struct as_conversion_traits<T *, T>
	{
		using arg_type = T *;
		using const_arg_type = const T *;
		using return_type = T;

		static return_type &convert(arg_type ptr) noexcept { return *ptr; }

		static const return_type &convert(const_arg_type ptr) noexcept { return *ptr; }
	};

	template <class T, class U>
	struct as_conversion_traits<T*, U> {
		using arg_type = T*;
		using const_arg_type = const T*;
		using return_type = U;

		static return_type &convert(arg_type ptr) noexcept {
			return *dynamic_cast<return_type*>(ptr);
		}

		static const return_type &convert(const_arg_type ptr) noexcept {
			return *dynamic_cast<const return_type*>(ptr);
		}
	};

	template <class T, class U>
	struct as_conversion_traits<T*, U*> {
		using arg_type = T*;
		using const_arg_type = const T*;
		using return_type = U*;
		using const_return_type = const U*;

		static return_type convert(arg_type ptr) noexcept {
			return dynamic_cast<return_type>(ptr);
		}

		static const_return_type convert(const_arg_type ptr) noexcept {
			return dynamic_cast<const_return_type>(ptr);
		}
	};
}// namespace cpp_as_is::ext

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_POINTER_HPP

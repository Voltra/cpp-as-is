#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_UNIQUE_PTR_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_UNIQUE_PTR_HPP

#include <memory>
#include "../traits.hpp"

namespace cpp_as_is::ext {
	template <class T> struct as_conversion_traits<std::unique_ptr<T>, T>
	{
		using arg_type = std::unique_ptr<T>;
		using return_type = T;

		static return_type &convert(arg_type &ptr) noexcept { return *ptr; }

		static const return_type &convert(const arg_type &ptr) noexcept { return *ptr; }
	};
}// namespace cpp_as_is::ext

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_IMPL_UNIQUE_PTR_HPP

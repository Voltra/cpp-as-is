#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_AS_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_AS_HPP

#include <utility>
#include "../utils.hpp"
#include "./concepts.hpp"
#include "./impl/impl.hpp"
#include "./traits.hpp"

namespace cpp_as_is {
	/**
	 * Function to convert from one type to another
	 * @tparam T The type to convert to
	 * @param value The value we want to convert/extract from
	 * @return The value as the desired type
	 * @warning It is undefined behavior to call this function if @code is<T>(std::as_const(value)) @endcode is false
	 */
	template <class T> inline auto as(CPP_AS_IS_AS_CONCEPT auto &&value) noexcept
	{
		return cpp_as_is::ext::as_conversion_traits<cpp_as_is::details::remove_cvref_t<decltype(value)>, T>::convert(
			std::forward<decltype(value)>(value));
	}
}// namespace cpp_as_is

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_AS_AS_HPP

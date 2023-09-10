#ifndef CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IS_HPP
#define CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IS_HPP

#include <type_traits>
#include "../utils.hpp"
#include "./concepts.hpp"
#include "./impl/impl.hpp"
#include "./traits.hpp"

namespace cpp_as_is {

	template <class T> inline bool is(CPP_AS_IS_IS_CONCEPT auto const &value) noexcept
	{
		return cpp_as_is::ext::is_conversion_traits<cpp_as_is::details::remove_cvref_t<decltype(value)>, T>::matches(
			value);
	}
}// namespace cpp_as_is

#endif// CPP_AS_IS_INCLUDE_CPP_AS_IS_IS_IS_HPP

#ifndef CPP_AS_IS_CPP_AS_IS_HPP
#define CPP_AS_IS_CPP_AS_IS_HPP

/**
 * @namespace cpp_as_is
 * Root namespace of the library
 */
namespace cpp_as_is {
/**
 * @namespace cpp_as_is::ext
 * Sub-namespace for extension points
 */
namespace ext {}

/**
 * @namespace cpp_as_is::details
 * Sub-namespace for implementation details and utility functions
 */
namespace details {}
}

#include "./is/is.hpp"
#include "./is/traits.hpp"

#endif// CPP_AS_IS_CPP_AS_IS_HPP
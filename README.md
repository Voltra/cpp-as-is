# cpp-as-is

[![ci](https://github.com/Voltra/cpp-as-is/actions/workflows/ci.yml/badge.svg)](https://github.com/Voltra/cpp-as-is/actions/workflows/ci.yml)
[![codecov](https://codecov.io/gh/Voltra/cpp-as-is/branch/main/graph/badge.svg)](https://codecov.io/gh/Voltra/cpp-as-is)
[![CodeQL](https://github.com/Voltra/cpp-as-is/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/Voltra/cpp-as-is/actions/workflows/codeql-analysis.yml)

## About cpp-as-is
A C++17 Library for generic type queries or conversions, based on [Herb Sutter's talk at CPPCon 2021](https://www.youtube.com/watch?v=raB_289NxBk)

## Usage

```cpp
#include <cpp_as_is/cpp_as_is.hpp>

int main() {
	using namespace cpp_as_is;
	
	auto someWrappedValue = getValue<int>();
	
	if (is<int>(someWrappedValue)) {
		int value = as<int>(someWrappedValue);
		std::cout << "value: " << value << '\n';
	} else {
		std::cout << "No value";
	}
	
	return 0;
}
```

## Available conversions & queries

NB: All specializations and overloads are conditionally present using `__has_include` directives

Legend: **to** means both `is` and `as` are available, **is** means only `is` is available

* `T` to `T`
* `T*` to `T`
* `T*` is `std::nullptr_t`
* `T*` to `U*`
* [`std::any`](https://en.cppreference.com/w/cpp/utility/any) to `T`
  * [`boost::any`](https://www.boost.org/doc/libs/1_61_0/doc/html/boost/any.html) to `T`
* [`std::expected<T, ...>`](https://en.cppreference.com/w/cpp/utility/expected) to `T`
  * `std::expected<T, E>` to [`std::unexpected<E>`](https://en.cppreference.com/w/cpp/utility/expected/unexpected)
    * [`BOOST_OUTCOME_V2_NAMESPACE::outcome<T, ...>`](https://www.boost.org/doc/libs/1_83_0/libs/outcome/doc/html/tutorial/essential/outcome.html) to `T`
      * `BOOST_OUTCOME_V2_NAMESPACE::outcome<T, ErrCode, ...>` to `ErrCode`
      * `BOOST_OUTCOME_V2_NAMESPACE::outcome<T, ErrCode, ExcPtr, ...>` to `ExcPtr`
    * [`BOOST_OUTCOME_V2_NAMESPACE::result<T, ...>`](https://www.boost.org/doc/libs/1_83_0/libs/outcome/doc/html/tutorial/essential/result.html) to `T`
      * `BOOST_OUTCOME_V2_NAMESPACE::result<T, ErrCode, ...>` to `ErrCode`
* [`std::future<T>`](https://en.cppreference.com/w/cpp/thread/future) to `T`
  * [`std::shared_future<T>`](https://en.cppreference.com/w/cpp/thread/shared_future) to `T`
  * [`std::experimental::future<T>`](https://en.cppreference.com/w/cpp/experimental/future) to `T`
  * [`std::experimental::shared_future<T>`](https://en.cppreference.com/w/cpp/experimental/shared_future) to `T`
  * [`boost::fibers::future<T>`](https://www.boost.org/doc/libs/1_83_0/libs/fiber/doc/html/fiber/synchronization/futures/future.html) to `T`
* [`std::optional<T>`](https://en.cppreference.com/w/cpp/utility/optional) to `T`
  * `std::optional<T>` is [`std::nullopt_t`](https://en.cppreference.com/w/cpp/utility/optional/nullopt)
  * [`boost::optional<T>`](https://www.boost.org/doc/libs/1_83_0/libs/optional/doc/html/index.html#optional.introduction) to `T`
* [`std::shared_ptr<T>`](https://en.cppreference.com/w/cpp/memory/shared_ptr) to `T`
* [`std::unique_ptr<T>`](https://en.cppreference.com/w/cpp/memory/unique_ptr) to `T`
* [`std::variant<Variants...>`](https://en.cppreference.com/w/cpp/utility/variant) to `T`

## Extendability

There are two extension points:
* `cpp_as_is::ext::is_conversion_traits<From, To>` for `cpp_as_is::is<To>(from)`, as described by the `cpp_as_is::InspectableWithIs<From, To>` concept
  * `arg_type` represents the expected argument type when calling `is`
  * `static inline bool matches(const arg_type &) noexcept` is the static member function that checks whether the types "match" (it should be constexpr if possible, though it's not required)
* `cpp_as_is::ext::as_conversion_traits<From, To>` for `cpp_as_is::as<To>(from)`, as described by the `cpp_as_is::IsConvertibleWithAs<From, To>` concept
  * `arg_type` represents the expected argument type when calling `as`
  * `return_type` represents the expected return type of `as`
  * `static inline return_type convert(arg_type) noexcept` is the static member function that handles converting from `From` to `To`

As a rule:
* if you're going to extend `as`, you must first extend `is`
* provide as many overloads for `as_conversion_traits::convert` as possible (e.g. const ref, rvalue, etc...)


## More Details

 * [Dependency Setup](README_dependencies.md)
 * [Building Details](README_building.md)
 * [Troubleshooting](README_troubleshooting.md)
 * [Docker](README_docker.md)

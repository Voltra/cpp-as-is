#include <catch2/catch_test_macros.hpp>
#include <cpp_as_is/cpp_as_is.hpp>
#include <optional>
#include <string>

TEST_CASE("True for T on std::optional<T> when the optional has a value", "[is(std::optional)]")
{
	using namespace cpp_as_is;

	const std::optional<int> optI = 42;
	REQUIRE(is<int>(optI));

	const std::optional<std::string> optS = "Hello world CPP_AS_IS!";
	REQUIRE(is<std::string>(optS));
}

TEST_CASE("False for std::nullopt_t on std::optional<T> when the optional has a value", "[is(std::optional)]")
{
	using namespace cpp_as_is;

	const std::optional<int> optI = 42;
	REQUIRE_FALSE(is<std::nullopt_t>(optI));

	const std::optional<std::string> optS = "Hello world CPP_AS_IS!";
	REQUIRE_FALSE(is<std::nullopt_t>(optS));
}

TEST_CASE("False for T on std::optional<T> when the optional has no value", "[is(std::optional)]")
{
	using namespace cpp_as_is;

	const std::optional<int> optI;
	REQUIRE_FALSE(is<int>(optI));

	const std::optional<std::string> optS;
	REQUIRE_FALSE(is<std::string>(optS));
}

TEST_CASE("True for std::nullopt_t on std::optional<T> when the optional has no value", "[is(std::optional)]")
{
	using namespace cpp_as_is;

	const std::optional<int> optI;
	REQUIRE(is<std::nullopt_t>(optI));

	const std::optional<std::string> optS;
	REQUIRE(is<std::nullopt_t>(optS));
}
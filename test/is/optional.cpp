#include <catch2/catch_test_macros.hpp>
#include <string>
#include <optional>
#include <cpp_as_is/cpp_as_is.hpp>

TEST_CASE("True for T on std::optional<T>", "[is]") {
  using namespace cpp_as_is;

  const std::optional<int> optI = 42;
  REQUIRE(is<int>(optI));

  std::optional<std::string> optS = "Hello world CPP_AS_IS!";
  REQUIRE(is<std::string>(optS));
  optS.reset();
  REQUIRE(is<std::nullopt_t>(optS));
}
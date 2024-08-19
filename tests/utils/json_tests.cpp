// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers)
// NOLINTBEGIN(readability-magic-numbers)

#include <optional>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <nlohmann/json.hpp>

#include "utils/json.hpp"  // IWYU pragma: keep

TEST_CASE(
    "Serialization and Deserialization of std::optional<int>",
    "[optional][int]") {
  SECTION("optional<int> with value") {
    std::optional<int> opt = 42;
    nlohmann::json j = opt;
    REQUIRE(j.is_number_integer());
    REQUIRE(j.get<int>() == 42);

    auto deserialized_opt = j.get<std::optional<int>>();
    REQUIRE(deserialized_opt.has_value());
    REQUIRE(deserialized_opt.value() == 42);
  }

  SECTION("Empty optional<int>") {
    std::optional<int> opt;
    nlohmann::json j = opt;
    REQUIRE(j.is_null());

    auto deserialized_opt = j.get<std::optional<int>>();
    REQUIRE(!deserialized_opt.has_value());
  }
}

TEST_CASE(
    "Serialization and Deserialization of std::optional<std::string>",
    "[optional][string]") {
  SECTION("optional<std::string> with value") {
    std::optional<std::string> opt = "hello";
    nlohmann::json j = opt;
    REQUIRE(j.is_string());
    REQUIRE(j.get<std::string>() == "hello");

    auto deserialized_opt = j.get<std::optional<std::string>>();
    REQUIRE(deserialized_opt.has_value());
    REQUIRE(deserialized_opt.value() == "hello");
  }

  SECTION("Empty optional<std::string>") {
    std::optional<std::string> opt;
    nlohmann::json j = opt;
    REQUIRE(j.is_null());

    auto deserialized_opt = j.get<std::optional<std::string>>();
    REQUIRE(!deserialized_opt.has_value());
  }
}

TEST_CASE(
    "Serialization and Deserialization of std::variant<int, std::string>",
    "[variant][int][string]") {
  SECTION("variant<int, std::string> with int") {
    std::variant<int, std::string> var = 42;
    nlohmann::json j = var;
    REQUIRE(j.is_number_integer());
    REQUIRE(j == 42);

    auto deserialized_var = j.get<std::variant<int, std::string>>();
    REQUIRE(std::holds_alternative<int>(deserialized_var));
    REQUIRE(std::get<int>(deserialized_var) == 42);
  }

  SECTION("variant<int, std::string> with std::string") {
    std::variant<int, std::string> var = "hello";
    nlohmann::json j = var;
    REQUIRE(j.is_string());
    REQUIRE(j == "hello");

    auto deserialized_var = j.get<std::variant<int, std::string>>();
    REQUIRE(std::holds_alternative<std::string>(deserialized_var));
    REQUIRE(std::get<std::string>(deserialized_var) == "hello");
  }
}

// Define custom structs for testing
struct MyStruct {
  int a;
  std::string b;
};

struct ComplexStruct {
  MyStruct s;
  double d;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(MyStruct, a, b)
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(ComplexStruct, s, d)

TEST_CASE(
    "Serialization and Deserialization of std::variant<int, MyStruct>",
    "[variant][int][MyStruct]") {
  SECTION("variant<int, MyStruct> with int") {
    std::variant<int, MyStruct> var = 42;
    nlohmann::json j = var;
    REQUIRE(j.is_number_integer());
    REQUIRE(j == 42);

    auto deserialized_var = j.get<std::variant<int, MyStruct>>();
    REQUIRE(std::holds_alternative<int>(deserialized_var));
    REQUIRE(std::get<int>(deserialized_var) == 42);
  }

  SECTION("variant<int, MyStruct> with MyStruct") {
    MyStruct my_struct = {1, "test"};
    std::variant<int, MyStruct> var = my_struct;
    nlohmann::json j = var;
    REQUIRE(j.is_object());
    REQUIRE(j["a"] == 1);
    REQUIRE(j["b"] == "test");

    auto deserialized_var = j.get<std::variant<int, MyStruct>>();
    REQUIRE(std::holds_alternative<MyStruct>(deserialized_var));
    REQUIRE(std::get<MyStruct>(deserialized_var).a == 1);
    REQUIRE(std::get<MyStruct>(deserialized_var).b == "test");
  }
}

TEST_CASE(
    "Serialization and Deserialization of std::variant<MyStruct, "
    "ComplexStruct>",
    "[variant][MyStruct][ComplexStruct]") {
  SECTION("variant<MyStruct, ComplexStruct> with MyStruct") {
    MyStruct my_struct = {2, "example"};
    std::variant<MyStruct, ComplexStruct> var = my_struct;
    nlohmann::json j = var;
    REQUIRE(j.is_object());
    REQUIRE(j["a"] == 2);
    REQUIRE(j["b"] == "example");

    auto deserialized_var = j.get<std::variant<MyStruct, ComplexStruct>>();
    REQUIRE(std::holds_alternative<MyStruct>(deserialized_var));
    REQUIRE(std::get<MyStruct>(deserialized_var).a == 2);
    REQUIRE(std::get<MyStruct>(deserialized_var).b == "example");
  }

  SECTION("variant<MyStruct, ComplexStruct> with ComplexStruct") {
    ComplexStruct complex_struct = {{3, "nested"}, 4.2};
    std::variant<MyStruct, ComplexStruct> var = complex_struct;
    nlohmann::json j = var;
    REQUIRE(j.is_object());
    REQUIRE(j["s"]["a"] == 3);
    REQUIRE(j["s"]["b"] == "nested");
    REQUIRE(j["d"] == 4.2);

    auto deserialized_var = j.get<std::variant<MyStruct, ComplexStruct>>();
    REQUIRE(std::holds_alternative<ComplexStruct>(deserialized_var));
    REQUIRE(std::get<ComplexStruct>(deserialized_var).s.a == 3);
    REQUIRE(std::get<ComplexStruct>(deserialized_var).s.b == "nested");
    REQUIRE(std::get<ComplexStruct>(deserialized_var).d == 4.2);
  }
}

TEST_CASE(
    "Serialization and Deserialization of std::optional<std::variant<int, "
    "std::string>>",
    "[optional][variant][int][string]") {
  SECTION("optional<variant<int, std::string>> with int") {
    std::optional<std::variant<int, std::string>> opt_var = 42;
    nlohmann::json j = opt_var;
    REQUIRE(j.is_number_integer());
    REQUIRE(j == 42);

    auto deserialized_opt_var =
        j.get<std::optional<std::variant<int, std::string>>>();
    REQUIRE(deserialized_opt_var.has_value());
    REQUIRE(std::holds_alternative<int>(deserialized_opt_var.value()));
    REQUIRE(std::get<int>(deserialized_opt_var.value()) == 42);
  }

  SECTION("optional<variant<int, std::string>> with std::string") {
    std::optional<std::variant<int, std::string>> opt_var =
        std::string("hello");
    nlohmann::json j = opt_var;
    REQUIRE(j.is_string());
    REQUIRE(j == "hello");

    auto deserialized_opt_var =
        j.get<std::optional<std::variant<int, std::string>>>();
    REQUIRE(deserialized_opt_var.has_value());
    REQUIRE(std::holds_alternative<std::string>(deserialized_opt_var.value()));
    REQUIRE(std::get<std::string>(deserialized_opt_var.value()) == "hello");
  }

  SECTION("Empty optional<variant<int, std::string>>") {
    std::optional<std::variant<int, std::string>> opt_var;
    nlohmann::json j = opt_var;
    REQUIRE(j.is_null());

    auto deserialized_opt_var =
        j.get<std::optional<std::variant<int, std::string>>>();
    REQUIRE(!deserialized_opt_var.has_value());
  }
}

TEST_CASE(
    "Serialization and Deserialization of std::optional<std::variant<int, "
    "MyStruct>>",
    "[optional][variant][int][MyStruct]") {
  SECTION("optional<variant<int, MyStruct>> with int") {
    std::optional<std::variant<int, MyStruct>> opt_var = 42;
    nlohmann::json j = opt_var;
    REQUIRE(j.is_number_integer());
    REQUIRE(j == 42);

    auto deserialized_opt_var =
        j.get<std::optional<std::variant<int, MyStruct>>>();
    REQUIRE(deserialized_opt_var.has_value());
    REQUIRE(std::holds_alternative<int>(deserialized_opt_var.value()));
    REQUIRE(std::get<int>(deserialized_opt_var.value()) == 42);
  }

  SECTION("optional<variant<int, MyStruct>> with MyStruct") {
    MyStruct my_struct = {1, "test"};
    std::optional<std::variant<int, MyStruct>> opt_var = my_struct;
    nlohmann::json j = opt_var;
    REQUIRE(j.is_object());
    REQUIRE(j["a"] == 1);
    REQUIRE(j["b"] == "test");

    auto deserialized_opt_var =
        j.get<std::optional<std::variant<int, MyStruct>>>();
    REQUIRE(deserialized_opt_var.has_value());
    REQUIRE(std::holds_alternative<MyStruct>(deserialized_opt_var.value()));
    REQUIRE(std::get<MyStruct>(deserialized_opt_var.value()).a == 1);
    REQUIRE(std::get<MyStruct>(deserialized_opt_var.value()).b == "test");
  }

  SECTION("Empty optional<variant<int, MyStruct>>") {
    std::optional<std::variant<int, MyStruct>> opt_var;
    nlohmann::json j = opt_var;
    REQUIRE(j.is_null());

    auto deserialized_opt_var =
        j.get<std::optional<std::variant<int, MyStruct>>>();
    REQUIRE(!deserialized_opt_var.has_value());
  }
}

// NOLINTEND(readability-magic-numbers)
// NOLINTEND(cppcoreguidelines-avoid-magic-numbers)

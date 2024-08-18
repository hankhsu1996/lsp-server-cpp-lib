#pragma once

// NOLINTBEGIN(readability-identifier-naming)

#include <optional>
#include <stdexcept>
#include <string_view>
#include <variant>

#include <nlohmann/json.hpp>

namespace nlohmann {

// Helper to convert type T into a constexpr string
template <typename T>
constexpr auto make_type_name() {
  using namespace std::string_view_literals;
#ifdef __clang__
  std::string_view name = __PRETTY_FUNCTION__;
  name.remove_prefix("auto nlohmann::make_type_name() [T = "sv.size());
  name.remove_suffix("]"sv.size());
#elif defined(__GNUC__) || defined(__GNUG__)
  std::string_view name = __PRETTY_FUNCTION__;
  name.remove_prefix(
      "constexpr auto nlohmann::make_type_name() [with T = "sv.size());
  name.remove_suffix("]"sv.size());
#elif defined(_MSC_VER)
  std::string_view name = __FUNCSIG__;
  name.remove_prefix("auto __cdecl nlohmann::make_type_name<"sv.size());
  name.remove_suffix(">(void)"sv.size());
#endif
  return name;
}

template <typename T>
constexpr auto type_name_sv = make_type_name<T>();

// Serializer for std::variant
template <typename... Ts>
struct adl_serializer<std::variant<Ts...>> {
  using Variant = std::variant<Ts...>;
  using Json = nlohmann::json;

  static void to_json(Json& j, const Variant& data) {
    std::visit(
        [&j](const auto& v) {
          using T = std::decay_t<decltype(v)>;
          j["type"] = type_name_sv<T>;
          j["data"] = v;
        },
        data);
  }

  static void from_json(const Json& j, Variant& data) {
    auto variant_from_json = [&](const auto& type) -> bool {
      using T = std::decay_t<decltype(type)>;
      if (j.at("type").get<std::string_view>() != type_name_sv<T>) {
        return false;
      }
      data = j.at("data").template get<T>();
      return true;
    };

    bool found = (variant_from_json(Ts{}) || ...);
    if (!found) {
      throw std::invalid_argument("Invalid JSON type for variant");
    }
  }
};

template <typename T>
void to_json(nlohmann::json& j, const std::optional<T>& opt) {
  if (opt.has_value()) {
    j = *opt;
  } else {
    j = nullptr;
  }
}

template <typename T>
void from_json(const nlohmann::json& j, std::optional<T>& opt) {
  if (j.is_null()) {
    opt.reset();
  } else {
    opt = j.get<T>();
  }
}

}  // namespace nlohmann

// NOLINTEND(readability-identifier-naming)

#pragma once

// NOLINTBEGIN(readability-identifier-naming)

#include <optional>
#include <stdexcept>
#include <variant>

#include <nlohmann/json.hpp>

namespace nlohmann {

/**
 * @brief Specialization of adl_serializer for std::variant<Ts...>.
 *
 * This specialization allows us to leverage `NLOHMANN_DEFINE_TYPE_INTRUSIVE`
 * or `NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE` macros for structs containing
 * `std::variant`, simplifying the implementation of `to_json` and `from_json`
 * functions.
 *
 * @note The `from_json` function deserializes by attempting each type in the
 * variant sequentially. If deserialization fails for a type, it moves on to
 * the next. This approach, while convenient, has a linear performance cost
 * relative to the number of types in the variant, which can be inefficient
 * for large variants.
 *
 * @warning In contexts like the LSP specification, where many complex
 * variants are present, this may lead to performance issues. The alternative
 * would be to implement custom `from_json` functions tailored to specific
 * variants, which is more performant but also much more labor-intensive.
 */
template <typename... Ts>
struct adl_serializer<std::variant<Ts...>> {
  static void to_json(nlohmann::json& j, const std::variant<Ts...>& data) {
    std::visit([&j](const auto& v) { j = v; }, data);
  }

  static void from_json(const nlohmann::json& j, std::variant<Ts...>& data) {
    auto variant_from_json = [&](const auto& type) -> bool {
      using T = std::decay_t<decltype(type)>;
      try {
        data = j.get<T>();
        return true;
      } catch (const nlohmann::json::exception&) {
        return false;
      }
    };

    bool found = (variant_from_json(Ts{}) || ...);
    if (!found) {
      throw std::runtime_error("Invalid JSON type for variant");
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

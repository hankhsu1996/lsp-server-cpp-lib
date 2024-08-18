#pragma once

#include <cstdint>
#include <map>
#include <memory>
#include <string>
#include <variant>
#include <vector>

#include <nlohmann/json.hpp>

#include "utils/json_utils.hpp"  // IWYU pragma: keep

namespace lsp::types {

// Base types
using Integer = std::int32_t;
using Uinteger = std::uint32_t;
using Decimal = double;

struct LSPAny;
using LSPObject = std::map<std::string, std::shared_ptr<LSPAny>>;
using LSPArray = std::vector<std::shared_ptr<LSPAny>>;

struct LSPAny : public std::variant<
                    std::nullptr_t, bool, Integer, Uinteger, Decimal,
                    std::string, LSPObject, LSPArray> {
  using variant::variant;
};

// Cancellation Support
struct CancelParams {
  std::variant<Integer, std::string> id;

  explicit CancelParams(std::variant<Integer, std::string> id)
      : id(std::move(id)) {
  }
};

// Progress Support
using ProgressToken = std::variant<Integer, std::string>;

template <typename T>
struct ProgressParams {
  ProgressToken token;
  T value;

  ProgressParams(ProgressToken token, T value)
      : token(std::move(token)), value(std::move(value)) {
  }
};

// JSON serialization
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(CancelParams, id);

}  // namespace lsp::types

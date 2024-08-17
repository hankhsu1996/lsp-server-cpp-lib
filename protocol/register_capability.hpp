#pragma once

#include <optional>

#include "types/basic.hpp"

namespace lsp::protocol {

using lsp::types::DocumentSelector;
using lsp::types::LSPAny;

// Register Capability
struct Registration {
  std::string id;
  std::string method;
  std::optional<LSPAny> register_options;

  Registration() = default;

  explicit Registration(
      std::string id, std::string method,
      std::optional<LSPAny> register_options)
      : id(std::move(id)),
        method(std::move(method)),
        register_options(std::move(register_options)) {
  }
};

struct RegistrationParams {
  std::vector<Registration> registrations;

  RegistrationParams() = default;

  explicit RegistrationParams(std::vector<Registration> registrations)
      : registrations(std::move(registrations)) {
  }
};

struct StaticRegistrationOptions {
  std::optional<std::string> id;

  StaticRegistrationOptions() = default;

  explicit StaticRegistrationOptions(std::optional<std::string> id)
      : id(std::move(id)) {
  }
};

struct TextDocumentRegistrationOptions {
  std::optional<DocumentSelector> document_selector;

  TextDocumentRegistrationOptions() = default;

  explicit TextDocumentRegistrationOptions(
      std::optional<DocumentSelector> document_selector)
      : document_selector(std::move(document_selector)) {
  }
};

// Unregister Capability
struct Unregistration {
  std::string id;
  std::string method;

  Unregistration() = default;

  explicit Unregistration(std::string id, std::string method)
      : id(std::move(id)), method(std::move(method)) {
  }
};

struct UnregistrationParams {
  // Note the intentional typo to match the spec
  std::vector<Unregistration> unregisterations;

  UnregistrationParams() = default;

  explicit UnregistrationParams(std::vector<Unregistration> unregisterations)
      : unregisterations(std::move(unregisterations)) {
  }
};

}  // namespace lsp::protocol

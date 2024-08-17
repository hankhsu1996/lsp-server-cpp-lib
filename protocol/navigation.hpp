#pragma once

#include <optional>

#include "protocol/register_capability.hpp"
#include "types/basic.hpp"

namespace lsp::protocol {

using lsp::types::PartialResultParams;
using lsp::types::Position;
using lsp::types::TextDocumentIdentifier;
using lsp::types::TextDocumentPositionParams;
using lsp::types::WorkDoneProgressOptions;
using lsp::types::WorkDoneProgressParams;

// Go To Declaration
struct DeclarationClientCapabilities {
  std::optional<bool> dynamic_registration;
  std::optional<bool> link_support;

  DeclarationClientCapabilities() = default;

  explicit DeclarationClientCapabilities(
      std::optional<bool> dynamic_registration,
      std::optional<bool> link_support)
      : dynamic_registration(dynamic_registration), link_support(link_support) {
  }
};

struct DeclarationOptions : public WorkDoneProgressOptions {
  DeclarationOptions() = default;

  explicit DeclarationOptions(bool work_done_progress)
      : WorkDoneProgressOptions(work_done_progress) {
  }
};

struct DeclarationRegistrationOptions : public DeclarationOptions,
                                        public TextDocumentRegistrationOptions,
                                        public StaticRegistrationOptions {
  DeclarationRegistrationOptions() = default;

  explicit DeclarationRegistrationOptions(
      bool work_done_progress,
      std::optional<DocumentSelector> document_selector,
      std::optional<std::string> id)
      : DeclarationOptions(work_done_progress),
        TextDocumentRegistrationOptions(document_selector),
        StaticRegistrationOptions(id) {
  }
};

struct DeclarationParams : public TextDocumentPositionParams,
                           public WorkDoneProgressParams,
                           public PartialResultParams {
  DeclarationParams() = delete;
};

// Go To Definition
struct DefinitionClientCapabilities {
  std::optional<bool> dynamic_registration;
  std::optional<bool> link_support;

  DefinitionClientCapabilities() = default;

  explicit DefinitionClientCapabilities(
      std::optional<bool> dynamic_registration,
      std::optional<bool> link_support)
      : dynamic_registration(dynamic_registration), link_support(link_support) {
  }
};

struct DefinitionOptions : public WorkDoneProgressOptions {
  DefinitionOptions() = default;
};

struct DefinitionRegistrationOptions : public TextDocumentRegistrationOptions,
                                       public DefinitionOptions {
  DefinitionRegistrationOptions() = default;
};

struct DefinitionParams : public TextDocumentPositionParams,
                          public WorkDoneProgressParams,
                          public PartialResultParams {
  DefinitionParams() = delete;
};

// Go To Type Definition
struct TypeDefinitionClientCapabilities {
  std::optional<bool> dynamic_registration;
  std::optional<bool> link_support;

  TypeDefinitionClientCapabilities() = default;

  explicit TypeDefinitionClientCapabilities(
      std::optional<bool> dynamic_registration,
      std::optional<bool> link_support)
      : dynamic_registration(dynamic_registration), link_support(link_support) {
  }
};

struct TypeDefinitionOptions : public WorkDoneProgressOptions {
  TypeDefinitionOptions() = default;
};

struct TypeDefinitionRegistrationOptions
    : public TextDocumentRegistrationOptions,
      public TypeDefinitionOptions,
      public StaticRegistrationOptions {
  TypeDefinitionRegistrationOptions() = default;
};

struct TypeDefinitionParams : public TextDocumentPositionParams,
                              public WorkDoneProgressParams,
                              public PartialResultParams {
  TypeDefinitionParams() = delete;
};

// Go To Implementation
struct ImplementationClientCapabilities {
  std::optional<bool> dynamic_registration;
  std::optional<bool> link_support;

  ImplementationClientCapabilities() = default;

  explicit ImplementationClientCapabilities(
      std::optional<bool> dynamic_registration,
      std::optional<bool> link_support)
      : dynamic_registration(dynamic_registration), link_support(link_support) {
  }
};

struct ImplementationOptions : public WorkDoneProgressOptions {
  ImplementationOptions() = default;
};

struct ImplementationRegistrationOptions
    : public TextDocumentRegistrationOptions,
      public ImplementationOptions,
      public StaticRegistrationOptions {
  ImplementationRegistrationOptions() = default;
};

struct ImplementationParams : public TextDocumentPositionParams,
                              public WorkDoneProgressParams,
                              public PartialResultParams {
  ImplementationParams() = delete;
};

// Find References
struct ReferenceClientCapabilities {
  std::optional<bool> dynamic_registration;

  ReferenceClientCapabilities() = default;

  explicit ReferenceClientCapabilities(std::optional<bool> dynamic_registration)
      : dynamic_registration(dynamic_registration) {
  }
};

struct ReferenceOptions : public WorkDoneProgressOptions {
  ReferenceOptions() = default;
};

struct ReferenceRegistrationOptions : public TextDocumentRegistrationOptions,
                                      public ReferenceOptions {
  ReferenceRegistrationOptions() = default;
};

struct ReferenceContext {
  bool include_declaration;

  ReferenceContext() = default;

  explicit ReferenceContext(bool include_declaration)
      : include_declaration(include_declaration) {
  }
};

struct ReferenceParams : public TextDocumentPositionParams,
                         public WorkDoneProgressParams,
                         public PartialResultParams {
  ReferenceContext context;

  ReferenceParams() = delete;

  explicit ReferenceParams(
      TextDocumentIdentifier text_document, Position position,
      std::optional<std::string> work_done_token,
      std::optional<std::string> partial_result_token, ReferenceContext context)
      : TextDocumentPositionParams(
            std::move(text_document), std::move(position)),
        WorkDoneProgressParams(std::move(work_done_token)),
        PartialResultParams(std::move(partial_result_token)),
        context(std::move(context)) {
  }
};

}  // namespace lsp::protocol

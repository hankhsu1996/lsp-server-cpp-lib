#pragma once

#include <cstdint>
#include <optional>

#include "protocol/register_capability.hpp"
#include "types/basic.hpp"

namespace lsp::protocol {

using lsp::types::Range;
using lsp::types::TextDocumentIdentifier;
using lsp::types::TextDocumentItem;
using lsp::types::Uinteger;
using lsp::types::VersionedTextDocumentIdentifier;

// Overview - Text Document
enum class TextDocumentSyncKind : std::int32_t {
  kNone = 0,
  kFull = 1,
  kIncremental = 2
};

// Did Open Text Document
struct DidOpenTextDocumentParams {
  TextDocumentItem text_document;

  explicit DidOpenTextDocumentParams(TextDocumentItem text_document)
      : text_document(std::move(text_document)) {
  }
};

// Did Change Text Document
struct TextDocumentChangeRegistrationOptions
    : public TextDocumentRegistrationOptions {
  TextDocumentSyncKind sync_kind;

  explicit TextDocumentChangeRegistrationOptions(TextDocumentSyncKind sync_kind)
      : sync_kind(sync_kind) {
  }
};

struct TextDocumentContentChangeEvent {
  std::optional<Range> range;
  std::optional<Uinteger> range_length;
  std::string text;

  explicit TextDocumentContentChangeEvent(std::string text)
      : text(std::move(text)) {
  }

  TextDocumentContentChangeEvent(Range range, std::string text)
      : range(std::move(range)), text(std::move(text)) {
  }

  TextDocumentContentChangeEvent(
      Range range, Uinteger range_length, std::string text)
      : range(std::move(range)),
        range_length(range_length),
        text(std::move(text)) {
  }
};

struct DidChangeTextDocumentParams {
  VersionedTextDocumentIdentifier text_document;
  std::vector<TextDocumentContentChangeEvent> content_changes;

  DidChangeTextDocumentParams(
      VersionedTextDocumentIdentifier text_document,
      std::vector<TextDocumentContentChangeEvent> content_changes)
      : text_document(std::move(text_document)),
        content_changes(std::move(content_changes)) {
  }
};

// Will Save Text Document
// Will Save Document Wait Until
enum class TextDocumentSaveReason : std::int32_t {
  kManual = 1,
  kAfterDelay = 2,
  kFocusOut = 3
};

struct WillSaveTextDocumentParams {
  TextDocumentIdentifier text_document;
  TextDocumentSaveReason reason;

  WillSaveTextDocumentParams(
      TextDocumentIdentifier text_document, TextDocumentSaveReason reason)
      : text_document(std::move(text_document)), reason(reason) {
  }
};

// Did Save Text Document
struct SaveOptions {
  std::optional<bool> include_text;

  explicit SaveOptions(std::optional<bool> include_text = std::nullopt)
      : include_text(include_text) {
  }
};

struct TextDocumentSaveRegistrationOptions
    : public TextDocumentRegistrationOptions {
  std::optional<bool> include_text;

  explicit TextDocumentSaveRegistrationOptions(
      std::optional<bool> include_text = std::nullopt)
      : include_text(include_text) {
  }
};

struct DidSaveTextDocumentParams {
  TextDocumentIdentifier text_document;
  std::optional<std::string> text;

  explicit DidSaveTextDocumentParams(
      TextDocumentIdentifier text_document,
      std::optional<std::string> text = std::nullopt)
      : text_document(std::move(text_document)), text(std::move(text)) {
  }
};

// Did Close Text Document
struct DidCloseTextDocumentParams {
  TextDocumentIdentifier text_document;

  explicit DidCloseTextDocumentParams(TextDocumentIdentifier text_document)
      : text_document(std::move(text_document)) {
  }
};

// Rename a Text Document
struct TextDocumentSyncClientCapabilities {
  std::optional<bool> dynamic_registration;
  std::optional<bool> will_save;
  std::optional<bool> will_save_wait_until;
  std::optional<bool> did_save;

  explicit TextDocumentSyncClientCapabilities(
      std::optional<bool> dynamic_registration = std::nullopt,
      std::optional<bool> will_save = std::nullopt,
      std::optional<bool> will_save_wait_until = std::nullopt,
      std::optional<bool> did_save = std::nullopt)
      : dynamic_registration(dynamic_registration),
        will_save(will_save),
        will_save_wait_until(will_save_wait_until),
        did_save(did_save) {
  }
};

struct TextDocumentSyncOptions {
  std::optional<bool> open_close;
  std::optional<TextDocumentSyncKind> change;
  std::optional<bool> will_save;
  std::optional<bool> will_save_wait_until;
  std::optional<std::variant<bool, SaveOptions>> save;

  explicit TextDocumentSyncOptions(
      std::optional<bool> open_close = std::nullopt,
      std::optional<TextDocumentSyncKind> change = std::nullopt,
      std::optional<bool> will_save = std::nullopt,
      std::optional<bool> will_save_wait_until = std::nullopt,
      std::optional<std::variant<bool, SaveOptions>> save = std::nullopt)
      : open_close(open_close),
        change(change),
        will_save(will_save),
        will_save_wait_until(will_save_wait_until),
        save(std::move(save)) {
  }
};

}  // namespace lsp::protocol

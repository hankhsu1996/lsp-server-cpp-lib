#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <utility>

#include <nlohmann/json.hpp>

#include "types/base.hpp"
#include "utils/json.hpp"  // IWYU pragma: keep

namespace lsp::types {

// URI
using URI = std::string;
using DocumentUri = std::string;

// Regular Expressions
struct RegularExpressionsClientCapabilities {
  std::string engine;
  std::optional<std::string> version;

  RegularExpressionsClientCapabilities() = default;

  explicit RegularExpressionsClientCapabilities(
      std::string engine, std::optional<std::string> version)
      : engine(std::move(engine)), version(std::move(version)) {
  }
};

// Position
struct Position {
  Uinteger line{};
  Uinteger character{};

  Position() = default;

  constexpr explicit Position(Uinteger line, Uinteger character)
      : line(line), character(character) {
  }
};

// Range
struct Range {
  Position start;
  Position end;

  Range() = default;

  constexpr explicit Range(const Position& start, const Position& end)
      : start(start), end(end) {
  }
};

// Text Document Item
struct TextDocumentItem {
  DocumentUri uri;
  std::string language_id;
  std::int32_t version{};
  std::string text;

  TextDocumentItem() = default;

  explicit TextDocumentItem(
      DocumentUri uri, std::string language_id, std::int32_t version,
      std::string text)
      : uri(std::move(uri)),
        language_id(std::move(language_id)),
        version(version),
        text(std::move(text)) {
  }
};

// Text Document Identifier
struct TextDocumentIdentifier {
  DocumentUri uri;

  TextDocumentIdentifier() = default;

  explicit TextDocumentIdentifier(DocumentUri uri) : uri(std::move(uri)) {
  }
};

// Versioned Text Document Identifier
struct VersionedTextDocumentIdentifier : public TextDocumentIdentifier {
  std::int32_t version{};

  VersionedTextDocumentIdentifier() = default;

  explicit VersionedTextDocumentIdentifier(
      DocumentUri uri, std::int32_t version)
      : TextDocumentIdentifier(std::move(uri)), version(version) {
  }
};

struct OptionalVersionedTextDocumentIdentifier : public TextDocumentIdentifier {
  std::optional<std::int32_t> version;

  OptionalVersionedTextDocumentIdentifier() = default;

  OptionalVersionedTextDocumentIdentifier(
      DocumentUri uri, std::optional<std::int32_t> version)
      : TextDocumentIdentifier(std::move(uri)), version(version) {
  }
};

// Text Document Position Params
struct TextDocumentPositionParams {
  TextDocumentIdentifier text_document;
  Position position;

  TextDocumentPositionParams() = default;

  explicit TextDocumentPositionParams(
      TextDocumentIdentifier text_document, Position position)
      : text_document(std::move(text_document)), position(position) {
  }
};

// Document Filter
struct DocumentFilter {
  std::optional<std::string> language;
  std::optional<std::string> scheme;
  std::optional<std::string> pattern;

  DocumentFilter() = default;

  explicit DocumentFilter(
      std::optional<std::string> language, std::optional<std::string> scheme,
      std::optional<std::string> pattern)
      : language(std::move(language)),
        scheme(std::move(scheme)),
        pattern(std::move(pattern)) {
  }
};

using DocumentSelector = std::vector<DocumentFilter>;

// Text Edit
struct TextEdit {
  Range range;
  std::string newT_text;

  TextEdit() = default;

  explicit TextEdit(Range range, std::string new_text)
      : range(std::move(range)), newT_text(std::move(new_text)) {
  }
};

struct ChangeAnnotation {
  std::string label;
  std::optional<bool> needs_confirmation;
  std::optional<std::string> description;

  ChangeAnnotation() = default;

  explicit ChangeAnnotation(
      std::string label, std::optional<bool> needs_confirmation,
      std::optional<std::string> description)
      : label(std::move(label)),
        needs_confirmation(needs_confirmation),
        description(std::move(description)) {
  }
};

using ChangeAnnotationIdentifier = std::string;

struct AnnotatedTextEdit : public TextEdit {
  ChangeAnnotationIdentifier annotation_id;

  AnnotatedTextEdit() = default;

  AnnotatedTextEdit(
      Range range, std::string new_text,
      ChangeAnnotationIdentifier annotation_id)
      : TextEdit(std::move(range), std::move(new_text)),
        annotation_id(std::move(annotation_id)) {
  }
};

// Text Document Edit
struct TextDocumentEdit {
  OptionalVersionedTextDocumentIdentifier text_document;
  std::vector<std::variant<TextEdit, AnnotatedTextEdit>> edits;

  TextDocumentEdit() = default;

  TextDocumentEdit(
      OptionalVersionedTextDocumentIdentifier text_document,
      std::vector<std::variant<TextEdit, AnnotatedTextEdit>> edits)
      : text_document(std::move(text_document)), edits(std::move(edits)) {
  }
};

// Location
struct Location {
  DocumentUri uri;
  Range range;

  Location() = default;

  explicit Location(DocumentUri uri, Range range)
      : uri(std::move(uri)), range(std::move(range)) {
  }
};

// Location Link
struct LocationLink {
  std::optional<Range> origin_selection_range;
  DocumentUri target_uri;
  Range target_range;
  Range target_selection_range;

  LocationLink() = default;

  LocationLink(
      std::optional<Range> origin_selection_range, DocumentUri target_uri,
      Range target_range, Range target_selection_range)
      : origin_selection_range(std::move(origin_selection_range)),
        target_uri(std::move(target_uri)),
        target_range(std::move(target_range)),
        target_selection_range(std::move(target_selection_range)) {
  }
};

// Diagnostic
enum class DiagnosticSeverity : std::uint8_t {
  kError = 1,
  kWarning = 2,
  kInformation = 3,
  kHint = 4
};

enum class DiagnosticTag : std::uint8_t { kUnnecessary = 1, kDeprecated = 2 };

struct CodeDescription {
  URI href;

  CodeDescription() = default;

  explicit CodeDescription(URI href) : href(std::move(href)) {
  }
};

struct DiagnosticRelatedInformation {
  Location location;
  std::string message;

  DiagnosticRelatedInformation() = default;

  DiagnosticRelatedInformation(Location location, std::string message)
      : location(std::move(location)), message(std::move(message)) {
  }
};

struct Diagnostic {
  Range range;
  std::optional<DiagnosticSeverity> severity;
  std::variant<Integer, std::string> code;
  std::optional<CodeDescription> code_description;
  std::optional<std::string> source;
  std::string message;
  std::optional<std::vector<DiagnosticTag>> tags;
  std::optional<std::vector<DiagnosticRelatedInformation>> related_information;
  std::optional<LSPAny> data;

  Diagnostic() = default;

  explicit Diagnostic(
      Range range, std::string message,
      std::optional<DiagnosticSeverity> severity,
      std::variant<Integer, std::string> code,
      std::optional<CodeDescription> code_description,
      std::optional<std::string> source,
      std::optional<std::vector<DiagnosticTag>> tags,
      std::optional<std::vector<DiagnosticRelatedInformation>>
          related_information,
      std::optional<LSPAny> data)
      : range(std::move(range)),
        severity(std::move(severity)),
        code(std::move(code)),
        code_description(std::move(code_description)),
        source(std::move(source)),
        message(std::move(message)),
        tags(std::move(tags)),
        related_information(std::move(related_information)),
        data(std::move(data)) {
  }
};

// Command
struct Command {
  std::string title;
  std::string command;
  std::optional<std::vector<LSPAny>> arguments;

  Command() = default;

  explicit Command(
      std::string title, std::string command,
      std::optional<std::vector<LSPAny>> arguments)
      : title(std::move(title)),
        command(std::move(command)),
        arguments(std::move(arguments)) {
  }
};

// MarkupContent
enum class MarkupKind { kPlainText, kMarkdown };

struct MarkupContent {
  MarkupKind kind{};
  std::string value;

  MarkupContent() = default;

  explicit MarkupContent(MarkupKind kind, std::string value)
      : kind(kind), value(std::move(value)) {
  }
};

// File Resource Changes
struct CreateFileOptions {
  std::optional<bool> overwrite;
  std::optional<bool> ignore_if_exists;

  CreateFileOptions() = default;

  explicit CreateFileOptions(
      std::optional<bool> overwrite, std::optional<bool> ignore_if_exists)
      : overwrite(overwrite), ignore_if_exists(ignore_if_exists) {
  }
};

struct CreateFile {
  std::string kind = "create";
  DocumentUri uri;
  std::optional<CreateFileOptions> options;
  std::optional<ChangeAnnotationIdentifier> annotation_id;

  CreateFile() = default;

  explicit CreateFile(
      DocumentUri uri, std::optional<CreateFileOptions> options,
      std::optional<ChangeAnnotationIdentifier> annotation_id)
      : uri(std::move(uri)),
        options(std::move(options)),
        annotation_id(std::move(annotation_id)) {
  }
};

struct RenameFileOptions {
  std::optional<bool> overwrite;
  std::optional<bool> ignore_if_exists;

  RenameFileOptions() = default;

  explicit RenameFileOptions(
      std::optional<bool> overwrite, std::optional<bool> ignore_if_exists)
      : overwrite(overwrite), ignore_if_exists(ignore_if_exists) {
  }
};

struct RenameFile {
  std::string kind = "rename";
  DocumentUri old_uri;
  DocumentUri new_uri;
  std::optional<RenameFileOptions> options;
  std::optional<ChangeAnnotationIdentifier> annotation_id;

  RenameFile() = default;

  explicit RenameFile(
      DocumentUri old_uri, DocumentUri new_uri,
      std::optional<RenameFileOptions> options,
      std::optional<ChangeAnnotationIdentifier> annotation_id)
      : old_uri(std::move(old_uri)),
        new_uri(std::move(new_uri)),
        options(std::move(options)),
        annotation_id(std::move(annotation_id)) {
  }
};

struct DeleteFileOptions {
  std::optional<bool> recursive;
  std::optional<bool> ignore_if_not_exists;

  DeleteFileOptions() = default;

  explicit DeleteFileOptions(
      std::optional<bool> recursive, std::optional<bool> ignore_if_not_exists)
      : recursive(recursive), ignore_if_not_exists(ignore_if_not_exists) {
  }
};

struct DeleteFile {
  std::string kind = "delete";
  DocumentUri uri;
  std::optional<DeleteFileOptions> options;
  std::optional<ChangeAnnotationIdentifier> annotation_id;

  DeleteFile() = default;

  explicit DeleteFile(
      DocumentUri uri, std::optional<DeleteFileOptions> options,
      std::optional<ChangeAnnotationIdentifier> annotation_id)
      : uri(std::move(uri)),
        options(std::move(options)),
        annotation_id(std::move(annotation_id)) {
  }
};

// Workspace Edit
enum class ResourceOperationKind { kCreate, kRename, kDelete };

enum class FailureHandlingKind {
  kAbort,
  kTransactional,
  kUndo,
  kTextOnlyTransactional
};

struct WorkspaceEdit {
  std::optional<std::map<DocumentUri, std::vector<TextEdit>>> changes;
  std::optional<std::variant<
      std::vector<TextDocumentEdit>,
      std::vector<
          std::variant<TextDocumentEdit, CreateFile, RenameFile, DeleteFile>>>>
      document_changes;
  std::optional<std::map<std::string, ChangeAnnotation>> change_annotations;

  WorkspaceEdit() = default;

  explicit WorkspaceEdit(
      std::optional<std::map<DocumentUri, std::vector<TextEdit>>> changes,
      std::optional<std::variant<
          std::vector<TextDocumentEdit>,
          std::vector<std::variant<
              TextDocumentEdit, CreateFile, RenameFile, DeleteFile>>>>
          document_changes,
      std::optional<std::map<std::string, ChangeAnnotation>> change_annotations)
      : changes(std::move(changes)),
        document_changes(std::move(document_changes)),
        change_annotations(std::move(change_annotations)) {
  }
};

struct WorkspaceEditClientCapabilities {
  std::optional<bool> document_changes;
  std::optional<std::vector<ResourceOperationKind>> resource_operations;
  std::optional<FailureHandlingKind> failure_handling;
  std::optional<bool> normalizes_line_endings;
  std::optional<std::map<std::string, bool>> change_annotation_support;

  WorkspaceEditClientCapabilities() = default;

  explicit WorkspaceEditClientCapabilities(
      std::optional<bool> document_changes,
      std::optional<std::vector<ResourceOperationKind>> resource_operations,
      std::optional<FailureHandlingKind> failure_handling,
      std::optional<bool> normalizes_line_endings,
      std::optional<std::map<std::string, bool>> change_annotation_support =
          std::nullopt)
      : document_changes(document_changes),
        resource_operations(std::move(resource_operations)),
        failure_handling(failure_handling),
        normalizes_line_endings(normalizes_line_endings),
        change_annotation_support(std::move(change_annotation_support)) {
  }
};

// Work Done Progress
struct WorkDoneProgressBegin {
  std::string kind = "begin";
  std::string title;
  std::optional<bool> cancellable;
  std::optional<std::string> message;
  std::optional<Uinteger> percentage;

  WorkDoneProgressBegin() = default;

  explicit WorkDoneProgressBegin(
      std::string title, std::optional<bool> cancellable,
      std::optional<std::string> message, std::optional<Uinteger> percentage)
      : title(std::move(title)),
        cancellable(cancellable),
        message(std::move(message)),
        percentage(percentage) {
  }
};

struct WorkDoneProgressReport {
  std::string kind = "report";
  std::optional<bool> cancellable;
  std::optional<std::string> message;
  std::optional<Uinteger> percentage;

  WorkDoneProgressReport() = default;

  explicit WorkDoneProgressReport(
      std::optional<bool> cancellable, std::optional<std::string> message,
      std::optional<Uinteger> percentage)
      : cancellable(cancellable),
        message(std::move(message)),
        percentage(percentage) {
  }
};

struct WorkDoneProgressEnd {
  std::string kind = "end";
  std::optional<std::string> message;

  WorkDoneProgressEnd() = default;

  explicit WorkDoneProgressEnd(std::optional<std::string> message)
      : message(std::move(message)) {
  }
};

struct WorkDoneProgressParams {
  std::optional<ProgressToken> work_done_token;

  WorkDoneProgressParams() = default;

  explicit WorkDoneProgressParams(std::optional<ProgressToken> work_done_token)
      : work_done_token(std::move(work_done_token)) {
  }
};

struct WorkDoneProgressOptions {
  std::optional<bool> work_done_progress;

  WorkDoneProgressOptions() = default;

  explicit WorkDoneProgressOptions(std::optional<bool> work_done_progress)
      : work_done_progress(work_done_progress) {
  }
};

// Partial Result Params
struct PartialResultParams {
  std::optional<ProgressToken> partial_result_token;

  PartialResultParams() = default;

  explicit PartialResultParams(
      std::optional<ProgressToken> partial_result_token)
      : partial_result_token(std::move(partial_result_token)) {
  }
};

// Trace Value
enum class TraceValue { kOff, kMessages, kVerbose };

// JSON Serialization
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
    RegularExpressionsClientCapabilities, engine, version);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Position, line, character);

}  // namespace lsp::types

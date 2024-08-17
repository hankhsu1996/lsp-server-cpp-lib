#pragma once

#include <cstdint>
#include <lsp/types/base.hpp>
#include <optional>
#include <string>

#include "lsp/protocol/navigation.hpp"
#include "lsp/protocol/text_document.hpp"
#include "lsp/types/basic.hpp"

namespace lsp::protocol {

using lsp::types::DocumentUri;
using lsp::types::LSPAny;
using lsp::types::TraceValue;
using lsp::types::WorkDoneProgressParams;
using lsp::types::WorkspaceEditClientCapabilities;

// Forward declarations
struct ClientCapabilities;
struct ServerCapabilities;

// Placeholders
struct WorkspaceFolder {};
struct CompletionClientCapabilities {};
struct HoverClientCapabilities {};
struct SignatureHelpClientCapabilities {};
struct DocumentHighlightClientCapabilities {};
struct DocumentSymbolClientCapabilities {};
struct CodeActionClientCapabilities {};
struct CodeLensClientCapabilities {};
struct DocumentLinkClientCapabilities {};
struct DocumentColorClientCapabilities {};
struct DocumentFormattingClientCapabilities {};
struct DocumentRangeFormattingClientCapabilities {};
struct DocumentOnTypeFormattingClientCapabilities {};
struct RenameClientCapabilities {};
struct PublishDiagnosticsClientCapabilities {};
struct FoldingRangeClientCapabilities {};
struct SelectionRangeClientCapabilities {};
struct LinkedEditingRangeClientCapabilities {};
struct CallHierarchyClientCapabilities {};
struct SemanticTokensClientCapabilities {};
struct MonikerClientCapabilities {};
struct TypeHierarchyClientCapabilities {};
struct InlineValueClientCapabilities {};
struct InlayHintClientCapabilities {};
struct DiagnosticClientCapabilities {};
struct DidChangeConfigurationClientCapabilities {};
struct DidChangeWatchedFilesClientCapabilities {};
struct WorkspaceSymbolClientCapabilities {};
struct ExecuteCommandClientCapabilities {};
struct SemanticTokensWorkspaceClientCapabilities {};
struct CodeLensWorkspaceClientCapabilities {};
struct InlineValueWorkspaceClientCapabilities {};
struct InlayHintWorkspaceClientCapabilities {};
struct DiagnosticWorkspaceClientCapabilities {};
struct NotebookDocumentSyncClientCapabilities {};
struct ShowMessageRequestClientCapabilities {};
struct ShowDocumentClientCapabilities {};
struct RegularExpressionsClientCapabilities {};
struct MarkdownClientCapabilities {};
struct PositionEncodingKind {};
struct FileOperationRegistrationOptions {};
struct WorkspaceFolderServerCapabilities {};
struct NotebookDocumentSyncOptions {};
struct NotebookDocumentSyncRegistrationOptions {};
struct CompletionOptions {};
struct HoverOptions {};
struct SignatureHelpOptions {};
struct DocumentHighlightOptions {};
struct DocumentSymbolOptions {};
struct CodeActionOptions {};
struct CodeLensOptions {};
struct DocumentLinkOptions {};
struct DocumentColorOptions {};
struct DocumentColorRegistrationOptions {};
struct DocumentFormattingOptions {};
struct DocumentRangeFormattingOptions {};
struct DocumentOnTypeFormattingOptions {};
struct RenameOptions {};
struct FoldingRangeOptions {};
struct FoldingRangeRegistrationOptions {};
struct ExecuteCommandOptions {};
struct SelectionRangeOptions {};
struct SelectionRangeRegistrationOptions {};
struct LinkedEditingRangeOptions {};
struct LinkedEditingRangeRegistrationOptions {};
struct CallHierarchyOptions {};
struct CallHierarchyRegistrationOptions {};
struct SemanticTokensOptions {};
struct SemanticTokensRegistrationOptions {};
struct MonikerOptions {};
struct MonikerRegistrationOptions {};
struct TypeHierarchyOptions {};
struct TypeHierarchyRegistrationOptions {};
struct InlineValueOptions {};
struct InlineValueRegistrationOptions {};
struct InlayHintOptions {};
struct InlayHintRegistrationOptions {};
struct DiagnosticOptions {};
struct DiagnosticRegistrationOptions {};
struct WorkspaceSymbolOptions {};

// Initialize Request
struct TextDocumentClientCapabilities {
  std::optional<TextDocumentSyncClientCapabilities> synchronization;
  std::optional<CompletionClientCapabilities> completion;
  std::optional<HoverClientCapabilities> hover;
  std::optional<SignatureHelpClientCapabilities> signature_help;
  std::optional<DeclarationClientCapabilities> declaration;
  std::optional<DefinitionClientCapabilities> definition;
  std::optional<TypeDefinitionClientCapabilities> type_definition;
  std::optional<ImplementationClientCapabilities> implementation;
  std::optional<ReferenceClientCapabilities> references;
  std::optional<DocumentHighlightClientCapabilities> document_highlight;
  std::optional<DocumentSymbolClientCapabilities> document_symbol;
  std::optional<CodeActionClientCapabilities> code_action;
  std::optional<CodeLensClientCapabilities> code_lens;
  std::optional<DocumentLinkClientCapabilities> document_link;
  std::optional<DocumentColorClientCapabilities> color_provider;
  std::optional<DocumentFormattingClientCapabilities> formatting;
  std::optional<DocumentRangeFormattingClientCapabilities> range_formatting;
  std::optional<DocumentOnTypeFormattingClientCapabilities> on_type_formatting;
  std::optional<RenameClientCapabilities> rename;
  std::optional<PublishDiagnosticsClientCapabilities> publish_diagnostics;
  std::optional<FoldingRangeClientCapabilities> folding_range;
  std::optional<SelectionRangeClientCapabilities> selection_range;
  std::optional<LinkedEditingRangeClientCapabilities> linked_editing_range;
  std::optional<CallHierarchyClientCapabilities> call_hierarchy;
  std::optional<SemanticTokensClientCapabilities> semantic_tokens;
  std::optional<MonikerClientCapabilities> moniker;
  std::optional<TypeHierarchyClientCapabilities> type_hierarchy;
  std::optional<InlineValueClientCapabilities> inline_value;
  std::optional<InlayHintClientCapabilities> inlay_hint;
  std::optional<DiagnosticClientCapabilities> diagnostic;

  TextDocumentClientCapabilities() = default;

  explicit TextDocumentClientCapabilities(
      std::optional<TextDocumentSyncClientCapabilities> synchronization,
      std::optional<CompletionClientCapabilities> completion,
      std::optional<HoverClientCapabilities> hover,
      std::optional<SignatureHelpClientCapabilities> signature_help,
      std::optional<DeclarationClientCapabilities> declaration,
      std::optional<DefinitionClientCapabilities> definition,
      std::optional<TypeDefinitionClientCapabilities> type_definition,
      std::optional<ImplementationClientCapabilities> implementation,
      std::optional<ReferenceClientCapabilities> references,
      std::optional<DocumentHighlightClientCapabilities> document_highlight,
      std::optional<DocumentSymbolClientCapabilities> document_symbol,
      std::optional<CodeActionClientCapabilities> code_action,
      std::optional<CodeLensClientCapabilities> code_lens,
      std::optional<DocumentLinkClientCapabilities> document_link,
      std::optional<DocumentColorClientCapabilities> color_provider,
      std::optional<DocumentFormattingClientCapabilities> formatting,
      std::optional<DocumentRangeFormattingClientCapabilities> range_formatting,
      std::optional<DocumentOnTypeFormattingClientCapabilities>
          on_type_formatting,
      std::optional<RenameClientCapabilities> rename,
      std::optional<PublishDiagnosticsClientCapabilities> publish_diagnostics,
      std::optional<FoldingRangeClientCapabilities> folding_range,
      std::optional<SelectionRangeClientCapabilities> selection_range,
      std::optional<LinkedEditingRangeClientCapabilities> linked_editing_range,
      std::optional<CallHierarchyClientCapabilities> call_hierarchy,
      std::optional<SemanticTokensClientCapabilities> semantic_tokens,
      std::optional<MonikerClientCapabilities> moniker,
      std::optional<TypeHierarchyClientCapabilities> type_hierarchy,
      std::optional<InlineValueClientCapabilities> inline_value,
      std::optional<InlayHintClientCapabilities> inlay_hint,
      std::optional<DiagnosticClientCapabilities> diagnostic)
      : synchronization(std::move(synchronization)),
        completion(std::move(completion)),
        hover(std::move(hover)),
        signature_help(std::move(signature_help)),
        declaration(std::move(declaration)),
        definition(std::move(definition)),
        type_definition(std::move(type_definition)),
        implementation(std::move(implementation)),
        references(std::move(references)),
        document_highlight(std::move(document_highlight)),
        document_symbol(std::move(document_symbol)),
        code_action(std::move(code_action)),
        code_lens(std::move(code_lens)),
        document_link(std::move(document_link)),
        color_provider(std::move(color_provider)),
        formatting(std::move(formatting)),
        range_formatting(std::move(range_formatting)),
        on_type_formatting(std::move(on_type_formatting)),
        rename(std::move(rename)),
        publish_diagnostics(std::move(publish_diagnostics)),
        folding_range(std::move(folding_range)),
        selection_range(std::move(selection_range)),
        linked_editing_range(std::move(linked_editing_range)),
        call_hierarchy(std::move(call_hierarchy)),
        semantic_tokens(std::move(semantic_tokens)),
        moniker(std::move(moniker)),
        type_hierarchy(std::move(type_hierarchy)),
        inline_value(std::move(inline_value)),
        inlay_hint(std::move(inlay_hint)),
        diagnostic(std::move(diagnostic)) {
  }
};

struct NotebookDocumentClientCapabilities {
  NotebookDocumentSyncClientCapabilities synchronization;

  NotebookDocumentClientCapabilities() = default;

  explicit NotebookDocumentClientCapabilities(
      NotebookDocumentSyncClientCapabilities synchronization)
      : synchronization(std::move(synchronization)) {
  }
};

struct FileOperationsClientCapabilities {
  std::optional<bool> dynamic_registration;
  std::optional<bool> did_create;
  std::optional<bool> will_create;
  std::optional<bool> did_rename;
  std::optional<bool> will_rename;
  std::optional<bool> did_delete;
  std::optional<bool> will_delete;

  FileOperationsClientCapabilities() = default;

  explicit FileOperationsClientCapabilities(
      std::optional<bool> dynamic_registration = std::nullopt,
      std::optional<bool> did_create = std::nullopt,
      std::optional<bool> will_create = std::nullopt,
      std::optional<bool> did_rename = std::nullopt,
      std::optional<bool> will_rename = std::nullopt,
      std::optional<bool> did_delete = std::nullopt,
      std::optional<bool> will_delete = std::nullopt)
      : dynamic_registration(dynamic_registration),
        did_create(did_create),
        will_create(will_create),
        did_rename(did_rename),
        will_rename(will_rename),
        did_delete(did_delete),
        will_delete(will_delete) {
  }
};

struct WorkspaceClientCapabilities {
  std::optional<bool> apply_edit;
  std::optional<WorkspaceEditClientCapabilities> workspace_edit;
  std::optional<DidChangeConfigurationClientCapabilities>
      did_change_configuration;
  std::optional<DidChangeWatchedFilesClientCapabilities>
      did_change_watched_files;
  std::optional<WorkspaceSymbolClientCapabilities> symbol;
  std::optional<ExecuteCommandClientCapabilities> execute_command;
  std::optional<bool> workspace_folders;
  std::optional<bool> configuration;
  std::optional<SemanticTokensWorkspaceClientCapabilities> semantic_tokens;
  std::optional<CodeLensWorkspaceClientCapabilities> code_lens;
  std::optional<FileOperationsClientCapabilities> file_operations;
  std::optional<InlineValueWorkspaceClientCapabilities> inline_value;
  std::optional<InlayHintWorkspaceClientCapabilities> inlay_hint;
  std::optional<DiagnosticWorkspaceClientCapabilities> diagnostics;

  WorkspaceClientCapabilities() = default;

  explicit WorkspaceClientCapabilities(
      std::optional<bool> apply_edit,
      std::optional<WorkspaceEditClientCapabilities> workspace_edit,
      std::optional<DidChangeConfigurationClientCapabilities>
          did_change_configuration,
      std::optional<DidChangeWatchedFilesClientCapabilities>
          did_change_watched_files,
      std::optional<WorkspaceSymbolClientCapabilities> symbol,
      std::optional<ExecuteCommandClientCapabilities> execute_command,
      std::optional<bool> workspace_folders, std::optional<bool> configuration,
      std::optional<SemanticTokensWorkspaceClientCapabilities> semantic_tokens,
      std::optional<CodeLensWorkspaceClientCapabilities> code_lens,
      std::optional<FileOperationsClientCapabilities> file_operations,
      std::optional<InlineValueWorkspaceClientCapabilities> inline_value,
      std::optional<InlayHintWorkspaceClientCapabilities> inlay_hint,
      std::optional<DiagnosticWorkspaceClientCapabilities> diagnostics)
      : apply_edit(apply_edit),
        workspace_edit(std::move(workspace_edit)),
        did_change_configuration(std::move(did_change_configuration)),
        did_change_watched_files(std::move(did_change_watched_files)),
        symbol(std::move(symbol)),
        execute_command(std::move(execute_command)),
        workspace_folders(workspace_folders),
        configuration(configuration),
        semantic_tokens(std::move(semantic_tokens)),
        code_lens(std::move(code_lens)),
        file_operations(std::move(file_operations)),
        inline_value(std::move(inline_value)),
        inlay_hint(std::move(inlay_hint)),
        diagnostics(std::move(diagnostics)) {};
};

struct WindowClientCapabilities {
  std::optional<bool> work_done_progress;
  std::optional<ShowMessageRequestClientCapabilities> show_message;
  std::optional<ShowDocumentClientCapabilities> show_document;

  WindowClientCapabilities() = default;

  explicit WindowClientCapabilities(
      std::optional<bool> work_done_progress,
      std::optional<ShowMessageRequestClientCapabilities> show_message,
      std::optional<ShowDocumentClientCapabilities> show_document)
      : work_done_progress(work_done_progress),
        show_message(std::move(show_message)),
        show_document(std::move(show_document)) {
  }
};

struct StaleRequestSupportClientCapabilities {
  bool cancel{};
  std::vector<std::string> retry_on_content_modified;

  StaleRequestSupportClientCapabilities() = default;

  explicit StaleRequestSupportClientCapabilities(
      bool cancel, std::vector<std::string> retry_on_content_modified)
      : cancel(cancel),
        retry_on_content_modified(std::move(retry_on_content_modified)) {
  }
};

struct GeneralClientCapabilities {
  std::optional<StaleRequestSupportClientCapabilities> stale_request_support;
  std::optional<RegularExpressionsClientCapabilities> regular_expressions;
  std::optional<MarkdownClientCapabilities> markdown;
  std::optional<std::vector<PositionEncodingKind>> position_encodings;

  GeneralClientCapabilities() = default;

  explicit GeneralClientCapabilities(
      std::optional<StaleRequestSupportClientCapabilities>
          stale_request_support,
      std::optional<RegularExpressionsClientCapabilities> regular_expressions,
      std::optional<MarkdownClientCapabilities> markdown,
      std::optional<std::vector<PositionEncodingKind>> position_encodings)
      : stale_request_support(std::move(stale_request_support)),
        regular_expressions(std::move(regular_expressions)),
        markdown(std::move(markdown)),
        position_encodings(std::move(position_encodings)) {
  }
};

struct ClientCapabilities {
  std::optional<WorkspaceClientCapabilities> workspace;
  std::optional<TextDocumentClientCapabilities> text_document;
  std::optional<NotebookDocumentClientCapabilities> notebook_document;
  std::optional<WindowClientCapabilities> window;
  std::optional<GeneralClientCapabilities> general;
  std::optional<LSPAny> experimental;

  ClientCapabilities() = default;

  explicit ClientCapabilities(
      std::optional<WorkspaceClientCapabilities> workspace,
      std::optional<TextDocumentClientCapabilities> text_document,
      std::optional<NotebookDocumentClientCapabilities> notebook_document,
      std::optional<WindowClientCapabilities> window,
      std::optional<GeneralClientCapabilities> general,
      std::optional<LSPAny> experimental)
      : workspace(std::move(workspace)),
        text_document(std::move(text_document)),
        notebook_document(std::move(notebook_document)),
        window(std::move(window)),
        general(std::move(general)),
        experimental(std::move(experimental)) {
  }
};

struct ClientInfo {
  std::string name;
  std::optional<std::string> version;

  ClientInfo() = default;

  explicit ClientInfo(std::string name, std::optional<std::string> version)
      : name(std::move(name)), version(std::move(version)) {
  }
};

struct InitializeParams : public WorkDoneProgressParams {
  std::optional<std::int32_t> process_id;
  std::optional<ClientInfo> client_info;
  std::optional<std::string> locale;
  std::optional<std::string> root_path;
  std::optional<DocumentUri> root_uri;
  std::optional<LSPAny> initialization_options;
  ClientCapabilities capabilities;
  std::optional<TraceValue> trace;
  std::optional<std::vector<WorkspaceFolder>> workspace_folders;

  InitializeParams() = default;

  explicit InitializeParams(
      std::optional<std::int32_t> process_id,
      std::optional<ClientInfo> client_info, std::optional<std::string> locale,
      std::optional<std::string> root_path, std::optional<DocumentUri> root_uri,
      std::optional<LSPAny> initialization_options,
      ClientCapabilities capabilities, std::optional<TraceValue> trace,
      std::optional<std::vector<WorkspaceFolder>> workspace_folders)
      : process_id(std::move(process_id)),
        client_info(std::move(client_info)),
        locale(std::move(locale)),
        root_path(std::move(root_path)),
        root_uri(std::move(root_uri)),
        initialization_options(std::move(initialization_options)),
        capabilities(std::move(capabilities)),
        trace(std::move(trace)),
        workspace_folders(std::move(workspace_folders)) {
  }
};

// Initialize Response
struct FileOperationServerCapabilities {
  std::optional<FileOperationRegistrationOptions> did_create;
  std::optional<FileOperationRegistrationOptions> will_create;
  std::optional<FileOperationRegistrationOptions> did_rename;
  std::optional<FileOperationRegistrationOptions> will_rename;
  std::optional<FileOperationRegistrationOptions> did_delete;
  std::optional<FileOperationRegistrationOptions> will_delete;

  FileOperationServerCapabilities() = default;

  explicit FileOperationServerCapabilities(
      std::optional<FileOperationRegistrationOptions> did_create,
      std::optional<FileOperationRegistrationOptions> will_create,
      std::optional<FileOperationRegistrationOptions> did_rename,
      std::optional<FileOperationRegistrationOptions> will_rename,
      std::optional<FileOperationRegistrationOptions> did_delete,
      std::optional<FileOperationRegistrationOptions> will_delete)
      : did_create(std::move(did_create)),
        will_create(std::move(will_create)),
        did_rename(std::move(did_rename)),
        will_rename(std::move(will_rename)),
        did_delete(std::move(did_delete)),
        will_delete(std::move(will_delete)) {
  }
};

struct WorkspaceServerCapabilities {
  std::optional<WorkspaceFolderServerCapabilities> workspace_folders;
  std::optional<FileOperationServerCapabilities> file_operations;

  WorkspaceServerCapabilities() = default;

  explicit WorkspaceServerCapabilities(
      std::optional<WorkspaceFolderServerCapabilities> workspace_folders,
      std::optional<FileOperationServerCapabilities> file_operations)
      : workspace_folders(std::move(workspace_folders)),
        file_operations(std::move(file_operations)) {
  }
};

struct ServerCapabilities {
  std::optional<PositionEncodingKind> position_encoding;
  std::optional<std::variant<TextDocumentSyncOptions, TextDocumentSyncKind>>
      text_document_sync;
  std::optional<std::variant<
      NotebookDocumentSyncOptions, NotebookDocumentSyncRegistrationOptions>>
      notebook_document_sync;
  std::optional<CompletionOptions> completion_provider;
  std::optional<std::variant<bool, HoverOptions>> hover_provider;
  std::optional<SignatureHelpOptions> signature_help_provider;
  std::optional<
      std::variant<bool, DeclarationOptions, DeclarationRegistrationOptions>>
      declaration_provider;
  std::optional<std::variant<bool, DefinitionOptions>> definition_provider;
  std::optional<std::variant<
      bool, TypeDefinitionOptions, TypeDefinitionRegistrationOptions>>
      type_definition_provider;
  std::optional<std::variant<
      bool, ImplementationOptions, ImplementationRegistrationOptions>>
      implementation_provider;
  std::optional<std::variant<bool, ReferenceOptions>> references_provider;
  std::optional<std::variant<bool, DocumentHighlightOptions>>
      document_highlight_provider;
  std::optional<std::variant<bool, DocumentSymbolOptions>>
      document_symbol_provider;
  std::optional<std::variant<bool, CodeActionOptions>> code_action_provider;
  std::optional<CodeLensOptions> code_lens_provider;
  std::optional<DocumentLinkOptions> document_link_provider;
  std::optional<std::variant<
      bool, DocumentColorOptions, DocumentColorRegistrationOptions>>
      color_provider;
  std::optional<std::variant<bool, DocumentFormattingOptions>>
      document_formatting_provider;
  std::optional<std::variant<bool, DocumentRangeFormattingOptions>>
      document_range_formatting_provider;
  std::optional<DocumentOnTypeFormattingOptions>
      document_on_type_formatting_provider;
  std::optional<std::variant<bool, RenameOptions>> rename_provider;
  std::optional<
      std::variant<bool, FoldingRangeOptions, FoldingRangeRegistrationOptions>>
      folding_range_provider;
  std::optional<ExecuteCommandOptions> execute_command_provider;
  std::optional<std::variant<
      bool, SelectionRangeOptions, SelectionRangeRegistrationOptions>>
      selection_range_provider;
  std::optional<std::variant<
      bool, LinkedEditingRangeOptions, LinkedEditingRangeRegistrationOptions>>
      linked_editing_range_provider;
  std::optional<std::variant<
      bool, CallHierarchyOptions, CallHierarchyRegistrationOptions>>
      call_hierarchy_provider;
  std::optional<
      std::variant<SemanticTokensOptions, SemanticTokensRegistrationOptions>>
      semantic_tokens_provider;
  std::optional<std::variant<bool, MonikerOptions, MonikerRegistrationOptions>>
      moniker_provider;
  std::optional<std::variant<
      bool, TypeHierarchyOptions, TypeHierarchyRegistrationOptions>>
      type_hierarchy_provider;
  std::optional<
      std::variant<bool, InlineValueOptions, InlineValueRegistrationOptions>>
      inline_value_provider;
  std::optional<
      std::variant<bool, InlayHintOptions, InlayHintRegistrationOptions>>
      inlay_hint_provider;
  std::optional<std::variant<DiagnosticOptions, DiagnosticRegistrationOptions>>
      diagnostic_provider;
  std::optional<std::variant<bool, WorkspaceSymbolOptions>>
      workspace_symbol_provider;
  std::optional<WorkspaceServerCapabilities> workspace;
  std::optional<LSPAny> experimental;

  ServerCapabilities() = default;

  explicit ServerCapabilities(
      std::optional<PositionEncodingKind> position_encoding,
      std::optional<std::variant<TextDocumentSyncOptions, TextDocumentSyncKind>>
          text_document_sync,
      std::optional<std::variant<
          NotebookDocumentSyncOptions, NotebookDocumentSyncRegistrationOptions>>
          notebook_document_sync,
      std::optional<CompletionOptions> completion_provider,
      std::optional<std::variant<bool, HoverOptions>> hover_provider,
      std::optional<SignatureHelpOptions> signature_help_provider,
      std::optional<std::variant<
          bool, DeclarationOptions, DeclarationRegistrationOptions>>
          declaration_provider,
      std::optional<std::variant<bool, DefinitionOptions>> definition_provider,
      std::optional<std::variant<
          bool, TypeDefinitionOptions, TypeDefinitionRegistrationOptions>>
          type_definition_provider,
      std::optional<std::variant<
          bool, ImplementationOptions, ImplementationRegistrationOptions>>
          implementation_provider,
      std::optional<std::variant<bool, ReferenceOptions>> references_provider,
      std::optional<std::variant<bool, DocumentHighlightOptions>>
          document_highlight_provider,
      std::optional<std::variant<bool, DocumentSymbolOptions>>
          document_symbol_provider,
      std::optional<std::variant<bool, CodeActionOptions>> code_action_provider,
      std::optional<CodeLensOptions> code_lens_provider,
      std::optional<DocumentLinkOptions> document_link_provider,
      std::optional<std::variant<
          bool, DocumentColorOptions, DocumentColorRegistrationOptions>>
          color_provider,
      std::optional<std::variant<bool, DocumentFormattingOptions>>
          document_formatting_provider,
      std::optional<std::variant<bool, DocumentRangeFormattingOptions>>
          document_range_formatting_provider,
      std::optional<DocumentOnTypeFormattingOptions>
          document_on_type_formatting_provider,
      std::optional<std::variant<bool, RenameOptions>> rename_provider,
      std::optional<std::variant<
          bool, FoldingRangeOptions, FoldingRangeRegistrationOptions>>
          folding_range_provider,
      std::optional<ExecuteCommandOptions> execute_command_provider,
      std::optional<std::variant<
          bool, SelectionRangeOptions, SelectionRangeRegistrationOptions>>
          selection_range_provider,
      std::optional<std::variant<
          bool, LinkedEditingRangeOptions,
          LinkedEditingRangeRegistrationOptions>>
          linked_editing_range_provider,
      std::optional<std::variant<
          bool, CallHierarchyOptions, CallHierarchyRegistrationOptions>>
          call_hierarchy_provider,
      std::optional<std::variant<
          SemanticTokensOptions, SemanticTokensRegistrationOptions>>
          semantic_tokens_provider,
      std::optional<
          std::variant<bool, MonikerOptions, MonikerRegistrationOptions>>
          moniker_provider,
      std::optional<std::variant<
          bool, TypeHierarchyOptions, TypeHierarchyRegistrationOptions>>
          type_hierarchy_provider,
      std::optional<std::variant<
          bool, InlineValueOptions, InlineValueRegistrationOptions>>
          inline_value_provider,
      std::optional<
          std::variant<bool, InlayHintOptions, InlayHintRegistrationOptions>>
          inlay_hint_provider,
      std::optional<
          std::variant<DiagnosticOptions, DiagnosticRegistrationOptions>>
          diagnostic_provider,
      std::optional<std::variant<bool, WorkspaceSymbolOptions>>
          workspace_symbol_provider,
      std::optional<WorkspaceServerCapabilities> workspace,
      std::optional<LSPAny> experimental)
      : position_encoding(std::move(position_encoding)),
        text_document_sync(std::move(text_document_sync)),
        notebook_document_sync(std::move(notebook_document_sync)),
        completion_provider(std::move(completion_provider)),
        hover_provider(std::move(hover_provider)),
        signature_help_provider(std::move(signature_help_provider)),
        declaration_provider(std::move(declaration_provider)),
        definition_provider(std::move(definition_provider)),
        type_definition_provider(std::move(type_definition_provider)),
        implementation_provider(std::move(implementation_provider)),
        references_provider(std::move(references_provider)),
        document_highlight_provider(std::move(document_highlight_provider)),
        document_symbol_provider(std::move(document_symbol_provider)),
        code_action_provider(std::move(code_action_provider)),
        code_lens_provider(std::move(code_lens_provider)),
        document_link_provider(std::move(document_link_provider)),
        color_provider(std::move(color_provider)),
        document_formatting_provider(std::move(document_formatting_provider)),
        document_range_formatting_provider(
            std::move(document_range_formatting_provider)),
        document_on_type_formatting_provider(
            std::move(document_on_type_formatting_provider)),
        rename_provider(std::move(rename_provider)),
        folding_range_provider(std::move(folding_range_provider)),
        execute_command_provider(std::move(execute_command_provider)),
        selection_range_provider(std::move(selection_range_provider)),
        linked_editing_range_provider(std::move(linked_editing_range_provider)),
        call_hierarchy_provider(std::move(call_hierarchy_provider)),
        semantic_tokens_provider(std::move(semantic_tokens_provider)),
        moniker_provider(std::move(moniker_provider)),
        type_hierarchy_provider(std::move(type_hierarchy_provider)),
        inline_value_provider(std::move(inline_value_provider)),
        inlay_hint_provider(std::move(inlay_hint_provider)),
        diagnostic_provider(std::move(diagnostic_provider)),
        workspace_symbol_provider(std::move(workspace_symbol_provider)),
        workspace(std::move(workspace)),
        experimental(std::move(experimental)) {
  }
};

struct ServerInfo {
  std::string name;
  std::optional<std::string> version;

  ServerInfo() = default;

  explicit ServerInfo(std::string name, std::optional<std::string> version)
      : name(std::move(name)), version(std::move(version)) {
  }
};

struct InitializeResult {
  ServerCapabilities capabilities;
  std::optional<ServerInfo> server_info;

  InitializeResult() = default;

  explicit InitializeResult(
      ServerCapabilities capabilities, std::optional<ServerInfo> server_info)
      : capabilities(std::move(capabilities)),
        server_info(std::move(server_info)) {
  }
};

enum class InitializeErrorCodes {
  kUnknownProtocolVersion = 1,
};

struct InitializeError {
  bool retry;

  InitializeError() = default;

  explicit InitializeError(bool retry) : retry(retry) {
  }
};

}  // namespace lsp::protocol

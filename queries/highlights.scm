; -------
; Tree-Sitter doesn't allow overrides in regards to captures,
; though it is possible to affect the child node of a captured
; node. Thus, the approach here is to flip the order so that
; overrides are unnecessary.
; -------

; -------
; Types
; -------

(type_annotation) @type
(dimension_expr) @type

; ---
; Primitives
; ---

; (escape_sequence) @constant.character.escape
(string) @string
(boolean) @constant.builtin.boolean
(number) @constant.numeric
(line_comment) @comment.line

; ---
; Punctuation
; ---

[
  "::"
  ","
] @punctuation.delimiter

[
  "("
  ")"
] @punctuation.bracket

(function_decl
  type_parameter:
  [
    "<"
    ">"
  ] @punctuation.bracket)

; ---
; Variables
; ---

(variable_decl
  name: ((identifier) @variable))

; -------
; Keywords
; -------

[
  "if"
  "then"
  "else"
] @keyword.control.conditional

"use" @keyword.control.import

[
  "dimension"
  "unit"
] @keyword.storage.type

"let" @keyword.storage
"fn" @keyword.function

; -------
; Functions
; -------

(call
  name: ((identifier) @function))

(function_decl
  name: ((identifier) @function))

(procedure_call
  [
    "print"
    "assert_eq"
    "type"
  ] @function.builtin
)

; ---
; Macros
; ---

(decorator
  [
    "@"
    "metric_prefixes"
    "binary_prefixes"
    "aliases"
  ] @function.macro 
)

; (attribute
;   (identifier) @special
;   arguments: (token_tree (identifier) @type)
;   (#eq? @special "derive")
; )

; (attribute
;   (identifier) @function.macro)
; (attribute
;   [
;     (identifier) @function.macro
;     (scoped_identifier
;       name: (identifier) @function.macro)
;   ]
;   (token_tree (identifier) @function.macro)?)

; (inner_attribute_item) @attribute

; (macro_definition
;   name: (identifier) @function.macro)
; (macro_invocation
;   macro: [
;     ((identifier) @function.macro)
;     (scoped_identifier
;       name: (identifier) @function.macro)
;   ]
;   "!" @function.macro)

; (metavariable) @variable.parameter
; (fragment_specifier) @type

; -------
; Operators
; -------

[
  (multiply)
  (minus)
  (plus)
  (divide)
  (pow_symbol)
  (unicode_exponent)
  "//"
  "=="
  "!"
  "!="
  "≠"
  "<="
  "≤"
  "<"
  ">="
  "≥"
  ">"
] @operator

; ; -------
; ; Paths
; ; -------

; (use_declaration
;   argument: (identifier) @namespace)
; (use_wildcard
;   (identifier) @namespace)
; (extern_crate_declaration
;   name: (identifier) @namespace)
; (mod_item
;   name: (identifier) @namespace)
; (scoped_use_list
;   path: (identifier)? @namespace)
; (use_list
;   (identifier) @namespace)
; (use_as_clause
;   path: (identifier)? @namespace
;   alias: (identifier) @namespace)

; ; ---
; ; Remaining Paths
; ; ---

; (scoped_identifier
;   path: (identifier)? @namespace
;   name: (identifier) @namespace)
; (scoped_type_identifier
;   path: (identifier) @namespace)

; ; -------
; ; Remaining Identifiers
; ; -------

; "?" @special

; (type_identifier) @type
; (identifier) @variable
; (field_identifier) @variable.other.member

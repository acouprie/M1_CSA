type token =
  | A
  | B
  | C
  | EOF

val sp :
  (Lexing.lexbuf  -> token) -> Lexing.lexbuf -> unit

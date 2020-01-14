type token =
  | A
  | B
  | EOF

val sp :
  (Lexing.lexbuf  -> token) -> Lexing.lexbuf -> unit

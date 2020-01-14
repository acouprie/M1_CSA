type token =
  | A
  | EOF

val sp :
  (Lexing.lexbuf  -> token) -> Lexing.lexbuf -> unit

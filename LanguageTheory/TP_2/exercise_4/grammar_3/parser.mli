type token =
  | A
  | B
  | C
  | D
  | EOF

val sp :
  (Lexing.lexbuf  -> token) -> Lexing.lexbuf -> unit

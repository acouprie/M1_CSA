(** prog.ml **)
(* first starts to read the standard input, lexbuf contains the current symbol *)
let lexbuf = Lexing.from_channel stdin in
(* Lexer.l0 calls the l0 rule in the lexer on lexbuf *)
let result = Lexer.l0 lexbuf (* finally prints the result *)
in print_string ("result of analysis : "^string_of_int result^"\n");

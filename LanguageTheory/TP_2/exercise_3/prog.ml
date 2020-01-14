let lexbuf = Lexing.from_channel stdin in
Parser.sp Lexer.main lexbuf

(** lexer.mll *)
{
(*** OCAML PART for tool functions ***)
(* convert char in int *)
let digit_of_char c = (int_of_char c - int_of_char '0')
}

(*** ANALYSER PART ***)
(** Lexical Unit(s) **)
let integer = ['0' - '9']

(** Rules **)
rule l0 = parse 
        | integer as i     { (*A1*) print_string ("A1 reads "^(Char.escaped i)^"\n");l1 lexbuf}
	| _    {failwith "erreur_l0" } (** to exit properly, or add another rule *)
and
l1  = parse
	| integer as i   { (*A2*) print_string ("A2 reads "^(Char.escaped i)^"\n"); l1 lexbuf }
	| '\n'   	{ (*A3*) print_string ("A3 reads eol"^"\n")}
	| eof	        { (*A3*) print_string ("A3 reads eof"^"\n")}
	|'$'		{ (*A4*) print_string ("A4 reads $"^"\n"); l2 lexbuf}
	| _    {failwith "error_l1" }
and 
l2 = parse
	| integer as i   { (*A5*) print_string ("A5 reads "^(Char.escaped i)^"\n"); l3 lexbuf}
	| _    {failwith "error_l2" }
and 
l3 = parse
	| integer as i   { (*A6*) print_string ("A6 reads "^(Char.escaped i)^"\n"); l3 lexbuf}
	| '\n'		{ (*A7*) print_string ("A7 reads eol"^"\n")}
	| eof	        { (*A7*) print_string ("A7 reads eof"^"\n")}
	| _    {failwith "error_l3" }

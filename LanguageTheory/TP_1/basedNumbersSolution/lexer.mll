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
        | integer as i     { (*A1*) print_string ("A1 reads "^(Char.escaped i)^"\n"); let vi = (digit_of_char i) in l1 vi lexbuf}
	| _    {failwith "error_l0" } (** to exit properly, or add another rule *)
and
l1  v = parse
	| integer as i   { (*A2*) print_string ("A2 reads "^(Char.escaped i)^"\n"); let vi = digit_of_char i in l1 (v*10+vi) lexbuf}
	| '\n'   	{ (*A3*) print_string ("A3 reads eol"^"\n"); v}
	| eof	        { (*A3*) print_string ("A3 reads eof"^"\n"); v}
	|'$'		{ (*A4*) print_string ("A4 reads $"^"\n");
	  if (v<2 || v>10) then failwith "error_base"
          else l2 v lexbuf }
	| _    {failwith "error_l1" }
and 
l2 b = parse
	| integer as i   { (*A5*) print_string ("A5 reads "^(Char.escaped i)^"\n"); let vi = digit_of_char i in
          if vi>b then failwith "error_chiffre"
          else l3 b vi lexbuf}
	| _    {failwith "error_l2" }
and 
l3 b v = parse
	| integer as i   { (*A6*) print_string ("A6 reads "^(Char.escaped i)^"\n");  let vi = digit_of_char i in
          if vi>b then failwith "error_chiffre"
          else l3 b (v*b+vi) lexbuf }
	| '\n'		{ (*A7*) print_string ("A7 reads eol"^"\n"); v}
	| eof	        { (*A7*) print_string ("A7 reads eof"^"\n"); v}
	| _    {failwith "error_l3" }

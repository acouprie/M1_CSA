(****** fichier lexer.mll : analyseur lexical ******)
{
(*** PARTIE OCAML de fonctions utiles ***)
(* conversion char en entier *)
let digit_of_char c = (int_of_char c - int_of_char '0')
let increment (number:int) : int = number + 1
}

(*** PARTIE ANALYSEUR ***)
(** Unite(s) lexicale(s) **)
let integer = ['0' - '9']
let minus = '-'
let plus = '+'
let zero = '0'

(** Regles **)
rule l0 = parse 
  | integer as i { (*A1*)
    l1 (digit_of_char i) lexbuf
  }
	| _ { failwith "erreur_l0" }
and
l1 base = parse
	| integer as i { (*A1*)
    l1 (base * 10 + (digit_of_char i)) lexbuf
  }
	|'$' { (*A2*) l2 base lexbuf }
	| _ { failwith "error_l1" }
and
l2 base = parse
  | zero { (*A3*) l3 base 1 lexbuf }
  | plus { (*A4*) l4 base 1 lexbuf }
  | minus { (*A5*) l5 base 1 lexbuf }
and
l3 base nb_operator = parse
  | zero { (*A3*) 
    let nb_operator = increment(nb_operator) in l3 base nb_operator lexbuf
  }
  | 'b' { (*A7*)
    for i = 1 to nb_operator do
      print_int(base);
      print_string(" ");
    done;
    l7 base 0 '_' 0 lexbuf;
  }
	| _ {failwith "error_l3" }
and
l4 base nb_operator = parse
  | plus { (*A4*) 
    let nb_operator = increment(nb_operator) in l4 base nb_operator lexbuf
  }
  | integer as i { (*A6*) 
    l6 base (digit_of_char i) '+' nb_operator lexbuf
  }
	| _ {failwith "error_l4" }
and
l5 base nb_operator = parse
  | minus { (*A5*) 
    let nb_operator = increment(nb_operator) in l5 base nb_operator lexbuf
  }
  | integer as i { (*A6*) 
    l6 base (digit_of_char i) '-' nb_operator lexbuf
  }
	| _ {failwith "error_l5" }
and
l6 base shift operator nb_operator = parse
	| integer as i { (*A6*) 
    l6 base (shift * 10 + (digit_of_char i)) operator nb_operator lexbuf }
  | 'b' { (*A7*) 
    if operator = '+' then
      for i = 1 to nb_operator do print_int(base + shift); print_string(" ") done
    else if operator = '-' then
      for i = 1 to nb_operator do print_int(base - shift); print_string(" ") done
    else
	    failwith "error_l6";
    l7 base 0 '_' 0 lexbuf;
  }
	| _ { failwith "error_l6" }
and
l7 base shift operator nb_operator = parse
  | zero { (*A3*) l3 base 1 lexbuf }
  | plus { (*A4*) l4 base 1 lexbuf }
  | minus { (*A5*) l5 base 1 lexbuf }
	| '\n'  { (*A8*) print_string("\n") }
	| eof { (*A8*) print_string("\n") }
	| _ { failwith "error_l7" }
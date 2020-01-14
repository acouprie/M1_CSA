(** programme principal pour le for vu en TD3 *)

(**
Copyright (c) 2012, Armelle Bonenfant <bonenfant\@irit.fr>
A distribuer/modifier sour les termes de la licence GNU.
*)

(** Sous-ensemble de regle de grammaire dont on souhaite generer les quadruplets 	
<statlist>   ::= <stat> | <stat> ; <statlist> 
<stat>	     ::= ...| <forstat> | <affectstat>
<forstat>    ::= for ident := <exp> step <exp> until <exp> do <statlist>
<affectstat> ::= ident := <exp>

*)


let parse infile = 
  let lexbuf = Lexing.from_channel (open_in infile) in
  Parser.statlist Lexer.token lexbuf

(* Sys.argv.(1): first argument of executable.
   In this case: name of input file *)
let main () =
  let lquad = parse Sys.argv.(1) in 
  print_string("\nVoici l'ensemble des quadruplets generes \n");
  Lang.print_quad lquad; (*print_string (fst lquad);*)
  print_string("\n");;

main();;


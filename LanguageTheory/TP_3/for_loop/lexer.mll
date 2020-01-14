(** Lexer pour le for vu en TD3 *)


(** Subset of rules in order to generate quads
<statlist>   ::= <stat> | <stat> ; <statlist> 
<stat>	     ::= ...| <forstat> | <affectstat>
<affectstat> ::= ident := <exp>
*)

{
  open Parser  
  exception Lexerror
}

let spaces  = [' ''\t''\n']+

let naturel = ['0'-'9']+
let identifier = ['a'-'z''A'-'Z''_']['a'-'z''A'-'Z''_''0'-'9']*

rule token = parse
  spaces             { token lexbuf } (* recursive call *)
| naturel as i       { INTCONST(i) }
(* keywords *)
| ":="               { AFFECT } 
(* operators *)
| '+'                { PLUS } 
| '*'                { TIMES }
| ';'                { ENDINSTR }
| "do"               { DO }
| "for"              { FOR }
| "step"             { STEP }
| "until"            { UNTIL }
| "endloop"          { ENDLOOP }
| identifier as s    { IDENTIFIER(s) }
| eof                { EOF }
| _                  { Printf.printf "ERROR: unrecogized symbol '%s'\n"
                                     (Lexing.lexeme lexbuf);
                       raise Lexerror }

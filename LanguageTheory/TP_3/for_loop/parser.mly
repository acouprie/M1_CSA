%{
(** Parser *)


(** Subset of rules in order to generate quads
<statlist>   ::= <stat> | <stat> ; <statlist> 
<stat>	     ::= ...| <forstat> | <affectstat>
<affectstat> ::= ident := <exp>

*)
     open Lang

%}
%token <string> INTCONST
%token <string> IDENTIFIER
%token PLUS MINUS
%token TIMES 
%token ENDINSTR 
%token AFFECT 
%token EOF
%token FOR
%token STEP
%token UNTIL
%token DO
%token ENDLOOP 
%left  PLUS MINUS
%left  TIMES 

%type <string> term ident
%type <string*(Lang.quad list)> expr 
%type <Lang.quad list> statlist
%start statlist

%%

forstat: forpart1 DO statlist ENDLOOP {
    let (lquad, quadnum, ident, step) = $1
    in let listquad = lquad@$3@[currentquad(), "+", ident, step, ident]@[currentquad(), "goto", "nil", "nil", quadnum]
    in backpatch listquad [quadnum] (nextquad())}
;

forpart1: FOR ident AFFECT expr STEP expr UNTIL expr {
    let (ident, e1, e2, e3, q1, q2) = ($2, fst $4, fst $6, fst $8, currentquad(), currentquad())
    in ([q1, ":=", e1, "nil", ident]@[q2, ">?", ident, e3, "nil"],q2, ident ,e2)}
;

statlist: EOF                               { [] }
    | stat                                  { $1 }
    | stat ENDINSTR statlist                { $1@$3 }

;

stat:  affectstat                           { $1 }
    | forstat { $1 }
;

affectstat:  ident AFFECT expr            { let (ident, exp) = ($1, (fst $3)) in (snd $3)@[((currentquad ()),":=",exp,"nil",ident)]}
;

expr: 
    | ident                                { ($1,[])}
    | term                                 { ($1,[])}
    | expr PLUS expr                       { let (e1,e2) = (fst $1,fst $3) in 
                                             let res=newtemp ()in 
                                             (res,(((snd $1)@(snd $3)))@[(currentquad ()),"+",e1,e2,res])}
    | expr TIMES expr                      { let (e1,e2) = (fst $1,fst $3) in 
                                             let res=newtemp ()in 
                                             (res,(((snd $1)@(snd $3)))@[(currentquad ()),"*",e1,e2,res])}
;

ident: IDENTIFIER                           { $1 }
;

term: INTCONST                             { $1 }   
;

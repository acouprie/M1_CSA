type token =
  | INTCONST of (string)
  | IDENTIFIER of (string)
  | PLUS
  | MINUS
  | TIMES
  | ENDINSTR
  | AFFECT
  | EOF
  | FOR
  | STEP
  | UNTIL
  | DO
  | ENDLOOP

open Parsing;;
let _ = parse_error;;
# 2 "parser.mly"
(** Parser *)


(** Subset of rules in order to generate quads
<statlist>   ::= <stat> | <stat> ; <statlist> 
<stat>	     ::= ...| <forstat> | <affectstat>
<affectstat> ::= ident := <exp>

*)
     open Lang

# 31 "parser.ml"
let yytransl_const = [|
  259 (* PLUS *);
  260 (* MINUS *);
  261 (* TIMES *);
  262 (* ENDINSTR *);
  263 (* AFFECT *);
    0 (* EOF *);
  264 (* FOR *);
  265 (* STEP *);
  266 (* UNTIL *);
  267 (* DO *);
  268 (* ENDLOOP *);
    0|]

let yytransl_block = [|
  257 (* INTCONST *);
  258 (* IDENTIFIER *);
    0|]

let yylhs = "\255\255\
\005\000\006\000\004\000\004\000\004\000\007\000\007\000\008\000\
\003\000\003\000\003\000\003\000\002\000\001\000\000\000"

let yylen = "\002\000\
\004\000\008\000\001\000\001\000\003\000\001\000\001\000\003\000\
\001\000\001\000\003\000\003\000\001\000\001\000\002\000"

let yydefred = "\000\000\
\000\000\000\000\013\000\003\000\000\000\000\000\015\000\007\000\
\000\000\000\000\006\000\000\000\000\000\000\000\000\000\000\000\
\014\000\010\000\009\000\000\000\000\000\005\000\000\000\000\000\
\000\000\001\000\000\000\000\000\012\000\000\000\000\000\000\000"

let yydgoto = "\002\000\
\018\000\019\000\020\000\007\000\008\000\009\000\010\000\011\000"

let yysindex = "\016\000\
\014\000\000\000\000\000\000\000\011\255\253\254\000\000\000\000\
\017\255\024\255\000\000\022\255\023\255\014\000\014\000\023\255\
\000\000\000\000\000\000\018\255\019\255\000\000\013\255\023\255\
\023\255\000\000\023\255\027\255\000\000\002\255\023\255\018\255"

let yyrindex = "\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\003\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\002\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\001\000\000\000\000\000\000\000\025\255"

let yygindex = "\000\000\
\000\000\005\000\240\255\012\000\000\000\000\000\000\000\000\000"

let yytablesize = 278
let yytable = "\023\000\
\011\000\008\000\004\000\013\000\024\000\006\000\025\000\028\000\
\029\000\012\000\030\000\031\000\003\000\004\000\032\000\024\000\
\001\000\025\000\006\000\006\000\024\000\027\000\025\000\017\000\
\003\000\021\000\022\000\014\000\016\000\015\000\026\000\025\000\
\000\000\000\000\000\000\002\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\011\000\000\000\000\000\011\000\008\000\
\000\000\011\000\011\000\011\000\011\000\008\000\004\000\003\000\
\000\000\000\000\000\000\000\000\000\000\005\000"

let yycheck = "\016\000\
\000\000\000\000\000\000\007\001\003\001\001\000\005\001\024\000\
\025\000\005\000\027\000\010\001\002\001\000\000\031\000\003\001\
\001\000\005\001\014\000\015\000\003\001\009\001\005\001\001\001\
\002\001\014\000\015\000\011\001\007\001\006\001\012\001\005\001\
\255\255\255\255\255\255\011\001\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
\255\255\255\255\255\255\003\001\255\255\255\255\006\001\006\001\
\255\255\009\001\010\001\011\001\012\001\012\001\012\001\002\001\
\255\255\255\255\255\255\255\255\255\255\008\001"

let yynames_const = "\
  PLUS\000\
  MINUS\000\
  TIMES\000\
  ENDINSTR\000\
  AFFECT\000\
  EOF\000\
  FOR\000\
  STEP\000\
  UNTIL\000\
  DO\000\
  ENDLOOP\000\
  "

let yynames_block = "\
  INTCONST\000\
  IDENTIFIER\000\
  "

let yyact = [|
  (fun _ -> failwith "parser")
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 3 : 'forpart1) in
    let _3 = (Parsing.peek_val __caml_parser_env 1 : Lang.quad list) in
    Obj.repr(
# 36 "parser.mly"
                                      (
    let (lquad, quadnum, ident, step) = _1
    in let listquad = lquad@_3@[currentquad(), "+", ident, step, ident]@[currentquad(), "goto", "nil", "nil", quadnum]
    in backpatch listquad [quadnum] (nextquad()))
# 188 "parser.ml"
               : 'forstat))
; (fun __caml_parser_env ->
    let _2 = (Parsing.peek_val __caml_parser_env 6 : string) in
    let _4 = (Parsing.peek_val __caml_parser_env 4 : string*(Lang.quad list)) in
    let _6 = (Parsing.peek_val __caml_parser_env 2 : string*(Lang.quad list)) in
    let _8 = (Parsing.peek_val __caml_parser_env 0 : string*(Lang.quad list)) in
    Obj.repr(
# 42 "parser.mly"
                                                     (
    let (ident, e1, e2, e3, q1, q2) = (_2, fst _4, fst _6, fst _8, currentquad(), currentquad())
    in ([q1, ":=", e1, "nil", ident]@[q2, ">?", ident, e3, "nil"],q2, ident ,e2))
# 200 "parser.ml"
               : 'forpart1))
; (fun __caml_parser_env ->
    Obj.repr(
# 47 "parser.mly"
                                            ( [] )
# 206 "parser.ml"
               : Lang.quad list))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 0 : 'stat) in
    Obj.repr(
# 48 "parser.mly"
                                            ( _1 )
# 213 "parser.ml"
               : Lang.quad list))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : 'stat) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : Lang.quad list) in
    Obj.repr(
# 49 "parser.mly"
                                            ( _1@_3 )
# 221 "parser.ml"
               : Lang.quad list))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 0 : 'affectstat) in
    Obj.repr(
# 53 "parser.mly"
                                            ( _1 )
# 228 "parser.ml"
               : 'stat))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 0 : 'forstat) in
    Obj.repr(
# 54 "parser.mly"
              ( _1 )
# 235 "parser.ml"
               : 'stat))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : string) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : string*(Lang.quad list)) in
    Obj.repr(
# 57 "parser.mly"
                                          ( let (ident, exp) = (_1, (fst _3)) in (snd _3)@[((currentquad ()),":=",exp,"nil",ident)])
# 243 "parser.ml"
               : 'affectstat))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 0 : string) in
    Obj.repr(
# 61 "parser.mly"
                                           ( (_1,[]))
# 250 "parser.ml"
               : string*(Lang.quad list)))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 0 : string) in
    Obj.repr(
# 62 "parser.mly"
                                           ( (_1,[]))
# 257 "parser.ml"
               : string*(Lang.quad list)))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : string*(Lang.quad list)) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : string*(Lang.quad list)) in
    Obj.repr(
# 63 "parser.mly"
                                           ( let (e1,e2) = (fst _1,fst _3) in 
                                             let res=newtemp ()in 
                                             (res,(((snd _1)@(snd _3)))@[(currentquad ()),"+",e1,e2,res]))
# 267 "parser.ml"
               : string*(Lang.quad list)))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : string*(Lang.quad list)) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : string*(Lang.quad list)) in
    Obj.repr(
# 66 "parser.mly"
                                           ( let (e1,e2) = (fst _1,fst _3) in 
                                             let res=newtemp ()in 
                                             (res,(((snd _1)@(snd _3)))@[(currentquad ()),"*",e1,e2,res]))
# 277 "parser.ml"
               : string*(Lang.quad list)))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 0 : string) in
    Obj.repr(
# 71 "parser.mly"
                                            ( _1 )
# 284 "parser.ml"
               : string))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 0 : string) in
    Obj.repr(
# 74 "parser.mly"
                                           ( _1 )
# 291 "parser.ml"
               : string))
(* Entry statlist *)
; (fun __caml_parser_env -> raise (Parsing.YYexit (Parsing.peek_val __caml_parser_env 0)))
|]
let yytables =
  { Parsing.actions=yyact;
    Parsing.transl_const=yytransl_const;
    Parsing.transl_block=yytransl_block;
    Parsing.lhs=yylhs;
    Parsing.len=yylen;
    Parsing.defred=yydefred;
    Parsing.dgoto=yydgoto;
    Parsing.sindex=yysindex;
    Parsing.rindex=yyrindex;
    Parsing.gindex=yygindex;
    Parsing.tablesize=yytablesize;
    Parsing.table=yytable;
    Parsing.check=yycheck;
    Parsing.error_function=parse_error;
    Parsing.names_const=yynames_const;
    Parsing.names_block=yynames_block }
let statlist (lexfun : Lexing.lexbuf -> token) (lexbuf : Lexing.lexbuf) =
   (Parsing.yyparse yytables 1 lexfun lexbuf : Lang.quad list)

%token A
%token EOF
%type <unit> sp
%start sp

%%

sp: s EOF	{ () }
;

s: A { print_string "S -> a\n"; }
;

%%

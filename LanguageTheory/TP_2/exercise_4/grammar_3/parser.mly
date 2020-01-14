%token A
%token B
%token C
%token D
%token EOF
%type <unit> sp
%start sp

%%

sp: s EOF	{ () }
;

s: u A  { print_string "S -> U a\n"; }
| B u C { print_string "S -> b U c\n"; }
| C { print_string "S -> c\n"; }
| B A { print_string "S -> b a\n"; }
;

u:  D		{ print_string "U -> d\n"; }
;

%%

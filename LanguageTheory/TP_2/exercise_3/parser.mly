%token A
%token B
%token C
%token EOF
%type <unit> sp
%start sp

%%

sp: s EOF	{ print_string("Total of c: " ^(string_of_int $1)^ "\n") }
;

s:	A u B	{ print_string "S -> a U b\n"; $2 }
;

u:	C		{ print_string "U -> c\n"; 1 }
|	u C		{ print_string "U -> U c\n"; $1+1 }
;

%%

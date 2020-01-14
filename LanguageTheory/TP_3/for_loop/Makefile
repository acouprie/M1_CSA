
all: lang.cmo parser.cmo lexer.cmo prog.cmo
	ocamlc -o prog $^

# Compilation of .ml files
prog.cmo: prog.ml parser.cmo lang.cmo 
	ocamlc -c $<
lexer.cmo: lexer.ml parser.cmo lang.cmo
	ocamlc -c $<
parser.cmo: parser.ml parser.cmi lang.cmo
	ocamlc -c $<
lang.cmo: lang.ml
	ocamlc -c $<

# ocaml lexer and parser
lexer.ml: lexer.mll
	ocamllex $<

parser.ml parser.mli: parser.mly lang.cmo
	ocamlyacc -v $<

#### Generic rules

%.cmi: %.mli
	ocamlc -c $<


.PHONY: clean

clean: 
	rm -f lexer.ml parser.ml *.mli *.cmi *.cmo *.o doc/dependencies.dot

mrproper: clean
	rm -f cc- doc/*
	rmdir doc

doc: *.ml
	mkdir -p doc/
	ocamldoc -d doc/ -html *.ml
	ocamldoc -o doc/dependencies.dot -dot *.ml
	dot -Tpng -Grotate=0 doc/dependencies.dot > doc/dependencies.png

.PRECIOUS: %.mli

all: prog

prog:  lexer.cmo parser.cmo prog.cmo
	ocamlc -o $@ $^

%.cmo: %.ml
	ocamlc -c $<

%.cmi: %.mli
	ocamlc -c $<

%.ml: %.mll 
	ocamllex $<

%.ml %.mli: %.mly
	ocamlyacc -v $<


lexer.cmo: parser.cmi

clean:
	rm -f *.cmi *.cmo parser.mli parser.ml lexer.ml parser.output

cleanall: clean
	rm -f prog

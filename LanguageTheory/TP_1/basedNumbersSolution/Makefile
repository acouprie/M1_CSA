.PRECIOUS: %.mli

all: prog

prog:  lexer.cmo prog.cmo
	ocamlc -o $@ $^

%.cmo: %.ml
	ocamlc -c $<

%.cmi: %.mli
	ocamlc -c $<

%.ml: %.mll 
	ocamllex $<

clean:
	rm -f *.cmi *.cmo


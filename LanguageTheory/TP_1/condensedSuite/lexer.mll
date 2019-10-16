(****** fichier lexer.mll : analyseur lexical ******)
{
(*** PARTIE OCAML de fonctions utiles ***)
(* conversion char en entier *)
let digit_of_char c = (int_of_char c - int_of_char '0')
(* calcul de la valeur et ajout dans une chaine *)
let calcul_to_string b s e c =
  let valeur = b + s*e in 
  let rec aux n = 
    if (n == 1) then string_of_int valeur
    else (string_of_int valeur)^" "^(aux (n-1))
  in aux c
}

(*** PARTIE ANALYSEUR ***)
(** Unite(s) lexicale(s) **)
let entier = ['0' - '9']

(** Regles **)
rule l0 = parse 
        | entier as i     { (*A0*) print_string ("A0 lit "^(Char.escaped i)^"\n"); 
                            let vi = (digit_of_char i) in l1 vi lexbuf }
	| _    {failwith "erreur_l0" }
and
... (TO COMPLETE)



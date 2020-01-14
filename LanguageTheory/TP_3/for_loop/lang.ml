(*definition of quad type : label/address + quadruplet *)
type quad = string*string*string*string*string

(* current label number, by reference - global *)
      let label = ref 1

(* current register number, by reference - global *)
      let temp = ref 0

(* update of labels/registers *)
      let newtemp ()= let num = !temp in (temp:=(1+ !temp); "R"^(string_of_int num))
      let nextquad () = "L"^(string_of_int !label)
      let currentquad ()= let num = !label in (label:=(1+ !label); "L"^(string_of_int num))


(* update of list of quad lq having llabels as label, udpate with adr address *)
let backpatch lq llabels adr  = match llabels with
           [] -> lq
	  | label::llab -> List.map (fun (l,a,b,c,d) -> if (l=label) then (l,a,b,c,adr) else (l,a,b,c,d)) lq

(* output methods *)
let string_of_quad (l,a,b,c,d) = l^":\t"^a^",\t"^b^",\t"^c^",\t"^d
let print_quad l = print_string (List.fold_left (fun x y -> x^"\n"^y) (string_of_quad (List.hd l)) (List.map string_of_quad (List.tl l)))


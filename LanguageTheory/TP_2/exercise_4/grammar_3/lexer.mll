{
	open Parser
}

rule main = parse 
		'a'		{ A }
	|	'b'		{ B }
	|	'c'		{ C }
	|	'd'		{ D }
	|	'\n'	        { EOF }
	|	eof		{ EOF }
	|	_		{ failwith "bad character !" }

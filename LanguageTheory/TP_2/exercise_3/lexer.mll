{
	open Parser
}

rule main = parse 
		'a'		{ A }
	|	'b'		{ B }
	|	'c'		{ C }
	|	'\n'	        { EOF }
	|	eof		{ EOF }
	|	_		{ failwith "bad character !" }

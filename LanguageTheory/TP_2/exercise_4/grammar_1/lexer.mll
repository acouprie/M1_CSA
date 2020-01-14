{
	open Parser
}

rule main = parse 
		'a'		{ A }
	|	'b'		{ B }
	|	'\n'	{ EOF }
	|	eof		{ EOF }
	|	_		{ failwith "bad character !" }

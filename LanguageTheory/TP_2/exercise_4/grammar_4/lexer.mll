{
	open Parser
}

rule main = parse 
		'a'		{ A }
	|	'\n'	{ EOF }
	|	eof		{ EOF }
	|	_		{ failwith "bad character !" }

	.global		_start
	.extern		main

	.text
	
reset_vec:	b	_start
undef_vec:	b	undef_vec
swi_vec:	b	swi_vec
pabt_vec:	b	pabt_vec
dabt_vec:	b	dabt_vec
rsv_vec:	b	rsv_vec
irq_vec:	ldr pc, [pc,#-0xF20]
fiq_vec:	b	fiq_vec

_start:
	ldr	r13, =0x10000
	bl	main

_exit:
	b	_exit

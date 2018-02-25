; test the comb instruction
	.entry	start
;
	.org	0x50
v1:	.word	0xaaaaa
v2:	.word	0x55555
v3:	.word	0x99999
x:	.word	0xfffff
;
	.org	0x100
;
start:	ldb	v1
	comb	x
;
	ldb	v2
	comb	x
;
	ldb	v3
	comb	x
;
	halt

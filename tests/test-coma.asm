; test the coma instruction
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
start:	lda	v1
	coma	x
;
	lda	v2
	coma	x
;
	lda	v3
	coma	x
;
	halt

; test the clra instruction
	.entry	start
;
	.org	0x50
v1:	.word	0xaaaaa
v2:	.word	0x55555
v3:	.word	0x99999
;
	.org	0x100
;
start:	lda	v1
	clra	v1
;
	lda	v1
	clra	v1
;
	lda	v2
	clra	v1
;
	halt

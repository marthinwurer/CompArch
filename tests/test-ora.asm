; test the ora instruction
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
	ora	v2
;
	lda	v1
	ora	v3
;
	lda	v2
	ora	v3
;
	halt

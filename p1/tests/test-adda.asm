; test the adda instruction
	.entry	start
;
	.org	0x50
one:	.word	0x00001
five:	.word	0x00005
neg1:	.word	0xfffff
neg5:	.word	0xffffb
;
	.org	0x100
start:	lda	one
	adda	one
;
	lda	one
	adda	five
	adda	one
;
	lda	one
	adda	neg1
;
	lda	one
	adda	neg5
;
	halt

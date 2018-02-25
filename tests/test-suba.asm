; test the suba instruction
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
	suba	one
;
	lda	one
	suba	five
	suba	one
;
	lda	one
	suba	neg1
;
	lda	one
	suba	neg5
;
	halt

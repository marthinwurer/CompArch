; test the stxr instruction
	.entry	stxrrt
;
	.org	0x100
one:	.word	0x00001
five:	.word	0x00005
neg1:	.word	0xfffff
neg5:	.word	0xffffb
;
d1:	.word	0
d2:	.word	0
;
	.org	0x300
stxrrt:	ldxr	one
	stxr	d1
	ldxr	d2
	ldxr	d1
	lda	d1
;
	ldxr	five
	stxr	d1
	ldxr	d2
	ldxr	d1
	lda	d1
;
	ldxr	neg1
	stxr	d1
	ldxr	d2
	ldxr	d1
	lda	d1
;
	ldxr	neg5
	stxr	d1
	ldxr	d2
	ldxr	d1
	lda	d1
;
	halt

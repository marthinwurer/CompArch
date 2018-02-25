; test the sta instruction
	.entry	start
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
start:	lda	one
	sta	d1
	lda	d2
	lda	d1
;
	lda	five
	sta	d1
	lda	d2
	lda	d1
;
	lda	neg1
	sta	d1
	lda	d2
	lda	d1
;
	lda	neg5
	sta	d1
	lda	d2
	lda	d1
;
	halt

; test the addb instruction
	.entry	start
;
	.org	0x50
one:	.word	0x00001
five:	.word	0x00005
neg1:	.word	0xfffff
neg5:	.word	0xffffb
;
	.org	0x100
start:	ldb	one
	addb	one
;
	ldb	one
	addb	five
	addb	one
;
	ldb	one
	addb	neg1
;
	ldb	one
	addb	neg5
;
	halt

; test the ldb instruction
	.entry	start
;
	.org	0x100
one:	.word	0x1
five:	.word	0x5
neg1:	.word	0xfffff
neg5:	.word	0xffffb
;
	.org	0x200
start:
	ldb	one
;
	ldb	five
;
	ldb	neg1
;
	ldb	neg5
;
	halt

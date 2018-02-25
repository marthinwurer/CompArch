; test the subb instruction
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
	subb	one
;
	ldb	one
	subb	five
	subb	one
;
	ldb	one
	subb	neg1
;
	ldb	one
	subb	neg5
;
	halt

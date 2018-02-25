; test the stb instruction
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
start:	ldb	one
	stb	d1
	ldb	d2
	ldb	d1
;
	ldb	five
	stb	d1
	ldb	d2
	ldb	d1
;
	ldb	neg1
	stb	d1
	ldb	d2
	ldb	d1
;
	ldb	neg5
	stb	d1
	ldb	d2
	ldb	d1
;
	halt

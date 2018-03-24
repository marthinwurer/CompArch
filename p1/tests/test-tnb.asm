; test the tnb instruction
	.entry	start
;
	.org	0x20
zero:	.word	0
one:	.word	0x00001
five:	.word	0x00005
neg1:	.word	0xfffff
neg5:	.word	0xffffb
error:	.word	0x00bad
;
	.org	0x100
start:
	ldb	zero
	tnb	err1
	tr	test2
err1:	ldb	error
;
test2:	ldb	one
	tnb	err2
	tr	test3
err2:	ldb	error
;
test3:	ldb	five
	tnb	err3
	tr	test4
err3:	ldb	error
;
test4:	ldb	neg1
	tnb	test5
err4:	ldb	error
;
test5:	ldb	zero
	tnb	err5
	tr	test6
err5:	ldb	error
;
test6:	ldb	neg5
	tnb	out
err6:	ldb	error
;
out:
	halt

; test the tzb instruction
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
	tzb	test2
err1:	ldb	error
;
test2:	ldb	one
	tzb	err3
	tr	test3
err2:	ldb	error
;
test3:	ldb	five
	tzb	err3
	tr	test4
err3:	ldb	error
;
test4:	ldb	neg1
	tzb	err4
	tr	test5
err4:	ldb	error
;
test5:	ldb	zero
	tzb	test6
err5:	ldb	error
;
test6:	ldb	neg5
	tzb	err6
	tr	out
err6:	ldb	error
;
out:
	halt

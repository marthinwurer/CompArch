; test the tna instruction
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
	lda	zero
	tna	err1
	tr	test2
err1:	lda	error
;
test2:	lda	one
	tna	err2
	tr	test3
err2:	lda	error
;
test3:	lda	five
	tna	err3
	tr	test4
err3:	lda	error
;
test4:	lda	neg1
	tna	test5
err4:	lda	error
;
test5:	lda	zero
	tna	err5
	tr	test6
err5:	lda	error
;
test6:	lda	neg5
	tna	out
err6:	lda	error
;
out:
	halt

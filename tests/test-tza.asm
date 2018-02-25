; test the tza instruction
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
	tza	test2
err1:	lda	error
;
test2:	lda	one
	tza	err3
	tr	test3
err2:	lda	error
;
test3:	lda	five
	tza	err3
	tr	test4
err3:	lda	error
;
test4:	lda	neg1
	tza	err4
	tr	test5
err4:	lda	error
;
test5:	lda	zero
	tza	test6
err5:	lda	error
;
test6:	lda	neg5
	tza	err6
	tr	out
err6:	lda	error
;
out:
	halt

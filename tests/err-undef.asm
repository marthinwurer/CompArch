	.entry	start
;
start:	lda	ok
;
	.word	0x05000
;
	ldb	error
;
	halt
;
	.org	0x100
ok:	.word	0x00ace
error:	.word	0x00bad

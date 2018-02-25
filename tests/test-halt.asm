; test the halt instruction
	.entry	start
;
	.org	0x50
error:	.word	0x00bad
;
	.org	0x100
start:	halt
	lda	error
	halt
	halt
	halt
	halt

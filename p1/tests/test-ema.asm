; test the ema instruction
	.entry	start
;
	.org	0x100
one:	.word	0x1
five:	.word	0x5
neg1:	.word	0x1ffff
neg5:	.word	0x1fffb
;
	.org	0x150
swap:	.word	0x00ace
;
	.org	0x200
start:
	lda	one
	ema	swap
	ema	swap
;
	lda	five
	ema	swap
	ema	swap
;
	lda	neg1
	ema	swap
	ema	swap
;
	lda	neg5
	ema	swap
	ema	swap
;
	halt

; test the emb instruction
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
	ldb	one
	emb	swap
	emb	swap
;
	ldb	five
	emb	swap
	emb	swap
;
	ldb	neg1
	emb	swap
	emb	swap
;
	ldb	neg5
	emb	swap
	emb	swap
;
	halt

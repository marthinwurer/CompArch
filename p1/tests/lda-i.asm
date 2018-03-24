; test indirection with lda
	.entry	start
;
	.org	0x100
one:	.word	0x1
five:	.word	0x5
neg1:	.word	0xfffff
neg5:	.word	0xffffb
;
	.org	0x150
ptr0:	.word	0x100
ptr1:	.word	0x101
ptr2:	.word	0x102
ptr3:	.word	0x103
;
	.org	0x200
start:
	lda	ptr0,i
	lda	ptr1,i
	lda	ptr2,i
	lda	ptr3,i
;
	halt

; test the ldxr instruction
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
	ldxr	ptr0
	ldxr	ptr1
	ldxr	ptr2
	ldxr	ptr3
;
	ldxr	one
	ldxr	five
	ldxr	neg1
	ldxr	neg5
;
	halt

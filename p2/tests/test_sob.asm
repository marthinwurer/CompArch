;
; tests SOB
;
; uses instructions MOV, BPT, ADD, HALT
;
; uses addressing modes 0, 2, 6
;
	.globl	start
;
num:	.word	12
. = . + 10
vector:	.word	1,2,4
	.word	7,6,22
	.word	16,3,77
	.word	401
. = . + 50
;
start:	mov	num,r5
	mov	#vector,r2
	bpt
;
loop:	add	(r2)+,r4
	sob	r5,loop
;
	bpt
	halt
;
	.end	start

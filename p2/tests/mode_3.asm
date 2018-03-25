;
; tests addressing mode 3
;
; uses instructions MOV, HALT, BPT
;
; uses other addressing modes 0, 2
;
	.globl	start
ptrs:	.word	alpha,beta,gamma
. = . + 50
alpha:	.word	1
beta:	.word	2
gamma:	.word	4
;
. = . + 100
;
start:	mov	#ptrs,r2
	mov	#3,r1
	bpt
;
loop:	add	@(r2)+,r3
	bpt
	sub	#1,r1
	bgt	loop
;
quit:	bpt
	halt
;
	.end	start

;
; tests addressing mode 2
;
; uses instructions MOV, HALT, BPT
;
; uses other addressing modes 0, 6
;
	.globl	start
ptr:	.word	alpha
. = . + 50
alpha:	.word	1,2,4
;
. = . + 100
;
start:	mov	ptr,r2
	mov	#3,r1
	bpt
;
loop:	add	(r2)+,r3
	bpt
	sub	#1,r1
	bgt	loop
;
quit:	bpt
	halt
;
	.end	start

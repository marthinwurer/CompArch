;
; tests addressing mode 6
;
; uses instructions MOV, HALT, BPT
;
; uses other addressing modes 0
;
	.globl	start
ptr:	.word	alpha
;
. = . + 50
alpha:	.word	1
;
. = . + 100
;
start:	mov	ptr,r2
	mov	alpha,ptr
	mov	ptr,r3
	bpt
	mov	r2,ptr
	mov	ptr,r4
	bpt
;
	halt
;
	.end	start

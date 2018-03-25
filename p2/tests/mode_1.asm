;
; tests addressing mode 1
;
; uses instructions MOV, HALT, BPT
;
; uses other addressing modes 0, 6
;
	.globl	start
ptr:	.word	alpha
. = . + 50
alpha:	.word	42
;
. = . + 100
;
start:	mov	ptr,r2
	bpt
;
	mov	(r2),r3
	bpt
;
	halt
;
	.end	start

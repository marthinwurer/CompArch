;
; tests addressing mode 0
;
; uses instructions HALT, CLR, BPT
;
; uses no other addressing modes
;
	.globl	start
done:	halt
;
. = . + 100
;
start:	mov	r7,r2
	bpt
	clr	r7
	bpt
;
	.end	start

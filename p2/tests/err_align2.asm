;
; tests unaligned memory instruction references
;
; uses instructions JMP, CLR, HALT
;
; uses addressing modes 0, 6
;
	.globl	start
v1:	.word	10
v2:	.byte	5
v3:	.byte	10
. = . + 50
;
start:	jmp	loc+1
. = . + 50
loc:	clr	r5
	clr	r5
	halt
;
	.end	start

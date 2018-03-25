;
; tests NOP
;
; uses instructions MOV, BPT, HALT
;
; uses addressing modes 0, 6
;
	.globl	start
start:	nop
	mov	x,r5
	nop
	bpt
	nop
	bpt
	halt
;
x:	.word	42
	.end	start

;
; tests BPT
;
; uses instructions MOV, HALT
;
; uses addressing modes 0, 6
;
	.globl	start
start:	bpt
	mov	x,r5
	bpt
	halt
;
x:	.word	42
	.end	start

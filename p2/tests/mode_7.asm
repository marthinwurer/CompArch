;
; tests addressing mode 7
;
; uses instructions MOV, HALT, BPT
;
; uses other addressing modes 0, 6
;
	.globl	start
. = . + 50
v1:	.word	10
v2:	.word	v1
. = . + 50
;
start:	mov	@v2,r1
	bpt
	halt
;
	.end	start

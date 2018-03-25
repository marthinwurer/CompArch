;
; tests addressing mode 4
;
; uses instructions MOV, HALT, BPT
;
; uses other addressing modes 0, 6
;
	.globl	start
. = . + 50
v1:	.word	10
v2:	.word	5
. = . + 50
;
start:	mov	#v2,r1
	bpt
	mov	-(r1),r2
	bpt
	halt
;
	.end	start

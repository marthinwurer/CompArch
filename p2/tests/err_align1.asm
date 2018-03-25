;
; tests unaligned memory data references
;
; uses instructions MOV, HALT
;
; uses addressing modes 0, 6
;
	.globl	start
v1:	.word	10
v2:	.byte	5
v3:	.byte	10
. = . + 50
;
start:	mov	v1,r1
	mov	v3,r2
	halt
;
	.end	start

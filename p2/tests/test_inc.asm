;
; tests INC
;
; uses instructions BPT, HALT, MOV
;
; uses addressing modes 0, 1, 2, 6
;
	.globl	start
;
one:	.word	1
;
. = . + 50
ptr:	.word	alpha
. = . + 10
alpha:	.word	42
. = . + 10
;
start:	inc	r1
	bpt
;
	inc	one
	mov	one,r2
	bpt
;
	inc	one
	inc	one
	mov	one,r2
	bpt
;
	mov	ptr,r3
	inc	(r3)
	mov	alpha,r4
	bpt
;
	inc	(r3)+
	mov	alpha,r5
	bpt
;
	halt
;
	.end	start

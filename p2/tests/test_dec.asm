;
; tests DEC
;
; uses instructions BPT, HALT, MOV
;
; uses addressing modes 0, 1, 2, 6
;
	.globl	start
;
one:	.word	10
;
. = . + 50
ptr:	.word	alpha
. = . + 10
alpha:	.word	42
. = . + 10
;
start:	dec	r1
	bpt
;
	dec	one
	mov	one,r2
	bpt
;
	dec	one
	dec	one
	mov	one,r2
	bpt
;
	mov	ptr,r3
	dec	(r3)
	mov	alpha,r4
	bpt
;
	dec	(r3)+
	mov	alpha,r5
	bpt
;
	halt
;
	.end	start

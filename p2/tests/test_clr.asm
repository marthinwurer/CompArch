;
; tests CLR
;
; uses instructions MOV, BPT, HALT
;
; uses addressing modes 0, 6
;
	.globl	start
;
one:	.word	1
n_one:	.word	-1
;
start:	mov	one,r1
	mov	n_one,r2
	bpt
;
	clr	r1
	bpt
;
	clr	r2
	bpt
;
	clr	one
	mov	one,r4
	bpt
;
	clr	n_one
	mov	n_one,r5
	bpt
;
	halt
	.end	start

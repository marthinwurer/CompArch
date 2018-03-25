;
; tests ADD
;
; uses instructions BPT, HALT
;
; uses addressing modes 0, 6
;
	.globl	start
;
one:	.word	1
n_one:	.word	-1
five:	.word	5
n_five:	.word	-5
;
start:	add	one,r1
	bpt
;
	add	five,r1
	bpt
;
	add	n_one,r1
	bpt
;
	add	n_five,r1
	bpt
;
	add	n_five,r2
	add	n_five,r2
	bpt
;
	add	five,r3
	add	five,r3
	bpt
;
	add	five,r4
	add	n_five,r4
	add	n_five,r4
	bpt
;
	add	n_five,r5
	add	five,r5
	add	five,r5
	bpt
;
	halt
;
	.end	start

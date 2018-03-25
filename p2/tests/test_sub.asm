;
; tests SUB
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
start:	sub	one,r1
	bpt
;
	sub	five,r1
	bpt
;
	sub	n_one,r1
	bpt
;
	sub	n_five,r1
	bpt
;
	sub	n_five,r2
	sub	n_five,r2
	bpt
;
	sub	five,r3
	sub	five,r3
	bpt
;
	sub	five,r4
	sub	n_five,r4
	sub	n_five,r4
	bpt
;
	sub	n_five,r5
	sub	five,r5
	sub	five,r5
	bpt
;
	halt
;
	.end	start

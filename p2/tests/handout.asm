;
; sample program from project handout
;
	.globl	start
base = .
. = base + 76
;
start:
	clr	r3
	mov	r2,(r4)
	bpt
;
	mov	x,r2
	bpt
;
	mov	#123,r3
	bpt
;
	halt
;
. = base + 214
;
x:	.word	-1
;
	.end	start

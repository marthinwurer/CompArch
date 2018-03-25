;
; tests MOV
;
; uses instructions BPT, HALT
;
; uses addressing modes 0, 2, 6
;
	.globl	start
start:	bpt
;
	mov	#1000,sp
	bpt
;
	mov	sp,r3
	bpt
;
	mov	r3,x
	bpt
;
	mov	x,r4
	bpt
;
	mov	x,y
	bpt
;
	mov	y,r5
	bpt
;
	halt
;
x:	.word	0
y:	.word	77
	.end	start

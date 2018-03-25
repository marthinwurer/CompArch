;
; tests TST
;
; uses instructions MOV, BPT, HALT
;
; uses addressing modes 0, 6
;
	.globl	start
;
v1:	.word	0
v2:	.word	177777
v3:	.word	077777
;
start:	mov	v1,r1
	mov	v2,r2
	mov	v3,r3
	bpt
;
	tst	r1
	tst	r2
	tst	r3
;
	tst	v1
	tst	v2
	tst	v3
;
	halt
;
	.end	start

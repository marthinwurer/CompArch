;
; tests COM
;
; uses instructions MOV, BPT, HALT
;
; uses addressing modes 0, 6
;
	.globl	start
;
v1:	.word	1
v2:	.word	077777
v3:	.word	177777
v4:	.word	125252
v5:	.word	052525
;
. = . + 100
;
start:	mov	v1,r1
	mov	v2,r2
	mov	v3,r3
	mov	v4,r4
	mov	v5,r5
	bpt
;
	com	r1
	com	r2
	com	r3
	com	r4
	com	r5
	bpt
;
	com	r1
	com	r2
	com	r3
	com	r4
	com	r5
	bpt
;
	halt
;
	.end	start

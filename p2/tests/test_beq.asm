;
; tests BEQ
;
; uses instructions MOV, BPT, CMP, ADD, BR, HALT
;
; uses addressing modes 0, 2, 6
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
	cmp	r1,r1
	beq	ok1
	add	#1,r0
ok1:
;
	cmp	r1,r2
	beq	err1
	br	ok2
err1:	add	#2,r0
ok2:
;
	bpt
	halt
;
	.end	start

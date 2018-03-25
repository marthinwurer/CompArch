;
; tests BVC/BVS
;
; uses instructions MOV, BPT, ADD, HALT
;
; uses addressing modes 0, 2, 6
;
	.globl	start
;
v1:	.word	0
v2:	.word	100000
v3:	.word	077777
;
start:
	mov	v3,r3
	add	#1,r3
	bvs	ok1
	add	#1,r0
ok1:
	add	#1,r3
	bvc	ok2
	add	#2,r0
ok2:
	mov	v2,r2
	add	#1,r2
	bvs	bad3
	jmp	ok3
bad3:
	add	#4,r0
ok3:
	add	#1,r2
	bvc	ok4
	add	#10,r0
ok4:
;
	bpt
	halt
;
	.end	start

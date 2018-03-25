;
; tests BCC/BCS
;
; uses instructions MOV, BPT, ADD, HALT
;
; uses addressing modes 0, 2, 6
;
	.globl	start
;
v1:	.word	0
v2:	.word	177777
v3:	.word	077777
;
start:
	mov	v2,r2
	add	#1,r2
	bcs	ok1
	add	#1,r0
ok1:
	mov	v3,r3
	add	#1,r3
	bcc	ok2
	add	#2,r0
ok2:
;
	bpt
	halt
;
	.end	start

;
; tests CMP
;
; uses instructions MOV, BPT, HALT
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
	cmp	#0,r1
	cmp	#0,r2
	cmp	#0,r3
;
	cmp	r1,#0
	cmp	r2,#0
	cmp	r3,#0
;
	cmp	#0,v1
	cmp	#0,v2
	cmp	#0,v3
;
	cmp	v1,#0
	cmp	v2,#0
	cmp	v3,#0
;
	cmp	r1,r1
	cmp	r1,r2
	cmp	r1,r3
;
	cmp	r2,r1
	cmp	r2,r2
	cmp	r2,r3
;
	cmp	r3,r1
	cmp	r3,r2
	cmp	r3,r3
;
	cmp	v1,v1
	cmp	v1,v2
	cmp	v1,v3
;
	cmp	v2,v1
	cmp	v2,v2
	cmp	v2,v3
;
	cmp	v3,v1
	cmp	v3,v2
	cmp	v3,v3
;
	halt
;
	.end	start

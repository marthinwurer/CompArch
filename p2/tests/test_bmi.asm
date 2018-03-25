;
; tests BMI
;
; uses instructions MOV, BPT, BR, HALT, ADD, and CMP
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
	cmp	r1,r3
	bmi	ok1
err1:	add	#1,r0
ok1:
;
	cmp	r3,r1
	bmi	err2
	br	ok2
err2:	add	#2,r0
ok2:
;
	cmp	r1,r2
	bmi	err3
	br	ok3
err3:	add	#4,r0
ok3:
;
	cmp	r2,r1
	bmi	ok4
err4:	add	#10,r0
ok4:
;
	cmp	r3,r2	; this one's funny
	bmi	ok5
err5:	add	#20,r0
ok5:
;
	cmp	r2,r3
	bmi	ok6
err6:	add	#20,r0
ok6:
;
	cmp	r1,r1
	bmi	err7
	br	ok7
err7:	add	#40,r0
ok7:
;
	bpt
	halt
;
	.end	start

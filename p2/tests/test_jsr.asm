;
; tests JSR
;
; uses instructions MOV, BPT, HALT
;
; uses addressing modes 0, 1, 6
;
	.globl	start
a:	.word	loc5
b:	.word	loc6
;
. = . + 50
;
loc1:	jsr	r2,loc2
;
. = . + 50
;
loc2:	jsr	r3,loc3
;
. = . + 50
loc3:	jsr	r4,loc4
;
. = . + 50
;
loc4:	bpt
	mov	a,r0
	mov	b,r1
	jsr	r2,(r0)
;
. = . + 50
;
loc5:	jsr	r3,(r1)
;
. = . + 50
;
loc6:	bpt
	halt
;
. = . + 50
;
start:	
	mov	#stack,r6
	jsr	r1,loc1
;
. = . + 200
stack:	.word	0
	.end	start

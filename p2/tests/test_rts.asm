;
; tests RTS
;
; uses instructions MOV, BPT, HALT
;
; uses addressing modes ?
;
	.globl	start
;
a:	.word	loc1
b:	.word	loc2
c:	.word	loc3
;
. = . + 100
;
start:	mov	#1000,sp
	mov	a,r1
	mov	b,r2
	mov	c,r3
	bpt
;
	rts	r1
;
. = . + 100
loc1:	bpt
	rts	r2
;
. = . + 100
loc2:	bpt
	rts	r3
;
. = . + 100
loc3:	bpt
	halt
;
	.end	start

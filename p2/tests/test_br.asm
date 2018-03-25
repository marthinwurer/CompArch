;
; tests BR
;
; uses instructions HALT
;
; uses only branch operands
;
	.globl	start
;
start:	br	loc3
loc1:	br	loc5
loc2:	br	loc6
loc3:	br	loc1
loc4:	br	loc7
loc5:	br	loc2
loc6:	br	loc4
loc7:	halt
	.end	start

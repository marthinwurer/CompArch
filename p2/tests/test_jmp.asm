;
; tests JMP
;
; uses instructions HALT
;
; uses addressing modes 6
;
	.globl	start
;
start:	jmp	loc3
loc1:	jmp	loc5
loc2:	jmp	loc6
loc3:	jmp	loc1
loc4:	jmp	loc7
loc5:	jmp	loc2
loc6:	jmp	loc4
loc7:	halt
	.end	start

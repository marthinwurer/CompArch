;
; tests SEC/CLC
;
; uses instructions HALT
;
; uses no addressing modes
;
	.globl	start
start:	sec
	clc
	halt
	.end	start

;
; tests SEZ/CLZ
;
; uses instructions HALT
;
; uses no addressing modes
;
	.globl	start
start:	sez
	clz
	halt
	.end	start

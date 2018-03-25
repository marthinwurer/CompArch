;
; tests SEN/CLN
;
; uses instructions HALT
;
; uses no addressing modes
;
	.globl	start
start:	sen
	cln
	halt
	.end	start

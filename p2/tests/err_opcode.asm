;
; tests erroneous opcodes
;
; uses instructions HALT
;
; uses no addressing modes
;
	.globl	start
;
start:
	.word	1
	halt
;
	.end	start

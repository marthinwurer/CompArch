;
; tests SEV/CLV
;
; uses instructions HALT
;
; uses no addressing modes
;
	.globl	start
start:	sev
	clv
	halt
	.end	start

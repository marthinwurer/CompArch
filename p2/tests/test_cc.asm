;
; tests SCC/CCC
;
; uses instructions HALT
;
; uses no addressing modes
;
	.globl	start
start:	scc
	ccc
	scc
	ccc
	halt
	.end	start

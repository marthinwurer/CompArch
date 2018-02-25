; test the xorb instruction
	.entry	start
;
	.org	0x50
v1:	.word	0xaaaaa
v2:	.word	0x55555
v3:	.word	0x99999
;
	.org	0x100
;
start:	ldb	v1
	xorb	v2
;
	ldb	v1
	xorb	v3
;
	ldb	v2
	xorb	v3
;
	halt

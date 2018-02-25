; test the lia instruction
	.entry	start
;
	.org	0x1
error:	.word	0x00bad
;
	.org	0x200
start:
	lia	1,ix
;
	halt

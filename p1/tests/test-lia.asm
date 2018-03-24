; test the lia instruction
	.entry	start
;
	.org	0x200
start:
	lia	1
;
	lia	5
;
	lia	0x7ff
;
	lia	0xfff
;
	lia	0xffb
;
	lia	0x800
;
	halt

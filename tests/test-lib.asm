; test the lib instruction
	.entry	start
;
	.org	0x200
start:
	lib	1
;
	lib	5
;
	lib	0x7ff
;
	lib	0xfff
;
	lib	0xffb
;
	lib	0x800
;
	halt

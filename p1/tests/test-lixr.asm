; test the lixr instruction
	.entry	start
;
	.org	0x200
start:
	lixr	1
;
	lixr	5
;
	lixr	0x7ff
;
	lixr	0xfff
;
	lixr	0xffb
;
	lixr	0x800
;
	halt

	.entry	start
;
	.org	0x50
stop:	halt
;
	.org	0xc4
start:	lda	w
	adda	x
	adda	y,i
	lib	0x14
	subb	z
	tr	stop
;
	.org	0x100
w:	.word	0x50
y:	.word	0x300
z:	.word	0x9
;
	.org	0x200
x:	.word	0x30
;
	.org	0x300
foo:	.word	0x10

; test indirect indexed addressing with lda/ldb
	.entry	start
;
	.org	0x50
loc1:	.word	0
loc2:	.word	1
loc3:	.word	2
loc4:	.word	3
;
	.org	0x60
loc5:	.word	0xfffff
loc6:	.word	0xffffe
loc7:	.word	0xffffd
loc8:	.word	0xffffc
;
	.org	0x100
arr1:	.word	0x10
	.word	0x20
	.word	0x30
	.word	0x40
;
	.org	0x110
arr2:	.word	0x100
	.word	0x200
	.word	0x300
	.word	0x400
;
	.org	0x150
ptr1:	.word	0x100
ptr2:	.word	0x114
;
	.org	0x200
start:
	ldxr	ptr1
	lda	loc1,ix
	lda	loc2,ix
	lda	loc3,ix
	lda	loc4,ix
;
	ldxr	ptr2
	ldb	loc5,ix
	ldb	loc6,ix
	ldb	loc7,ix
	ldb	loc8,ix
;
	halt

; test the tr instruction
	.entry	start
;
	.org	0x0
loc7:	halt
;
	.org	0x500
start:	tr	loc1
;
	.org	0x510
loc1:	tr	loc2
;
	.org	0x520
loc4:	tr	loc5
;
	.org	0x530
loc6:	tr	loc7
;
	.org	0x540
loc3:	tr	loc4
;
	.org	0x550
loc2:	tr	loc3
;
	.org	0x560
loc5:	tr	loc6

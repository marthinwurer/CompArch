//
// Created by benjamin on 2/24/18.
//

#include <Clock.h>
#include "addressing.h"

/**
The PDP-11 supports eight addressing modes. Each operand is represented
in the instruction word with a three-bit mode specifier, followed by a
three-bit register designator. Some modes require an additional word of
 information, called the extension, in the instruction sequence.

Here are descriptions of the addressing modes when R0-R6 are used:

Mode	Name	            Assembler	Extension?	Effective Address (EA) Computed As
0	    register	        Rn	        none	    Rn (not a memory address)
1   	reg. deferred	    (Rn)	    none	    contents of Rn
2   	autoincrement	    (Rn)+	    none	    contents of Rn, before increment of Rn
3   	autoinc. deferred	@(Rn)+	    none	    contents of indirect word in memory pointed at by Rn, before increment of Rn
4   	autodecrement	    -(Rn)	    none	    contents of Rn, after decrement of Rn
5   	autodec. deferred	@-(Rn)	    none	    contents of indirect word in memory pointed at by Rn, after decrement of Rn
6   	displacement	    D(Rn)	    16-bit D	D + contents of Rn
7   	disp. deferred	    @D(Rn)	    16-bit D	contents of indirect word in memory pointed at by (D + contents of Rn)

 * @param am
 */
bool calc_addressing(ulong am, Clearable & reg, Clearable & into) {
    bool from_memory = false;
    bool inc = false;
    bool dec = false;
    bool D = false;

    // 0 (register), 1 (register deferred), 2 (autoincrement), 4 (autodecrement), 6 (displacement)
    switch (am){
        case 0:
            sbus.IN().pullFrom(reg);
            into.latchFrom(sbus.OUT());
            Clock::tick();
            break;
        case 01:
            from_memory = true;
            break;
        case 02:
            from_memory = true;
            inc = true;
            break;
        case 04:
            from_memory = true;
            dec = true;
            break;
        case 06:
            from_memory = true;
            D = true;
            break;
        default:
            cout << "AHHHHHHHHHHHHHHHHHH" << endl;
            throw ArchLibError("AAAAAHHHHHH");

    }

    if (from_memory){
        if(dec){
            alu.perform(BusALU::op_add);
            alu.OP1().pullFrom(reg);
            alu.OP2().pullFrom(const_2);
            reg.latchFrom(alu.OUT());
            Clock::tick();
        }

        // load the mar
        abus.IN().pullFrom(reg);
        m.MAR().latchFrom(abus.OUT());
        Clock::tick();
        // load the data into the op
        into.latchFrom(m.READ());
        m.read();

        // todo


    }


    m.read();
    mdr.latchFrom(m.READ());
    Clock::tick();
    return from_memory;

}

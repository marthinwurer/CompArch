//
// Created by benjamin on 2/24/18.
//

#include <Clock.h>
#include "addressing.h"

/**
K19 addressing modes are used to calculate the Effective Address (EA) for memory operands as follows:

Code	Name	    Description
00	    Direct	    EA is the contents of the address field.
01  	Indexed	    EA is the sum of the address field and the XR register.
10  	Indirect	The address field contains the address of an indirect word in memory; EA is the contents of the least significant 12 bits of that word.
11  	Indirect    indexed	The address field contains the address of an indirect word in memory; EA is the sum of the least significant 12 bits of that word and the XR register.

 * @param am
 */
void calc_addressing(ulong am) {

    switch (am){
        case 0b00:
            abus.IN().pullFrom(ir);
            m.MAR().latchFrom(abus.OUT());
            Clock::tick();
            break;
        case 0b01:
            m.MAR().latchFrom(addr_alu.OUT());
            addr_alu.OP1().pullFrom(ir);
            addr_alu.OP2().pullFrom(xr);
            addr_alu.perform(BusALU::Operation::op_add);
            Clock::tick();
            break;
        case 0b10:
            abus.IN().pullFrom(ir);
            m.MAR().latchFrom(abus.OUT());
            Clock::tick();
            m.MAR().latchFrom(m.READ());
            m.read();
            Clock::tick();
            break;
        case 0b11:
            abus.IN().pullFrom(ir);
            m.MAR().latchFrom(abus.OUT());
            Clock::tick();
            m.MAR().latchFrom(m.READ());
            m.read();
            Clock::tick();
            m.MAR().latchFrom(addr_alu.OUT());
            addr_alu.OP1().pullFrom(m.MAR());
            addr_alu.OP2().pullFrom(xr);
            addr_alu.perform(BusALU::Operation::op_add);
            Clock::tick();


            break;

        default:
            cout << "AHHHHHHHHHHHHHHHHHH" << endl;
            exit(1);

    }

    m.read();
    mdr.latchFrom(m.READ());
    Clock::tick();

}

#include <cstdlib>
#include <iostream>
#include <Clock.h>
#include <bitset>


#include "globals.h"
#include "addressing.h"
#include "opcodes.h"

int main( int argc, char * argv[]) {

    CPUObject::debug |= CPUObject::trace | CPUObject::memload;
    cout << hex;

    // get command line input
    // taken from dumbest
    if( argc != 2 ) {
        cerr << "Usage:  " << argv[0] << " object-file-name\n\n";
        exit( 1 );
    }

    m.load( argv[1] );






    // run
//    int count = 0;

    // entry point hack
    ic.latchFrom(m.READ());
    Clock::tick();

    try {


        while (!halt) {

            // store trace info
            A = a.uvalue();
            B = b.uvalue();
            XR = xr.uvalue();
            pc = ic.uvalue();

            // START IF
//        cout << "latch from read" << endl;
            abus.IN().pullFrom(ic);
            m.MAR().latchFrom(abus.OUT());
            m.read();
            Clock::tick();
            m.read();
            ir.latchFrom(m.READ());
            Clock::tick();
            instruction = ir.uvalue();
            // END IF

            // START DECODE
            // get the addressing mode
            ulong am = ir.uvalue() >> 18;
            ulong opcode = ir.uvalue() >> 12 & 0b111111;
//            cout << am << " " << std::bitset<6>(opcode) << endl; // todo

            // compute the addressing mode
            calc_addressing(am);
//            calc_addressing(0b00);
//            calc_addressing(0b01);
//            calc_addressing(0b10);
//            calc_addressing(0b11);

            // mdr is now the correct value.
//            cout << "mdr " << mdr.uvalue() << endl;
            // END DECODE

            // find and execute the correct operation
            bool skip = exec_opcode(opcode, am);


//            count++;
//            if (count > 1) {
//                halt = true;
//
//            }

            // increment the pc
            if (!skip){
                ic.incr();
                Clock::tick();
            }
            print_trace();
        }
    }catch( ArchLibError & e){
        print_trace();
        cout << endl << "Machine Halted - " << e.what() << endl;
    }

    // teardown

    return 0;
}

#include <cstdlib>
#include <iostream>
#include <Clock.h>
#include <bitset>


#include "globals.h"
#include "addressing.h"
#include "setup.h"
#include "decode.h"

int main( int argc, char * argv[]) {

    CPUObject::debug |= CPUObject::trace | CPUObject::memload;
    cout << oct;

    // get command line input
    // taken from dumbest
    if( argc != 2 ) {
        cerr << "Usage:  " << argv[0] << " object-file-name\n\n";
        exit( 1 );
    }

    m.load( argv[1] );


    setup();






    // run
//    int count = 0;

    // entry point hack
    regs[7]->latchFrom(m.READ());
    Clock::tick();

    try {


        while (!halt) {

            // store trace info
            // get the addr for the printout
            addr = regs[7]->uvalue();
            // get the ps
            ps = (N.uvalue()<<3) | (Z.uvalue() <<2) | (V.uvalue() << 1) | (C.uvalue());

            // START IF

            abus.IN().pullFrom(*regs[7]);
            m.MAR().latchFrom(abus.OUT());
            m.read();
            Clock::tick();
            m.read();
            ir.latchFrom(m.READ());
            Clock::tick();
            instruction = ir.uvalue();
            // END IF

            // START DECODE
            // set the operand validities to false
            src.valid = false;
            dest.valid = false;
            // get the instruction category
            ulong category = ir.uvalue() >> 12 & 0b1111;
            decode(category);

            if (src.valid) {
                load(src, sss);
            }
            if (dest.valid) {
                load(dest, ddd);
            }

            // call function pointer

            operation();

            if (dest.valid){
                writeback(dest);
            }



            ulong opcode = ir.uvalue() >> 12 & 0b1111;
            cout << " " << std::bitset<4>(category) << endl;

//            break;

            // mdr is now the correct value.
//            cout << "mdr " << mdr.uvalue() << endl;
            // END DECODE

            // find and execute the correct operation
            bool skip;


//            count++;
//            if (count > 1) {
//                halt = true;
//
//            }

            // increment the pc
            if (!skip){
                // inc pc
                alu.perform(BusALU::op_add);
                alu.OP1().pullFrom(*regs[7]);
                alu.OP2().pullFrom(const_2);
                regs[7]->latchFrom(alu.OUT());
                Clock::tick();
            }
            print_trace();
        }
    }catch( ArchLibError & e){
        print_trace();
        cout << endl << "Machine Halted - " << e.what() << endl;
    }

    // teardown

    // free all the registers
    for( int ii = 0; ii < NUM_REGS; ii++){
        delete regs[ii];
    }

    return 0;
}

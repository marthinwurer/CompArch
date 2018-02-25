#include <iostream>
#include <Clock.h>
#include <bitset>


#include "globals.h"
#include "addressing.h"
#include "opcodes.h"

int main( int argc, char * argv[]) {

//    CPUObject::debug |= CPUObject::trace | CPUObject::memload;
    cout << hex;

    // get command line input
    // taken from dumbest
    if( argc != 2 ) {
        cerr << "Usage:  " << argv[0] << " object-file-name\n\n";
        exit( 1 );
    }

    m.load( argv[1] );

    // setup
    // memory
//    m.MAR().connectsTo(abus.IN());
    m.MAR().connectsTo(abus.OUT());
    mdr.connectsTo(m.READ());
    mdr.connectsTo(m.WRITE());
    mdr.connectsTo(dbus.IN());
    mdr.connectsTo(dbus.OUT());
    mdr.connectsTo(alu.OP2());


    // accumulators
    a.connectsTo(dbus.IN());
    a.connectsTo(dbus.OUT());
    a.connectsTo(alu.OP1());
    b.connectsTo(dbus.IN());
    b.connectsTo(dbus.OUT());
    b.connectsTo(alu.OP1());


    // ic, ir, and xr
    ic.connectsTo(abus.IN());
    ic.connectsTo(abus.OUT());
    ic.connectsTo(m.READ()); // hack to get start point
    xr.connectsTo(abus.IN());
    xr.connectsTo(abus.OUT());

    ir.connectsTo(dbus.IN());
    ir.connectsTo(dbus.OUT());
    ir.connectsTo(m.READ());

    // connections required for addressing logic
    ir.connectsTo(abus.IN());
    ir.connectsTo(addr_alu.OP1());
    xr.connectsTo(addr_alu.OP2());
    m.MAR().connectsTo(addr_alu.OUT());
    m.MAR().connectsTo(addr_alu.OP1());
    m.MAR().connectsTo(m.READ());

    // connections required for alu logic
    a.connectsTo(alu.OUT());
    b.connectsTo(alu.OUT());
    se_mask_12.connectsTo(alu.OP2());

    // whyyyyyy
    xr.connectsTo(m.READ());
    xr.connectsTo(m.WRITE());
    xr.connectsTo(dbus.OUT());

    m.MAR().connectsTo(dbus.IN());
    ic.connectsTo(dbus.OUT());






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

#include <iostream>
#include <Clock.h>


#include "globals.h"
#include "addressing.h"

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







    // run
    int count = 0;

    // entry point hack
    ic.latchFrom(m.READ());
    Clock::tick();

    try {


        while (!halt) {

            // START IF
//        cout << "latch from read" << endl;
            abus.IN().pullFrom(ic);
            m.MAR().latchFrom(abus.OUT());
            m.read();
            Clock::tick();
            m.read();
            ir.latchFrom(m.READ());
            Clock::tick();
            // END IF

            // START DECODE
            // get the addressing mode
            ulong am = ir.uvalue() >> 18;
            ulong opcode = ir.uvalue() >> 12 & 0b111111;
            cout << am << " " << opcode << endl;

            // compute the addressing mode
            calc_addressing(am);
            calc_addressing(0b00);
            calc_addressing(0b01);
            calc_addressing(0b10);
            calc_addressing(0b11);

            // mdr is now the correct address.


            count++;
            if (count > 1) {
                halt = true;

            }
        }
    }catch( ArchLibError e){
        cout << e.what() << endl;
    }

    // teardown

    return 0;
}

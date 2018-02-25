#include <iostream>
#include <Clock.h>


#include "globals.h"

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
    b.connectsTo(dbus.IN());
    b.connectsTo(dbus.OUT());


    // ic, ir, and xr
    ic.connectsTo(abus.IN());
    ic.connectsTo(abus.OUT());
    ic.connectsTo(m.READ()); // hack to get start point
    xr.connectsTo(abus.IN());
    xr.connectsTo(abus.OUT());

    ir.connectsTo(dbus.IN());
    ir.connectsTo(dbus.OUT());
    ir.connectsTo(m.READ());






    // run
    int count = 0;

    // entry point hack
    ic.latchFrom(m.READ());
    Clock::tick();

    while (!halt){

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






        count ++;
        if (count > 10){
            halt = true;

        }
    }

    // teardown

    return 0;
}

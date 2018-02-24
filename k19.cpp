#include <iostream>
#include <Clock.h>


#include "globals.h"

int main() {

    CPUObject::debug |= CPUObject::trace | CPUObject::memload;
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
    xr.connectsTo(abus.IN());
    xr.connectsTo(abus.OUT());

    ir.connectsTo(dbus.IN());
    ir.connectsTo(dbus.OUT());






    // run
    int count = 0;

    while (!halt){

        cout << "latch from read" << endl;
        abus.IN().pullFrom(ic);
        m.MAR().latchFrom(abus.OUT());
        m.read();
        mdr.latchFrom(m.READ());
        Clock::tick();


        count ++;
        if (count > 10){
            halt = true;

        }
    }

    // teardown

    return 0;
}

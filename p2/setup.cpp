//
// Created by benjamin on 3/24/18.
//

#include "setup.h"
#include "globals.h"

void setup(){
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
    m.MAR().connectsTo(alu.OP1());

    // whyyyyyy
    xr.connectsTo(m.READ());
    xr.connectsTo(m.WRITE());
    xr.connectsTo(dbus.OUT());

    m.MAR().connectsTo(dbus.IN());
    ic.connectsTo(dbus.OUT());
    a.connectsTo(m.WRITE());
    b.connectsTo(m.WRITE());


}

//
// Created by benjamin on 3/24/18.
//

#include "setup.h"
#include "globals.h"

void setup(){
    for( int ii = 0; ii < NUM_REGS; ii++){
        regs.push_back(new Clearable("r"+ii, DATA_BITS));
        regs[ii]->connectsTo(dbus.OUT());
        regs[ii]->connectsTo(dbus.IN());
        regs[ii]->connectsTo(abus.OUT());
        regs[ii]->connectsTo(abus.IN());
        regs[ii]->connectsTo(alu.OP1());
        regs[ii]->connectsTo(alu.OP2());
        regs[ii]->connectsTo(alu.OUT());
        regs[ii]->connectsTo(sbus.IN());
        regs[ii]->connectsTo(sbus.OUT());
    }
    regs[7]->connectsTo(m.READ());



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

    // ic, ir, and xr
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
    se_mask_12.connectsTo(alu.OP2());
    m.MAR().connectsTo(alu.OP1());

    // whyyyyyy
    xr.connectsTo(m.READ());
    xr.connectsTo(m.WRITE());
    xr.connectsTo(dbus.OUT());

    m.MAR().connectsTo(dbus.IN());

    ddd.connectsTo(sbus.OUT());
    ddd.connectsTo(sbus.IN());
    sss.connectsTo(sbus.OUT());
    sss.connectsTo(sbus.IN());
    ddd.connectsTo(m.READ());
    sss.connectsTo(m.READ());


    N.connectsTo(bitbus.OUT());
    Z.connectsTo(bitbus.OUT());
    V.connectsTo(bitbus.OUT());
    C.connectsTo(bitbus.OUT());
    C.connectsTo(alu.CARRY());
    V.connectsTo(alu.OFLOW());
    const_1.connectsTo(bitbus.IN());


}

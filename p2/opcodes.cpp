//
// Created by benjamin on 3/27/18.
//

#include <Clock.h>
#include <bitset>
#include "opcodes.h"
#include "globals.h"

void setbit(Clearable & s, bool val){
    if (val){
        s.latchFrom(bitbus.OUT());
    }
    else{
        s.clear();
    }
}

void clear() {
    out.clear();
    N.clear();
    bitbus.IN().pullFrom(const_1);
    Z.latchFrom(bitbus.OUT());
    V.clear();
    C.clear();
    Clock::tick();
    do_writeback = true;
}

void mov() {
    sbus.IN().pullFrom(sss);
    out.latchFrom(sbus.OUT());
    bitbus.IN().pullFrom(const_1);
    setbit(N, sss(DATA_BITS - 1) == 1);
    setbit(Z, sss.uvalue() == 0);
    setbit(V, false);
    Clock::tick();
}

void add() {
    alu.perform(BusALU::op_add);
    alu.OP1().pullFrom(ddd);
    alu.OP2().pullFrom(sss);
    out.latchFrom(alu.OUT());
    V.latchFrom(alu.OFLOW());
    C.latchFrom(alu.CARRY());
    Clock::tick();

    bitbus.IN().pullFrom(const_1);
    setbit(N, out(DATA_BITS - 1) == 1);
    setbit(Z, out.uvalue() == 0);

}

void sub() {
    alu.perform(BusALU::op_sub);
    alu.OP1().pullFrom(ddd);
    alu.OP2().pullFrom(sss);
    out.latchFrom(alu.OUT());
    Clock::tick();
    /*
     * 	sub*	N <- result < 0
		Z <- result == 0
		V <- opnds had different signs & result has sign of (src)
		C <- (dst) + ~(src) + 1 < 2^16
     */

    bitbus.IN().pullFrom(const_1);
    setbit(N, out(DATA_BITS - 1) == 1);
    setbit(Z, out.uvalue() == 0);
    setbit(V, ((ddd(DATA_BITS-1) ^ sss(DATA_BITS-1)) == 1) && (sss(DATA_BITS-1) == out(DATA_BITS-1)));
//    cout << (ddd.uvalue()) << " " << (~(sss.uvalue()) & 0xFFFF) << " " << (1 << 16) << endl;
    setbit(C, ((ddd.uvalue()) + (~(sss.uvalue()) & 0xFFFF) + 1) < 1<<16);

}

void bgt() {
    // BGT	0030vv	0 000 011 0vv vvv vvv	Branch on >
    // bgt	0030vv	if( !Z & (N == V) ) PC <- PC + 2*vv
    imm = true;
    immediate = (char) ir(7, 0);
//    cout <<dec << immediate<<endl;
    cout <<bitset<8>(immediate)<<endl;
    // sign extend
//    if (immediate & 1<<7){
//        immediate |= 0b1111111110000000;
//    }
//    cout <<dec << immediate<<endl;
    immediate *= 2;
//    cout <<dec << immediate<<endl;
    if ( Z.uvalue() == 0 && (N.uvalue() == V.uvalue())){
        regs[7]->backDoor((short)regs[7]->uvalue() + immediate);
    }
    Clock::tick();



}

void pass() {

}






























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
    Clock::tick();

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
    setbit(N, out() == 1);
    setbit(Z, out.uvalue() == 0);
    setbit(V, ((ddd() ^ sss()) == 1) && (sss() == out()));
//    cout << (ddd.uvalue()) << " " << (~(sss.uvalue()) & 0xFFFF) << " " << (1 << 16) << endl;
    setbit(C, ((ddd.uvalue()) + (~(sss.uvalue()) & 0xFFFF) + 1) < 1<<16);
    Clock::tick();

}

void bgt() {
    // BGT	0030vv	0 000 011 0vv vvv vvv	Branch on >
    // bgt	0030vv	if( !Z & (N == V) ) PC <- PC + 2*vv
    imm = true;
    immediate = (char) ir(7, 0);
//    cout <<dec << immediate<<endl;
//    cout <<bitset<8>(immediate)<<endl;
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

void cmp() {
    alu.perform(BusALU::op_sub);
    alu.OP1().pullFrom(sss);
    alu.OP2().pullFrom(ddd);
    out.latchFrom(alu.OUT());
//    cout << out<< endl;
    Clock::tick();
//    cout << out<< endl;
    dest.writeback = false;
    /* "result" is (src) - (dst)
     * 	N <- result < 0
		Z <- result == 0
		V <- opnds had different signs & result has sign of (dst)
		C <- (src) + ~(dst) + 1 < 2^16
     sub*	N <- result < 0
		Z <- result == 0
		V <- opnds had different signs & result has sign of (src)
		C <- (dst) + ~(src) + 1 < 2^16
     */

    bitbus.IN().pullFrom(const_1);
    setbit(N, out() == 1);
//    cout << bitset<16>(sss.uvalue())<< " " << bitset<16>(sss.uvalue()) << endl;
//    cout << (short) sss.uvalue() - (short) ddd.uvalue() << endl;
//    cout << sss<< endl;
//    cout << ddd<< endl;
//    cout << out<< endl;
    setbit(Z, out.uvalue() == 0);
    setbit(V, ((ddd() ^ sss()) == 1) && (ddd() == out()));
//    cout << (ddd.uvalue()) << " " << (~(sss.uvalue()) & 0xFFFF) << " " << (1 << 16) << endl;
    setbit(C, ((sss.uvalue()) + (~(ddd.uvalue()) & 0xFFFF) + 1) < 1<<16);
    Clock::tick();

}






























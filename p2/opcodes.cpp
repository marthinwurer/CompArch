//
// Created by benjamin on 3/27/18.
//

#include <Clock.h>
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
    Z.clear();
    bitbus.IN().pullFrom(const_1);
    V.latchFrom(bitbus.OUT());
    C.clear();
    Clock::tick();
    do_writeback = true;
}

void mov() {
    sbus.IN().pullFrom(sss);
    out.latchFrom(sbus.OUT());
    setbit(N, sss(DATA_BITS - 1) == 1);
    setbit(Z, sss.uvalue() == 0);
    setbit(V, false);
    Clock::tick();
}

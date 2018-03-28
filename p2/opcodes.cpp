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
    setbit(N, sss(DATA_BITS - 1) == 1);
    setbit(Z, sss.uvalue() == 0);
    setbit(V, false);
    Clock::tick();
}

//
// Created by benjamin on 3/27/18.
//

#include <Clock.h>
#include "opcodes.h"
#include "globals.h"

void clear() {
    out.clear();
    N.clear();
    bitbus.IN().pullFrom(const_1);
    V.latchFrom(bitbus.OUT());
    C.clear();
    Z.clear();
    Clock::tick();
    do_writeback = true;
}

//
// Created by benjamin on 2/19/18.
//

#include "globals.h"
const unsigned int ADR_BITS = 12;
const unsigned int DATA_BITS = 20;

Bus abus("ABUS", ADR_BITS);
Bus dbus("DBUS", DATA_BITS);

StorageObject a("A", DATA_BITS);
StorageObject b("B", DATA_BITS);
StorageObject mdr("MDR", DATA_BITS);
StorageObject ir("IR", DATA_BITS);
StorageObject xr("XR", ADR_BITS);
Counter ic("IC", ADR_BITS);
Memory m("m", ADR_BITS, DATA_BITS);
BusALU alu("ALU", DATA_BITS);

bool halt(false);

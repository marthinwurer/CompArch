//
// Created by benjamin on 2/19/18.
//

#include "globals.h"
const unsigned int ADR_BITS = 12;
const unsigned int DATA_BITS = 20;

Bus abus("ABUS", ADR_BITS); // address bus. Used when addresses are to be moved.
Bus dbus("DBUS", DATA_BITS); // Data Bus. Used when data and instructions are to be moved.

StorageObject a("A", DATA_BITS); // Accumulator A
StorageObject b("B", DATA_BITS); // Accumulator B
StorageObject mdr("MDR", DATA_BITS); // Data to be written into, or data most recently read from, memory.
StorageObject ir("IR", DATA_BITS); // Instruction Register. Instruction being decoded and executed.
StorageObject xr("XR", ADR_BITS); // Index register. Contains a value to be used in calculating a memory address.
Counter ic("IC", ADR_BITS); // PC. Address of the next instruction to be fetched, decoded, and executed.
Memory m("m", ADR_BITS, DATA_BITS); // Memory
BusALU alu("ALU", DATA_BITS); // ALU

bool halt(false);

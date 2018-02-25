//
// Created by benjamin on 2/19/18.
//

#include <iomanip>
#include "globals.h"
const unsigned int ADR_BITS = 12;
const unsigned int DATA_BITS = 20;

Bus abus("ABUS", ADR_BITS); // address bus. Used when addresses are to be moved.
Bus dbus("DBUS", DATA_BITS); // Data Bus. Used when data and instructions are to be moved.

Clearable a("A", DATA_BITS); // Accumulator A
Clearable b("B", DATA_BITS); // Accumulator B
StorageObject mdr("MDR", DATA_BITS); // Data to be written into, or data most recently read from, memory.
StorageObject ir("IR", DATA_BITS); // Instruction Register. Instruction being decoded and executed.
StorageObject xr("XR", ADR_BITS); // Index register. Contains a value to be used in calculating a memory address.
Counter ic("IC", ADR_BITS); // PC. Address of the next instruction to be fetched, decoded, and executed.
Memory m("Memory", ADR_BITS, DATA_BITS); // Memory
BusALU alu("ALU", DATA_BITS); // ALU
BusALU addr_alu("A_ALU", ADR_BITS); // ALU

StorageObject se_mask_12("SE12", ADR_BITS, 0x800);

bool halt(false);

// globals for trace printing
ulong pc, instruction, addr, A, B, XR;
bool print_addr;
string mnemonic;


void print_trace() {

    cout << setfill('0') << setw(3) << hex << pc << ":  ";
    cout << setfill('0') << setw(5) << hex << instruction << "  ";
    cout << setfill(' ') << left << setw(6) << mnemonic << right;
    if (print_addr){
        cout << setfill('0') << setw(3) << hex << addr << "  ";
    } else {
        cout << "     ";
    }

    cout << "A[" << setfill('0') << setw(5) << hex << A << "]  ";
    cout << "B[" << setfill('0') << setw(5) << hex << B << "]  ";
    cout << "XR[" << setfill('0') << setw(3) << hex << XR << "]" << endl;
}

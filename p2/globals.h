//
// Created by benjamin on 2/19/18.
//

#ifndef P1_GLOBALS_H
#define P1_GLOBALS_H


#include <vector>
#include <Bus.h>
#include <Counter.h>
#include <Memory.h>
#include <BusALU.h>
#include <Clearable.h>

typedef unsigned long ulong;

extern const unsigned int ADR_BITS;
extern const unsigned int DATA_BITS;
extern const unsigned int NUM_REGS;

extern Bus abus;
extern Bus dbus;
extern Bus sbus; // Setup Bus. Used to set up the operands

extern vector<Clearable*> regs;

extern Clearable ps;
extern Clearable op1;
extern Clearable op2;
extern Clearable out;
extern StorageObject mdr;
extern StorageObject xr;
extern StorageObject ir;
extern Memory m;
extern BusALU alu;
extern BusALU addr_alu; // ALU

extern bool halt, do_writeback;

extern StorageObject se_mask_12, const_2;
extern ulong pc, instruction, addr, A, B, XR;
extern bool print_addr, bad_addr;
extern string mnemonic;


void print_trace();



#endif //P1_GLOBALS_H

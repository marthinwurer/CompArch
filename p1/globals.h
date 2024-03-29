//
// Created by benjamin on 2/19/18.
//

#ifndef P1_GLOBALS_H
#define P1_GLOBALS_H


#include <Bus.h>
#include <Counter.h>
#include <Memory.h>
#include <BusALU.h>
#include <Clearable.h>

typedef unsigned long ulong;

extern const unsigned int ADR_BITS;
extern const unsigned int DATA_BITS;

extern Bus abus;
extern Bus dbus;

extern Clearable a;
extern Clearable b;
extern StorageObject mdr;
extern StorageObject xr;
extern StorageObject ir;
extern Counter ic;
extern Memory m;
extern BusALU alu;
extern BusALU addr_alu; // ALU

extern bool halt;

extern StorageObject se_mask_12;
extern ulong pc, instruction, addr, A, B, XR;
extern bool print_addr, bad_addr;
extern string mnemonic;


void print_trace();



#endif //P1_GLOBALS_H

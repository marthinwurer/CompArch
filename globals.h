//
// Created by benjamin on 2/19/18.
//

#ifndef P1_GLOBALS_H
#define P1_GLOBALS_H


#include <Bus.h>
#include <Counter.h>
#include <Memory.h>
#include <BusALU.h>

extern const unsigned int ADR_BITS;
extern const unsigned int DATA_BITS;

extern Bus abus;
extern Bus dbus;

extern StorageObject a;
extern StorageObject b;
extern StorageObject mdr;
extern StorageObject xr;
extern StorageObject ir;
extern Counter ic;
extern Memory m;
extern BusALU alu;

extern bool halt;



#endif //P1_GLOBALS_H
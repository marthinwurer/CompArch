//
// Created by benjamin on 3/26/18.
//

#include <bitset>
#include <Clock.h>
#include "decode.h"
#include "addressing.h"
#include "opcodes.h"

void opcode_error(){
    mnemonic = "????";
    print_addr = false;
    throw ArchLibError("undefined opcode");
}

void decode(ulong category) {
    cout << "cat " << bitset<3>(category) << endl; // todo

    ulong s_am = ir.uvalue() >> 9 & 0b111;
    ulong s_reg = ir.uvalue() >> 6 & 0b111;
    ulong am = ir.uvalue() >> 3 & 0b111;
    ulong reg = ir.uvalue() & 0b111;

    switch (category){
        case 000:
            // other instruction
            cout << "decoding other" << endl;
            decode_other();
            break;
        case 001:
            // mov
            operation = mov;
            mnemonic = "MOV";
            calc_addressing(s_am, s_reg, src);
            calc_addressing(am, reg, dest);
            break;
        case 002:
            // cmp
            opcode_error();
            break;
        case 006:
            // add
            opcode_error();
            break;
        case 007:
            // sob
            opcode_error();
            break;
        case 010:
            // a non-relational conditional branch instruction
            opcode_error();
            break;
        case 016:
            // sub
            opcode_error();
            break;
        default:
            // todo
            cout << bitset<3>(category) << endl;
            opcode_error();
    }

}

void decode_other() {
    // get the next bits
    ulong next = ir.uvalue() >> 9 & 0b111;
    cout << "next " << bitset<3>(next) << endl; // todo


    switch (next){
        case 00:
            // a zero-operand instruction, br, rts, or jmp
            opcode_error();
            break;
        case 01:
            opcode_error();
            break;
        case 02:
            opcode_error();
            break;
        case 03:
            opcode_error();
            break;
        case 04:
            opcode_error();
            break;
        case 05:
//            cout << "clr, com, inc, dec, neg, or tst" << endl; // todo
            decode_1_op();
            break;
        default:
            // todo
            cout << "000" << bitset<3>(next) << endl;
            opcode_error();
    }

}

/**
CLR	0050dd	0 000 101 000 ddd ddd	Clear
COM	0051dd	0 000 101 001 ddd ddd	Complement
INC	0052dd	0 000 101 010 ddd ddd	Increment
DEC	0053dd	0 000 101 011 ddd ddd	Decrement
NEG	0054dd	0 000 101 100 ddd ddd	Negate
TST	0057dd	0 000 101 111 ddd ddd	Test
 */
void decode_1_op() {
    ulong opcode = ir.uvalue() >> 6 & 0b111;
    cout << "opcode " << bitset<3>(opcode) << endl; // todo
    ulong am = ir.uvalue() >> 3 & 0b111;
    ulong reg = ir.uvalue() & 0b111;

    // latch the data to a register
    calc_addressing(am, reg, dest);


    switch (opcode){
        case 0b000:
            operation = clear;
            mnemonic = "CLR";
            break;
        case 0b001:
            opcode_error();
            break;
        case 0b010:
            opcode_error();
            break;
        case 0b011:
            opcode_error();
            break;
        case 0b100:
            opcode_error();
            break;
        case 0b111:
            opcode_error();
            break;
        default:
            opcode_error();
            break;
    }


}

//
// Created by benjamin on 2/24/18.
//

#include <Clock.h>
#include <bitset>
#include "opcodes.h"

StorageObject * get_reg(bool reg){
    if( reg){
        return & b;
    }else{
        return & a;
    }
}

string reg_name(bool reg){
    return reg ? "B":"A";
}

/**
 * LDx	Load the indicated register from memory.
 * @param reg
 */
void ldx(bool reg){
    print_addr = true;
    mnemonic = "LD" + reg_name(reg);

    StorageObject & curr = *get_reg(reg);

    dbus.IN().pullFrom(mdr);
    curr.latchFrom(dbus.OUT());
    Clock::tick();
}

/**
 * STx	Store the indicated register into memory.
 * @param reg
 */
void stx(bool reg) {
    print_addr = true;
    mnemonic = "ST" + reg_name(reg);

    StorageObject &curr = *get_reg(reg);
    m.WRITE().pullFrom(curr);
    m.write();
    Clock::tick();
}

/**
 * EMx	Exchange the indicated register with memory.
 * @param reg
 */
void emx(bool reg) {
    print_addr = true;
    mnemonic = "EM" + reg_name(reg);

    StorageObject &curr = *get_reg(reg);
    m.WRITE().pullFrom(curr);
    m.write();
    dbus.IN().pullFrom(mdr);
    curr.latchFrom(dbus.OUT());
    Clock::tick();
}

/**
 * ADDx	Add memory to the indicated register.
 * @param reg
 */
void addx(bool reg) {
    print_addr = true;
    mnemonic = "ADD" + reg_name(reg);

    StorageObject &curr = *get_reg(reg);

    curr.latchFrom(alu.OUT());
    alu.OP1().pullFrom(curr);
    alu.OP2().pullFrom(mdr);
    alu.perform(BusALU::Operation::op_add);
    Clock::tick();
}

/**
 * execute an opcode
 * @param opcode
 * @param am - the addressing mode. used to check if the
 */
void exec_opcode(ulong opcode, ulong am) {

    bool reg = (opcode & 0b1) == 0b1;
    opcode = opcode >> 1;

    switch (opcode){
        case 0b00000:
            mnemonic = "HALT";
            print_addr = false;

            throw ArchLibError("HALT instruction executed");
            break;
        case 0b00001:
            break;
        case 0b01000:
            ldx(reg);
            break;
        case 0b01001:
            stx(reg);
            break;
        case 0b01010:
            emx(reg);
            break;

        case 0b10000:
            addx(reg);
            break;


        default:
            // todo
            cout << bitset<6>((opcode << 1) | (reg?0b1:0b0)) << endl;
            mnemonic = "????";
            print_addr = false;
            throw ArchLibError("undefined opcode");
    }

}

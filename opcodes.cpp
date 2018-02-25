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
 * LIx	Load the indicated register with the sign-extended contents of the address field (i.e., treat it as data).
 * @param reg
 */
void lix(bool reg) {
    print_addr = true;
    mnemonic = "LI" + reg_name(reg);

    // get a mask for the sign bit

    StorageObject &curr = *get_reg(reg);

    curr.latchFrom(alu.OUT());
    alu.OP1().pullFrom(curr);
    alu.OP2().pullFrom(se_mask_12);
    alu.perform(BusALU::Operation::op_extendSign);
    Clock::tick();
}

/**
 * LDXR	Load the XR from memory.
 * @param reg
 */
void ldxr(){
    print_addr = true;
    mnemonic = "LDXR";

    dbus.IN().pullFrom(mdr);
    xr.latchFrom(dbus.OUT());
    Clock::tick();
}

/**
 * LIXR	Load the XR with the contents of the address field.
 * @param reg
 */
void lixr(){
    print_addr = true;
    mnemonic = "LIXR";

    dbus.IN().pullFrom(m.MAR());
    xr.latchFrom(dbus.OUT());
    Clock::tick();
}

/**
 * STXR	Store the XR into memory.
 * @param reg
 */
void stxr() {
    print_addr = true;
    mnemonic = "STXR";

    m.WRITE().pullFrom(xr);
    m.write();
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

void handle_invalid(ulong opcode, bool reg){
    //# todo
    cout << bitset<6>((opcode << 1) | (reg?0b1:0b0)) << endl;
    mnemonic = "????";
    print_addr = false;
    throw ArchLibError("undefined opcode");
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
            if(reg) handle_invalid(opcode, reg);
            mnemonic = "HALT";
            print_addr = false;


            throw ArchLibError("HALT instruction executed");
            break;
        case 0b00001:
            if(reg) handle_invalid(opcode, reg);
            print_addr = true;
            mnemonic = "NOP";
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
        case 0b01011:
            if (am != 0b00){
                print_addr = false;
                mnemonic = "???";
                throw ArchLibError("illegal addressing mode");
            }
            lix(reg);
            break;

        case 0b01100:
            if(reg) handle_invalid(opcode, reg);
            ldxr();
            break;
        case 0b01101:
            if(reg) handle_invalid(opcode, reg);
            lixr();
            break;
        case 0b01110:
            if(reg) handle_invalid(opcode, reg);
            stxr();
            break;


        case 0b10000:
            addx(reg);
            break;


        default:
            // todo
            handle_invalid(opcode,reg);
    }

}

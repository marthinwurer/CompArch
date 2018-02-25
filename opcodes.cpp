//
// Created by benjamin on 2/24/18.
//

#include <Clock.h>
#include <bitset>
#include "opcodes.h"

Clearable * get_reg(bool reg){
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
    alu.OP1().pullFrom(m.MAR());
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

/**
 * SUBx	Subtract memory from the indicated register.
 * @param reg
 */
void subx(bool reg) {
    print_addr = true;
    mnemonic = "SUB" + reg_name(reg);

    StorageObject &curr = *get_reg(reg);

    curr.latchFrom(alu.OUT());
    alu.OP1().pullFrom(curr);
    alu.OP2().pullFrom(mdr);
    alu.perform(BusALU::Operation::op_sub);
    Clock::tick();
}

/**
 * CLRx	Clear the indicated register.
 * @param reg
 */
void clrx(bool reg) {
    print_addr = false;
    mnemonic = "CLR" + reg_name(reg);

    Clearable &curr = *get_reg(reg);

    curr.clear();
    Clock::tick();
}

/**
 * COMx	Complement the indicated register.
 * @param reg
 */
void comx(bool reg) {
    print_addr = false;
    mnemonic = "COM" + reg_name(reg);

    StorageObject &curr = *get_reg(reg);

    curr.latchFrom(alu.OUT());
    alu.OP1().pullFrom(curr);
    alu.perform(BusALU::Operation::op_not);
    Clock::tick();
}

/**
 * ANDx	AND memory to the indicated register.
 * @param reg
 */
void andx(bool reg) {
    print_addr = true;
    mnemonic = "AND" + reg_name(reg);

    StorageObject &curr = *get_reg(reg);

    curr.latchFrom(alu.OUT());
    alu.OP1().pullFrom(curr);
    alu.OP2().pullFrom(mdr);
    alu.perform(BusALU::Operation::op_and);
    Clock::tick();
}

/**
 * ORx	OR memory to the indicated register.
 * @param reg
 */
void orx(bool reg) {
    print_addr = true;
    mnemonic = "OR" + reg_name(reg);

    StorageObject &curr = *get_reg(reg);

    curr.latchFrom(alu.OUT());
    alu.OP1().pullFrom(curr);
    alu.OP2().pullFrom(mdr);
    alu.perform(BusALU::Operation::op_or);
    Clock::tick();
}

/**
 * XORx	XOR memory to the indicated register.
 * @param reg
 */
void xorx(bool reg) {
    print_addr = true;
    mnemonic = "XOR" + reg_name(reg);

    StorageObject &curr = *get_reg(reg);

    curr.latchFrom(alu.OUT());
    alu.OP1().pullFrom(curr);
    alu.OP2().pullFrom(mdr);
    alu.perform(BusALU::Operation::op_xor);
    Clock::tick();
}

/**
 * TR	Transfer to the memory address.
 */
void tr(){
    print_addr = true;
    mnemonic = "TR";

    dbus.IN().pullFrom(m.MAR());
    ic.latchFrom(dbus.OUT());
    Clock::tick();
}

/**
 * TZx	Transfer to the memory address if the indicated register contains zero.
 */
bool tzx(bool reg){
    print_addr = true;
    mnemonic = "TZ" + reg_name(reg);

    StorageObject &curr = *get_reg(reg);

    bool flag = false;
    if(curr.uvalue() == 0){
        flag = true;
        dbus.IN().pullFrom(m.MAR());
        ic.latchFrom(dbus.OUT());
    }
    Clock::tick();
    return flag;
}

/**
 * TNx	Transfer to the memory address if the indicated register contains a negative number.
 */
bool tnx(bool reg){
    print_addr = true;
    mnemonic = "TN" + reg_name(reg);

    StorageObject &curr = *get_reg(reg);

    bool flag = false;
    if(curr.uvalue() & 0x80000){ // the sign bit for 20 bits
        flag = true;
        dbus.IN().pullFrom(m.MAR());
        ic.latchFrom(dbus.OUT());
    }
    Clock::tick();
    return flag;
}

/**
 * TPx	Transfer to the memory address if the indicated register a positive number.
 */
bool tpx(bool reg){
    print_addr = true;
    mnemonic = "TP" + reg_name(reg);

    StorageObject &curr = *get_reg(reg);

    bool flag = false;
    if(!(curr.uvalue() & 0x80000) and curr.uvalue() > 0){ // the sign bit for 20 bits
        flag = true;
        dbus.IN().pullFrom(m.MAR());
        ic.latchFrom(dbus.OUT());
    }
    Clock::tick();
    return flag;
}

void handle_invalid(ulong opcode, bool reg){
    //# todo
//    cout << bitset<6>((opcode << 1) | (reg?0b1:0b0)) << endl;
    mnemonic = "????";
    print_addr = false;
    throw ArchLibError("undefined opcode");
}

/**
 * execute an opcode
 * @param opcode
 * @param am - the addressing mode. used to check if the
 * @return whether to skip increment of ic
 */
bool exec_opcode(ulong opcode, ulong am) {
    bad_addr = false;

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
                mnemonic = "LI" + reg_name(reg);
                bad_addr = true;
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
        case 0b10001:
            subx(reg);
            break;
        case 0b10010:
            clrx(reg);
            break;
        case 0b10011:
            comx(reg);
            break;

        case 0b10100:
            andx(reg);
            break;
        case 0b10101:
            orx(reg);
            break;
        case 0b10110:
            xorx(reg);
            break;

        case 0b11000:
            if(reg) handle_invalid(opcode, reg);
            tr();
            return true;
        case 0b11001:
            return tzx(reg);
        case 0b11010:
            return tnx(reg);
        case 0b11011:
            return tpx(reg);


        default:
            // todo
            handle_invalid(opcode,reg);
    }
    return false;

}

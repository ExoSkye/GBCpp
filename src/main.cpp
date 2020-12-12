//
// Created by protobit on 11/12/2020.
//

/**
 * Main function
 * @param argc
 * @param argv
 * @return process ret value
 */

#include <iostream>
#include "memory.hpp"
#include "op_decode/macros.hpp"

int main(int argc, char *argv[]) {
    int retval = 0;
    memory mem = memory(8192);
    mem[0] = 62;
    mem[4096] = 169;
    if (mem[0] == 62 && mem[4096] == 169) {
        printf("%s","Memory test completed successfully");
    }
    else {
        retval++;
    }
    registers regs{.A = 0b11111111};
    registers16 reg16s{.AF = reg16(&regs.A,&regs.F),
            .BC = reg16(&regs.B,&regs.C),
            .DE = reg16(&regs.D,&regs.E),
            .HL = reg16(&regs.H,&regs.L)};
    flags flags_struct{};
    regs.H = 8;
    regs.L = 8;
    decoder testdecode;
    testdecode.registerOps();
    testdecode.runInstruction(0x8E,0,&flags_struct,&regs,&reg16s);
    return retval;
}
//
// Created by protobit on 11/12/2020.
//

#ifndef GBCPP_MACROS_H
#define GBCPP_MACROS_H

#include "../common/common.hpp"
#include <functional>

class decoder {
    std::function<void(int64_t,flags*,registers*,registers16*)> op_array[0xFF];
public:
    void registerOps() {
#define startOpcode(number) op_array[number] = [](int64_t extra,flags* flags,registers* regs,registers16* reg16){
#define opCode(code) code;
#define endOpcode() };
#define extra8 extra & 0b0000000000000000000000000000000000000000000000000000000011111111
#define extra16 extra & 0b0000000000000000000000000000000000000000000000001111111111111111

#include "opcodes.inl"
#undef startOpcode
#undef opCode
#undef endOpcode
#undef extra8
    }
    void runInstruction(int index,int64_t extra,flags* flags,registers* regs,registers16* reg16) {
#ifdef _DEBUG
        printf("Executing instruction %X\n",index);
#endif
        if (!op_array[index]) {
#ifdef _DEBUG
            printf("Instruction not implemented\n");
#endif
        }
        else {
            op_array[index](extra, flags, regs, reg16);
        }
    }
};
#endif //GBCPP_MACROS_H

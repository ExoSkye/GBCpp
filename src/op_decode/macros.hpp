//
// Created by protobit on 11/12/2020.
//

#ifndef GBCPP_MACROS_H
#define GBCPP_MACROS_H

#include "../common/common.hpp"

#define startOpcode(name) void #name(int8_t*,int64_t,flags*,registers*,registers16*) {
#define opCode(code) code
#define endOpcode() }


class decoder {
    void (*func_array[0xFF])(int8_t*,int64_t,flags*,registers*,registers16*) {};
};
#endif //GBCPP_MACROS_H

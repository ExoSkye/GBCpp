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

int main(int argc, char *argv[]) {
    memory mem = memory(8192);
    mem[0] = 62;
    mem[4096] = 169;
    if (mem[0] == 62 && mem[4096] == 169) {
        printf("%s","Memory test completed successfully");
        return 0;
    }
    return 1;
}
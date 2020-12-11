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

byte *memory;

int main(int argc, char *argv[]) {
    memory = init_memory();
    if (memory == NULL)
    {
        
        std::cout << "Couldn't initialize memory" << std::endl;
    }
    else {
        std::cout << "Initialized 8KiB of memory" << std::endl;
    }
    deinit_memory(memory);
    return 0;
}
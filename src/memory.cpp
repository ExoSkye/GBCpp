#include "memory.hpp"
#include <stdlib.h>

byte *init_memory() {
    byte *memory = (byte*) calloc(sizeof(byte), 8192);
    return memory;
}

void deinit_memory(byte *memory) {
    free(memory);
}
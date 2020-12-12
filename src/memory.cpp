#include "memory.hpp"

#pragma warning(disable: 4172)

memory::memory(int size) {
    _size = size;
    _memory = (byte*) calloc(sizeof(byte), size);
    if (_memory == nullptr) {
        printf("%s","FATAL ERROR: Allocation failed");
    }
}

memory::~memory() {
    free(_memory);
}

byte &memory::operator[](int index) {
    if (index < _size) {
        return _memory[index];
    }
    else {
        printf("%s","NON-FATAL ERROR: Tried to access memory out of bounds, returning NULL");
        byte a = (byte)0;
        return a;
    }
}

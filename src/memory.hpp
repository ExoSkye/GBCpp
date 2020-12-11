#ifndef GBCPP_MEMORY_H
#define GBCPP_MEMORY_H

#include "common/common.hpp"
#include <cstdlib>
#include <cstdio>

class memory {
private:
    byte* _memory;
    int _size;
public:
    explicit memory(int size);
    memory() = delete;
   ~memory();
   byte& operator[](int index);
};
#endif
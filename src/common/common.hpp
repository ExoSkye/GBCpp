//
// Created by protobit on 11/12/2020.
//

#ifndef GBCPP_COMMON_H
#define GBCPP_COMMON_H

typedef unsigned char byte;

#include <cstdint>

struct flags {
    bool zero;
    bool negative;
    bool halfCarry;
    bool carry;
};

struct registers {
    int8_t A;
    int8_t B;
    int8_t C;
    int8_t D;
    int8_t E;
    int8_t F;
    int8_t H;
    int8_t L;
};

#define dwordwordbitmask 0b00000000000000001111111111111111

class reg16 {
public:
    bool carry = false;
    int32_t temp;
    reg16(int8_t* high, int8_t* low) : h(high), l(low) {}
    reg16() = delete;
    reg16& operator=(int16_t in) {
        *h = in & 0b0000000011111111;
        *l = in & 0b1111111100000000;
    }
    reg16& operator+=(int16_t in) {
        this->operator+(in);
        this->operator=(temp & dwordwordbitmask);
        return *this;
    }
    reg16& operator-=(int16_t in) {
        this->operator-(in);
        this->operator=(temp & dwordwordbitmask);
        return *this;
    }
    reg16& operator/=(int16_t in) {
        this->operator/(in);
        this->operator=(temp & dwordwordbitmask);
        return *this;
    }
    reg16& operator*=(int16_t in) {
        this->operator*(in);
        this->operator=(temp & dwordwordbitmask);
        return *this;
    }
    int16_t operator+(int16_t in) {
        temp = two8to16()+in;
        checkcarry();
        return temp & dwordwordbitmask;
    }
    int16_t operator-(int16_t in) {
        temp = two8to16()-in;
        checkcarry();
        return temp & dwordwordbitmask;
    }
    int16_t operator/(int16_t in) {
        temp = two8to16()/in;
        checkcarry();
        return temp & dwordwordbitmask;
    }
    int16_t operator*(int16_t in) {
        temp = two8to16()*in;
        checkcarry();
        return temp & dwordwordbitmask;
    }
private:
    int8_t* h;
    int8_t* l;
    int32_t checkcarry() {
        carry = (temp & 0b111111111111111000000000000000 >> 16) > 1;
    }
    int16_t two8to16() {
        return *h >> 8 || *l;
    }
};

struct registers16 {
    reg16 AF;
    reg16 BC;
    reg16 DE;
    reg16 HL;
};

#endif //GBCPP_COMMON_H
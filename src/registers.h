#pragma once
#include <iostream>

struct Register{
    union {
        uint16_t value;
        struct{
            uint8_t low: 8;
            uint8_t high: 8;
        };
    };

    Register& operator+=(const uint16_t& rhs){
        this->value = rhs;
        return *this;
    }

    Register& operator=(const uint16_t& rhs){
        this->value = rhs;
        return *this;
    }
};

struct CpuRegisters {
    Register AF;
    Register BC;
    Register DE;
    Register HL;
    Register SP;
    Register PC;

    const uint8_t FLAG_CARRY = 0b00010000;
    const uint8_t FLAG_HALF_CARRY = 0b00100000;
    const uint8_t FLAG_SUBSTRACT = 0b01000000;
    const uint8_t FLAG_ZERO = 0b10000000;
};
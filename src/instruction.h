#pragma once
#include <iostream>
struct Instruction {
    const char* mnemonic;
    const char* opcode;
    const uint8_t size;
    const uint8_t cycles;
    void (*callback)();
};
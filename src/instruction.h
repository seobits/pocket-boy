#pragma once
#include <iostream>
#include "registers.h"

struct Instruction {
    const char* mnemonic;
    const int opcode;
    const uint8_t size;
    const uint8_t cycles;
    void (*function)(CpuRegisters&);
};

struct InstructionSet {
    public:
        const Instruction list[0xFF] = {
            "NOP", 0x00, 2, 1, &InstructionSet::_0x00_nop
        };
    
    private:
        static inline void _0x00_nop(CpuRegisters& reg){}
};
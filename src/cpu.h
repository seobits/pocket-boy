#pragma once
#include <iostream>
#include "registers.h"
#include "instruction.h"

class Cpu {
    public: 
        CpuRegisters registers;
        Cpu();
        void Execute(const uint8_t& opcode);
    private: 
        const InstructionSet _instructionSet;
};
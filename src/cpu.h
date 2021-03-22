#pragma once
#include <iostream>
#include "registers.h"
#include "instruction.h"

class Cpu {
    public: 
        Cpu();
        CpuRegisters registers;
        void Execute(MemoryManagementUnit& mmu);
    private: 
        const InstructionSet _instructionSet;
        uint16_t _cycleCounter = 0;
};
#pragma once
//#include <iostream>
#include "registers.h"
#include "instruction.h"
#include "instruction_set.h"

struct CpuRegisters {
    Register AF;
    Register BC;
    Register DE;
    Register HL;
    Register SP;
    Register PC;
};

class CPU {
    public: 
        CPU();
    private: 
        CpuRegisters* _registers;
        const Instruction* _instructionSet;
};
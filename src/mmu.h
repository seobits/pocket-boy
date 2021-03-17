#pragma once
#include "memory.h"
#include "instruction.h"
#include "registers.h"

class MemoryManagementUnit{
    public:
        uint8_t fetchOpcode(const Register& pcRegister);
    private:
        Memory _memory;
};
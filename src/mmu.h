#pragma once
#include "memory.h"
#include "registers.h"

class MemoryManagementUnit{
    public:
        uint8_t* readFromMemory(const uint16_t& address);
        void writeToMemory(const uint16_t& address, uint8_t data);
    private:
        Memory _memory;
};
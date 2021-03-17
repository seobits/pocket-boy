#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "cpu.h"
#include "mmu.h"

class PocketBoy {
    public:
        PocketBoy();
        void Boot();
    private:
    Cpu _cpu;
    MemoryManagementUnit _mmu;
    std::vector<char>* _bios;
    std::vector<char>* _cartridge;
    std::vector<char>* _loadExecutableBinary(const char* filename);
};
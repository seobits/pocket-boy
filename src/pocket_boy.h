#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "cpu.h"
#include "memory.h"

class PocketBoy {
    public:
        PocketBoy();
    private:
    CPU* _cpu;
    Memory* _memory;
    std::vector<char>* _bios;
    std::vector<char>* _cartridge;
    std::vector<char>* _loadExecutableBinary(const char* filename);
};
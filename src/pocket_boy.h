#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "cpu.h"

class PocketBoy {
    public:
        PocketBoy();
    private:
    CPU* _cpu;
    std::vector<char>* _bios;
    std::vector<char>* _cartridge;
    std::vector<char>* _loadRomData(const char* filename);
};
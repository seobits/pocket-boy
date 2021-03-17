#include "pocket_boy.h"

PocketBoy::PocketBoy(){
    this->_bios = this->_loadExecutableBinary("rom/bios.gb");
}

void PocketBoy::Boot(){
    uint8_t opcode = this->_mmu.fetchOpcode(this->_cpu.registers.PC);
    this->_cpu.Execute(opcode);
}

std::vector<char>* PocketBoy::_loadExecutableBinary(const char* filename) {
    std::basic_ifstream<char> input(filename, std::ios::in | std::ios::binary);
    std::vector<char>* data;
    if(input){
        std::cout << "Loaded file " << filename << std::endl;
        std::istreambuf_iterator<char> streamIterator(input);
        std::istreambuf_iterator<char> eos;
        data = new std::vector<char>(streamIterator, eos);
    }else{
        std::cout << "file not found" << std::endl;
    }
    return data;
}
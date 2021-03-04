#include "pocket_boy.h"

PocketBoy::PocketBoy(){
    this->_cpu = new CPU();
    this->_bios = this->_loadRomData("rom/bios.gb");
}

std::vector<char>* PocketBoy::_loadRomData(const char* filename) {
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
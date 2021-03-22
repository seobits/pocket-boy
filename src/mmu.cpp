#include "mmu.h"

uint8_t* MemoryManagementUnit::readFromMemory(const uint16_t& address){
    uint8_t* memoryAllocAddress = ((uint8_t*)&this->_memory) + address;
    return memoryAllocAddress;
}

void MemoryManagementUnit::writeToMemory(const uint16_t& address, uint8_t data){
    uint8_t* memoryAllocAddress = ((uint8_t*)&this->_memory) + address;
    *memoryAllocAddress = data;
}
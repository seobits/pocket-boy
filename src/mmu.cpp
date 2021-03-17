#include "mmu.h"

uint8_t MemoryManagementUnit::fetchOpcode(const Register& pcRegister){
    uint8_t& memoryAllocAddress = (uint8_t&)this->_memory;
    return memoryAllocAddress + pcRegister.value;
}
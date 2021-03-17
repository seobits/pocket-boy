#include "cpu.h"

Cpu::Cpu(){
    std::cout << "Creating new CPU instance" << std::endl;
}

void Cpu::Execute(const uint8_t& opcode){
    const Instruction* executableInstruction = &this->_instructionSet.list[opcode];
    if(executableInstruction->function != NULL){
        std::cout << "Executing instruction -> " << executableInstruction->mnemonic;
    }else{
        std::cout << "Unable to execute instruction with opcode -> " << opcode;
    }
}
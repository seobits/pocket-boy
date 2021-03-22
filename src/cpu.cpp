#include "cpu.h"
#include "mmu.h"

Cpu::Cpu(){
    std::cout << "Creating new CPU instance" << std::endl;
}

void Cpu::Execute(MemoryManagementUnit& mmu){
    uint8_t* instructionAddress = mmu.readFromMemory(this->registers.PC.value);
    const uint8_t opcode = *instructionAddress;
    const Instruction& executableInstruction = this->_instructionSet.list[opcode];
    if(executableInstruction.function != NULL){
        std::cout << "Executing instruction: " << executableInstruction.mnemonic << std::endl;
        executableInstruction.function(mmu, instructionAddress, executableInstruction, this->registers);
        this->registers.PC += executableInstruction.length;
        this->_cycleCounter += executableInstruction.cycles;
        
    }else{
        std::cout << "Unable to execute instruction with opcode -> " << opcode << std::endl;
    }
}
#pragma once
#include <iostream>
#include "registers.h"
#include "mmu.h"

struct Instruction {
    const char* mnemonic;
    const int opcode;
    const uint8_t length;
    const uint8_t cycles;
    void (*function)(MemoryManagementUnit& mmu, uint8_t* instructionAddress, const Instruction& instruction, CpuRegisters& registers);
};

struct InstructionSet {
    public:
        const Instruction list[0xFF] = {
            "NOP", 0x00, 1, 4, &InstructionSet::_0x00_NOP,
            "LD BC, d16", 0x01, 3, 12, &InstructionSet::_0x01_LD_BC_D16,
            "LD (BC),A", 0x02, 1, 8, &InstructionSet::_0x02_LD_BC_A,
            "INC BC", 0x03, 1, 8, &InstructionSet::_0x03_INC_BC,
            "INC B", 0x04, 1, 4, &InstructionSet::_0x04_INC_B,
        };
    
    private:
        static inline void _0x00_NOP(MemoryManagementUnit& mmu, uint8_t* instructionAddress, const Instruction& instruction, CpuRegisters& registers){}
        static inline void _0x01_LD_BC_D16(MemoryManagementUnit& mmu, uint8_t* instructionAddress, const Instruction& instruction, CpuRegisters& registers){
            uint16_t* dataAddress = (uint16_t*)(instructionAddress + 1);
            registers.BC = *dataAddress;
        }
        static inline void _0x02_LD_BC_A(MemoryManagementUnit& mmu, uint8_t* instructionAddress, const Instruction& instruction, CpuRegisters& registers){
            mmu.writeToMemory(registers.BC.value, registers.AF.high);
        }
        static inline void _0x03_INC_BC(MemoryManagementUnit& mmu, uint8_t* instructionAddress, const Instruction& instruction, CpuRegisters& registers){
            registers.BC += 1;
        }
        static inline void _0x04_INC_B(MemoryManagementUnit& mmu, uint8_t* instructionAddress, const Instruction& instruction, CpuRegisters& registers){
            if((registers.BC.high & 0xF) == 0xF){
                registers.AF.high |= 0b0010;
            }

            registers.BC.high++;

            if(registers.BC.high == 0){
                registers.AF.high |= 0b1000;
            }

            registers.AF.high &= 0b1011;
        }
};
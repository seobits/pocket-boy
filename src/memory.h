#pragma once
#include <iostream>

enum EnumMemoryOffset {
    ROM_0 = 0x0,
    ROM_SW = 0x4000,
    VRAM = 0x8000,
    RAM_SW = 0xA000,
    RAM_INTERNAL_1 = 0xC000,
    RAM_ECHO = 0xE000,
    SPRITE_ATTRIB = 0xFE00,
    EMPTY_USABLE_IO_1 = 0xFEA0,
    IO_PORTS = 0xFF00,
    EMPTY_USABLE_IO_2 = 0xFF4C,
    RAM_INTERNAL_2 = 0xFF80,
    INTERRUPT_ENABLE = 0xFFFF
};

struct Memory {
    uint8_t rom_0[ROM_SW - ROM_0];
    uint8_t rom_sw[VRAM - ROM_SW];
    uint8_t vram[RAM_SW - VRAM];
    uint8_t ram_sw[RAM_INTERNAL_1 - RAM_SW];
    uint8_t ram_internal_1[RAM_ECHO - RAM_INTERNAL_1];
    uint8_t ram_echo[SPRITE_ATTRIB - RAM_ECHO];
    uint8_t sprite_atrib[EMPTY_USABLE_IO_1 - SPRITE_ATTRIB];
    uint8_t empty_usable_io_1[IO_PORTS - EMPTY_USABLE_IO_1];
    uint8_t io_ports[EMPTY_USABLE_IO_2 - IO_PORTS];
    uint8_t empty_usable_io_2[RAM_INTERNAL_2 - EMPTY_USABLE_IO_2];
    uint8_t ram_internal_2[INTERRUPT_ENABLE - RAM_INTERNAL_2];
};
#pragma once
#include <iostream>
struct Register{
    union {
        uint16_t value;
        struct{
            uint8_t low: 8;
            uint8_t high: 8;
        };
    };
};
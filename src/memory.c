#include "memory.h"

#ifndef CUSTOM_MEMORY

uint8_t memory[MEM_SIZE];

size_t memSize()
{
    return MEM_SIZE;
}

int memGet(uint32_t loc, uint8_t *val)
{
    if (loc >= MEM_SIZE)
        return -1;

    *val = memory[loc];
    return 0;
}

int memSet(uint32_t loc, uint8_t val)
{
    if (loc >= MEM_SIZE)
        return -1;

    memory[loc] = val;
    return 0;
}

#endif
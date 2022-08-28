#include "inst.h"
#include "memory.h"

#ifndef CUSTOM_MEMORY
#ifdef MEM_SIZE

uint8_t memory[MEM_SIZE];

size_t memSize()
{
    return MEM_SIZE;
}

Error memGet(uint32_t loc, uint8_t *val)
{
    if (loc >= MEM_SIZE)
        return MemoryOutOfRange;

    *val = memory[loc];
    return Ok;
}

Error memSet(uint32_t loc, uint8_t val)
{
    if (loc >= MEM_SIZE)
        return MemoryOutOfRange;

    memory[loc] = val;
    return Ok;
}

#endif
#endif

int instWrite(MemoryIntf *memIntf, uint32_t loc, Inst inst, uint8_t arg1, uint8_t arg2, uint8_t arg3)
{
    if (memIntf->set(loc++, inst) ||
        memIntf->set(loc++, arg1) ||
        memIntf->set(loc++, arg2) ||
        memIntf->set(loc++, arg3))
        return -1;

    return 0;
}

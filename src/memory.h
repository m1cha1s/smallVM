#ifndef simplevm_memory_h
#define simplevm_memory_h

#include "common.h"
#include "inst.h"

typedef struct _MemoryIntf
{
    size_t (*size)();
    Error (*get)(uint32_t loc, uint8_t *val);
    Error (*set)(uint32_t loc, uint8_t val);
} MemoryIntf;

#ifndef CUSTOM_MEMORY
size_t memSize();
Error memGet(uint32_t loc, uint8_t *val);
Error memSet(uint32_t loc, uint8_t val);
#endif

int instWrite(MemoryIntf *, uint32_t, Inst, uint8_t, uint8_t, uint8_t);

#endif
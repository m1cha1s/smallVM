#ifndef simplevm_memory_h
#define simplevm_memory_h

#include "common.h"

typedef struct _MemoryIntf
{
    size_t (*size)();
    int (*get)(uint32_t, uint8_t *);
    int (*set)(uint32_t, uint8_t);
} MemoryIntf;

#ifndef CUSTOM_MEMORY

size_t memSize();
int memGet(uint32_t loc, uint8_t *val);
int memSet(uint32_t loc, uint8_t val);

#endif

#endif
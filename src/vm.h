#ifndef smallvm_vm_h
#define smallvm_vm_h

#include "common.h"
#include "memory.h"

typedef struct _VM
{
    uint8_t A;
    uint32_t PC;
    uint8_t SP;

    // The memory interface
    MemoryIntf memIntf;
} VM;

int loadProg(VM *, uint8_t *, size_t);
void dumpMem(VM *);

#endif
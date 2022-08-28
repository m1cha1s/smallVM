#define MEM_SIZE 12

#include <stdio.h>

#include "common.h"
#include "vm.h"
#include "inst.h"
#include "memory.h"
#include "debug.h"

int main()
{
    MemoryIntf mem = {.size = memSize, .get = memGet, .set = memSet};
    VM vm;

    printf("%d\n", mem.size());

    vmInit(&vm, &mem);

    instWrite(&mem, 0, LDA, 0x00, 0x00, 0x08);
    instWrite(&mem, 4, STA, 0x00, 0x00, 0x09);
    mem.set(8, 0xEA);
    instDump(&mem, 0);
    instDump(&mem, 4);

    vmTick(&vm);
    vmDumpRegs(&vm);

    memDump(&mem);
}
#include <stdio.h>

#include "common.h"
#include "vm.h"
#include "inst.h"
#include "memory.h"
#include "debug.h"

int main()
{
    MemoryIntf mem = {.size = memSize, .get = memGet, .set = memSet};

    mem.set(0, LDA);
    mem.set(1, 0);
    mem.set(2, 0x12);
    mem.set(3, 0xff);

    dumpInst(&mem, 0);
}
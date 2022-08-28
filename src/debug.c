#include <stdio.h>

#include "debug.h"

int dumpInst(MemoryIntf *mem, uint32_t loc)
{
    uint8_t opcode;
    uint8_t arg1;
    uint8_t arg2;
    uint8_t arg3;

    mem->get(loc++, &opcode);
    mem->get(loc++, &arg1);
    mem->get(loc++, &arg2);
    mem->get(loc++, &arg3);

    switch (opcode)
    {
    case NOP:
        printf("NOP\n");
        return 0;
    case LDA:
        printf("LDA 0x%X%X\n", arg2, arg3);
        return 0;
    default:
        printf("Unknown instruction %X %X %X %X!\n", opcode, arg1, arg2, arg3);
        return -1;
    }
}
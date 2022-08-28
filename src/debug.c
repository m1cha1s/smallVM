#include <stdio.h>

#include "debug.h"

static Error memOP(MemoryIntf *mem, const char *name, uint8_t arg2, uint8_t arg3)
{
    uint8_t val;
    uint32_t loc = arg3;
    loc |= ((uint32_t)arg2) << 8;
    mem->get(loc, &val);
    printf("%s $%02X%02X -> %X\n", name, arg2, arg3, val);

    return Ok;
}

Error instDump(MemoryIntf *mem, uint32_t loc)
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
        return memOP(mem, "LDA", arg2, arg3);
    case STA:
        return memOP(mem, "STA", arg2, arg3);
    default:
        printf("Unknown instruction %X %X %X %X!\n", opcode, arg1, arg2, arg3);
        return UnknownInstruction;
    }
}

void vmDumpRegs(VM *vm)
{
    printf("==== Reg dump ====\n");
    printf(" A:  0x%02X\n", vm->A);
    printf(" PC: 0x%08X\n", vm->PC);
    printf(" SP: 0x%02X\n", vm->SP);
    printf("==================\n");
}

void memDump(MemoryIntf *mem)
{
    printf("==== Mem dump ====\n");

    for (uint32_t i = 0; i < mem->size(); i++)
    {
        uint8_t val;
        mem->get(i, &val);
        printf("0x%08X: 0x%02X\n", i, val);
    }

    printf("==================\n");
}
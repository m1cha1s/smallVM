#include "vm.h"
#include "inst.h"

void vmInit(VM *vm, MemoryIntf *memIntf)
{
    vm->A = 0;
    vm->memIntf = memIntf;
    vm->PC = 0;
    // Put the stack pointer at the top of memory
    vm->SP = memIntf->size() - 1;
}

static Error lda(VM *vm)
{
    uint8_t arg2, arg3;
    // Discard arg1
    vm->PC++;

    Error err = vm->memIntf->get(vm->PC++, &arg2);
    if (err)
        return err;
    err = vm->memIntf->get(vm->PC++, &arg3);
    if (err)
        return err;

    uint8_t val;

    uint32_t loc = ((uint32_t)arg3) | ((uint32_t)arg2) << 8;

    err = vm->memIntf->get(loc, &val);
    if (err)
        return err;

    vm->A = val;

    return Ok;
}

static Error sta(VM *vm)
{
    uint8_t arg2, arg3;
    // Discard arg1
    vm->PC++;

    Error err = vm->memIntf->get(vm->PC++, &arg2);
    if (err)
        return err;
    err = vm->memIntf->get(vm->PC++, &arg3);
    if (err)
        return err;

    uint32_t loc = ((uint32_t)arg3) | ((uint32_t)arg2) << 8;

    err = vm->memIntf->set(loc, vm->A);
    if (err)
        return err;

    return Ok;
}

Error vmTick(VM *vm)
{
    uint8_t opcode;

    // FIXME: This is a bad way of doing it.
    Error err = vm->memIntf->get(vm->PC++, &opcode);
    if (err)
        return err;

    switch (opcode)
    {
    case NOP:
        return Ok;
    case LDA:
        return lda(vm);
    case STA:
        return sta(vm);

    default:
        return UnknownInstruction;
    }
}
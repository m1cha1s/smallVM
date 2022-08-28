#ifndef simplevm_debug_h
#define simplevm_debug_h

#include "common.h"
#include "inst.h"
#include "memory.h"
#include "vm.h"

Error instDump(MemoryIntf *, uint32_t);
void vmDumpRegs(VM *);
void memDump(MemoryIntf *);

#endif
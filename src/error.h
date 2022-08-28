#ifndef simplevm_error_h
#define simelevm_error_h

typedef enum _Error
{
    Ok,
    MemoryOutOfRange,
    UnknownInstruction,
} Error;

#endif
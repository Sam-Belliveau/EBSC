#include "include/MMU.h"

void MemoryManagementUnit::pushByte(const BYTE data)
{ mem.getByte(MEMORY_SIZE-(++sp)) = data; }

BYTE MemoryManagementUnit::popByte()
{ return mem.getByte(MEMORY_SIZE-(sp--)); }

void MemoryManagementUnit::pushWord(const WORD data)
{ mem.getWord(MEMORY_SIZE-(++sp)) = data; }

WORD MemoryManagementUnit::popWord()
{ return mem.getWord(MEMORY_SIZE-(sp--)); }

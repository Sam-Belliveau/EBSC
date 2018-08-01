#ifndef MEMORYMANAGEMENTUNIT_H
#define MEMORYMANAGEMENTUNIT_H

/*** Definitions ***/
#include "InstructionSet.h"
#include "DataLayout.h"
#include "TypeNames.h"
#include "BitSet.h"

#define MEMORY_SIZE 0x8000
#define REGISTER_SIZE 0x100

// Theres a reason for this to be a class I swear
class MemoryManagementUnit
{
public: // Methods
  void pushByte(const BYTE data);
  BYTE popByte();

  void pushWord(const WORD data);
  WORD popWord();

public: // Variables
  BitSet flags;

  DataLayout<REGISTER_SIZE> reg;

  // Memory and Stack Pointer
  WORD mp = 0, sp = 0;
  DataLayout<MEMORY_SIZE> mem;
};

#endif

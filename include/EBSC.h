#ifndef EBSC8
#define EBSC8

/*** Extentions ***/
#include "Console.h"

/*** Definitions ***/
#include "TypeNames.h"
#include "InstructionSet.h"

/*** Managers ***/
#include "MemoryManagementUnit.h"
#include "ProgramManagementUnit.h"

#define TRUE 0x01
#define FALSE 0x00

/*** CPU ***/
class EBSC
{
public: // Methods
  void startProgram()
  {
    MMU.flags.setBit(0, true);
    while(MMU.flags.getBit(0))
    { runNextOPCODE(); }
    return;
  }

  void runNextOPCODE();

public: // Variables
  // Managers
  MemoryManagementUnit MMU;
  ProgramManagementUnit PMU;

  // Extentions
  Console terminal;
};

#endif

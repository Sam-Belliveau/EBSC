#ifndef PROGRAMMANAGMENTUNIT_H
#define PROGRAMMANAGMENTUNIT_H

/*** Libraries ***/
#include <vector>

/*** Definitions ***/
#include "InstructionSet.h"
#include "TypeNames.h"

class ProgramManagementUnit
{
public: // Methods
  void addByte(const BYTE input);
  void loadProgram(const std::vector<BYTE> input_program);

  BYTE getByte();
  WORD getWord();

public: // Variables
  WORD program_counter = 0;

private: // Variables
  BYTE program[0x10000];
  WORD program_size = 0;
};

#endif

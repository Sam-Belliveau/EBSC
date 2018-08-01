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
  void addByte(const BYTE input)
  {
    program[program_size] = input;
    program_size++;
  }

  void loadProgram(const std::vector<BYTE> input_program)
  {
    program_size = 0;
    program_counter = 0;
    for(BYTE i : input_program)
    { addByte(i); }
  }

  BYTE getByte()
  {
    if(program_size > program_counter)
    { return program[program_counter++]; }
    else { return OP_STOP; }
  }

  WORD getWord()
  {
    return (static_cast<WORD>(getByte()) << 8) +
            static_cast<WORD>(getByte());
  }

public: // Variables
  WORD program_counter = 0;

private: // Variables
  BYTE program[0x10000];
  WORD program_size = 0;
};

#endif

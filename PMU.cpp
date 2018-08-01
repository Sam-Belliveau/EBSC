#include "include/PMU.h"

void ProgramManagementUnit::addByte(const BYTE input)
{
  program[program_size] = input;
  program_size++;
}

void ProgramManagementUnit::loadProgram(const std::vector<BYTE> input_program)
{
  program_size = 0;
  program_counter = 0;
  for(BYTE i : input_program)
  { addByte(i); }
}

BYTE ProgramManagementUnit::getByte()
{
  if(program_size > program_counter)
  { return program[program_counter++]; }
  else { return OP_STOP; }
}

WORD ProgramManagementUnit::getWord()
{
  return (static_cast<WORD>(getByte()) << 8) +
          static_cast<WORD>(getByte());
}

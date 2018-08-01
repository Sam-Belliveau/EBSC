#ifndef DATALAYOUT_H
#define DATALAYOUT_H

#include "TypeNames.h"


template<std::size_t size>
class DataLayout
{
public: // Methods
  DataLayout()
  {
    for(BYTE i : data)
    { i = 0; }
  }

  BYTE& getByte(const std::size_t index)
  { return data[index]; }

  WORD& getWord(const std::size_t index)
  { return *reinterpret_cast<WORD*>(&data[index]); }

  DWORD& getDWord(const std::size_t index)
  { return *reinterpret_cast<DWORD*>(&data[index]); }

  QWORD& getQWord(const std::size_t index)
  { return *reinterpret_cast<QWORD*>(&data[index]); }

private: // Variables
  BYTE data[size];
};

#endif

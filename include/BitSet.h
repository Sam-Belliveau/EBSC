#ifndef BITSET_H
#define BITSET_H

#include "TypeNames.h"

#define GETMASK(x) (0x01 << x)

class BitSet
{
public: // Methods
  bool getBit(const std::size_t bit)
  { return ((data & (0x01 << bit)) != 0); }

  void setBit(const std::size_t bit, const bool val)
  {
    if(val)
    { data |= (0x01 << bit); }
    else
    {
      if(getBit(bit))
      { data ^= (0x01 << bit); }
    }
  }

public: // Variables
  QWORD data = 0; // This is where the bits are stored
};

#endif

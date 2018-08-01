#ifndef CONSOLE_H
#define CONSOLE_H

/*** Libraries ***/
#include <iostream>

/*** Definitions ***/
#include "TypeNames.h"

// The reason the console is an object is because
// The Classes EBSC8 Contains Are Like Devices
class Console
{
public: // Methods
  void printWord(const WORD i);
  void printByte(const BYTE i);
  void printChar(const BYTE i);

  WORD getWord();
  BYTE getByte();
  BYTE getChar();
};

#endif

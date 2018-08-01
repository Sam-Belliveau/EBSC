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
  void printWord(const WORD i)
  { std::cout << static_cast<unsigned>(i); }

  void printByte(const BYTE i)
  { std::cout << static_cast<unsigned>(i); }

  void printChar(const BYTE i)
  { std::cout << static_cast<char>(i); }

  BYTE getNum()
  {
    BYTE out; std::cin >> out;
    std::cin.clear();
    std::cin.ignore(0xffff, '\n');
    return out;
  }

  BYTE getChar()
  {
    char out; std::cin >> out;
    std::cin.clear();
    std::cin.ignore(0xffff, '\n');
    return static_cast<BYTE>(out);
  }
};

#endif

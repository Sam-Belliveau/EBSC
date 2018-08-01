#include "include/Console.h"

void Console::printWord(const WORD i)
{ std::cout << static_cast<unsigned>(i); }

void Console::printByte(const BYTE i)
{ std::cout << static_cast<unsigned>(i); }

void Console::printChar(const BYTE i)
{ std::cout << static_cast<char>(i); }

WORD Console::getWord()
{
  WORD out; std::cin >> out;
  std::cin.clear();
  std::cin.ignore(0xffff, '\n');
  return out;
}

BYTE Console::getByte()
{
  BYTE out; std::cin >> out;
  std::cin.clear();
  std::cin.ignore(0xffff, '\n');
  return out;
}

BYTE Console::getChar()
{
  char out; std::cin >> out;
  std::cin.clear();
  std::cin.ignore(0xffff, '\n');
  return static_cast<BYTE>(out);
}

#include <iostream>
#include <vector>
#include "include/EBSC.h"

int main()
{
  const std::vector<BYTE> fib =
  {
    GP_RGMP, OP_STWP, 0x00, 0x00, 0x01, // First Var
    GP_RGMP, OP_STWP, 0x02, 0x00, 0x01, // Secound Var
    GP_RGMP, OP_STWP, 0x04, 0x3f, 0xff, // Max Value

    GP_PRGM, OP_SRPC, 0x06,

    GP_PRNT, OP_PTWR, 0x00,
    GP_PRNT, OP_PTCP, '\n',
    GP_PRNT, OP_PTWR, 0x02,
    GP_PRNT, OP_PTCP, '\n',

    GP_RGMP, OP_ADDW, 0x00, 0x02,
    GP_RGMP, OP_ADDW, 0x02, 0x00,

    GP_RGMP, OP_ILTW, 0x08, 0x00, 0x04,
    GP_RGMP, OP_ILTW, 0x09, 0x02, 0x04,
    GP_RGMP, OP_IORB, 0x08, 0x09,

    GP_PRGM, OP_ISPR, 0x08, 0x06
  };

  EBSC computer;
  computer.PMU.loadProgram(fib);
  computer.startProgram();

  std::cout << "\n\n";
}

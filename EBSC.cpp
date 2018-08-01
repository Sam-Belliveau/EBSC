#include "include/EBSC.h"

void EBSC::runNextOPCODE()
{
  const BYTE GROUP = PMU.getByte();
  const BYTE OPCODE = PMU.getByte();
  BYTE b1, b2, b3, b4; // Byte Input Buffer
  WORD w1, w2, w3, w4; // Word Input Buffer


  switch (GROUP)
  {

  /*** GROUP: Program Management ***/
  case GP_PRGM:
    switch (OPCODE)
    {
    case OP_STOP:
      MMU.flags.setBit(0, false);
      break;

    case OP_SRPC:
      b1 = PMU.getByte();
      MMU.reg.getWord(b1) = PMU.program_counter;
      break;

    case OP_SPCR:
      b1 = PMU.getByte();
      PMU.program_counter = MMU.reg.getWord(b1);
      break;

    case OP_ISPR:
      b1 = PMU.getByte();
      b2 = PMU.getByte();

      if(MMU.reg.getByte(b1) != FALSE)
      { PMU.program_counter = MMU.reg.getWord(b2); }
      break;

    case OP_PUPS:
      MMU.pushWord(PMU.program_counter);
      break;

    case OP_POPS:
     PMU.program_counter = MMU.popWord();
     break;

    case OP_IPPS:
      b1 = PMU.getByte();
      if(MMU.reg.getByte(b1) != 0)
      { PMU.program_counter = MMU.popWord(); }
      break;

    default:
      MMU.flags.setBit(1, true);
      break;
    } break;


  /*** GROUP: Stack ***/
  case GP_STACK:
    switch(OPCODE)
    {
    case OP_POPB:
      b1 = PMU.getByte();
      MMU.reg.getByte(b1) = MMU.popByte();
      break;

    case OP_PUSB:
      b1 = PMU.getByte();
      MMU.pushByte(MMU.reg.getByte(b1));
      break;

    case OP_POPW:
      b1 = PMU.getByte();
      MMU.reg.getWord(b1) = MMU.popWord();
      break;

    case OP_PUSW:
      b1 = PMU.getByte();
      MMU.pushWord(MMU.reg.getWord(b1));
      break;
    } break;

  /*** GROUP: Register Manipulation ***/
  case GP_RGMP:
    switch (OPCODE)
    {
    case OP_STBP:
      b1 = PMU.getByte();
      b2 = PMU.getByte();

      MMU.reg.getByte(b1) = b2;
      break;

    case OP_STWP:
      b1 = PMU.getByte();
      w1 = PMU.getWord();

      MMU.reg.getWord(b1) = w1;
      break;

    case OP_STBM:
      b1 = PMU.getByte();
      w1 = PMU.getWord();

      MMU.reg.getByte(b1) = MMU.mem.getByte(w1);
      break;

    case OP_STWM:
      b1 = PMU.getByte();
      w1 = PMU.getWord();

      MMU.reg.getByte(b1) = MMU.mem.getWord(w1);
      break;

    case OP_STBI:
      b1 = PMU.getByte();

      MMU.reg.getByte(b1) = MMU.mem.getByte(MMU.mp);
      break;

    case OP_STWI:
      b1 = PMU.getByte();

      MMU.reg.getWord(b1) = MMU.mem.getWord(MMU.mp);
      break;

    case OP_STBB:
      b1 = PMU.getByte();
      b2 = PMU.getByte();

      MMU.reg.getByte(b1) = MMU.reg.getByte(b2);
      break;

    case OP_STWW:
      b1 = PMU.getByte();
      b2 = PMU.getByte();

      MMU.reg.getWord(b1) = MMU.reg.getWord(b2);
      break;

    /*** 8-BIT MATH ***/
    case OP_ILTB:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      b3 = PMU.getByte();

      MMU.reg.getByte(b1) =
        (MMU.reg.getByte(b2) <
        MMU.reg.getByte(b3)) ? TRUE : FALSE;
      break;

    case OP_IGTB:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      b3 = PMU.getByte();

      MMU.reg.getByte(b1) =
        (MMU.reg.getByte(b2) >
        MMU.reg.getByte(b3)) ? TRUE : FALSE;
      break;

    case OP_ILEB:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      b3 = PMU.getByte();

      MMU.reg.getByte(b1) =
        (MMU.reg.getByte(b2) <=
        MMU.reg.getByte(b3)) ? TRUE : FALSE;
      break;

    case OP_IGEB:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      b3 = PMU.getByte();

      MMU.reg.getByte(b1) =
        (MMU.reg.getByte(b2) >=
        MMU.reg.getByte(b3)) ? TRUE : FALSE;
      break;

    case OP_IETB:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      b3 = PMU.getByte();

      MMU.reg.getByte(b1) =
        (MMU.reg.getByte(b2) ==
        MMU.reg.getByte(b3)) ? TRUE : FALSE;
      break;

    case OP_INEB:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      b3 = PMU.getByte();

      MMU.reg.getByte(b1) =
        (MMU.reg.getByte(b2) !=
        MMU.reg.getByte(b3)) ? TRUE : FALSE;
      break;

    case OP_INCB:
      b1 = PMU.getByte();
      MMU.reg.getByte(b1)++;
      break;

    case OP_DECB:
      b1 = PMU.getByte();
      MMU.reg.getByte(b1)--;
      break;

    case OP_ADDB:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      MMU.reg.getByte(b1) += MMU.reg.getByte(b2);
      break;

    case OP_SUBB:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      MMU.reg.getByte(b1) -= MMU.reg.getByte(b2);
      break;

    case OP_MULB:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      MMU.reg.getByte(b1) *= MMU.reg.getByte(b2);
      break;

    case OP_DIVB:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      MMU.reg.getByte(b1) /= MMU.reg.getByte(b2);
      break;

    case OP_MODB:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      MMU.reg.getByte(b1) %= MMU.reg.getByte(b2);
      break;

    case OP_ANDB:
      b1 = PMU.getByte();
      b2 = PMU.getByte();

      MMU.reg.getByte(b1) &= MMU.reg.getByte(b2);
      break;

    case OP_IORB:
      b1 = PMU.getByte();
      b2 = PMU.getByte();

      MMU.reg.getByte(b1) |= MMU.reg.getByte(b2);
      break;

    case OP_XORB:
      b1 = PMU.getByte();
      b2 = PMU.getByte();

      MMU.reg.getByte(b1) ^= MMU.reg.getByte(b2);
      break;

    case OP_LSHB:
      b1 = PMU.getByte();
      b2 = PMU.getByte();

      MMU.reg.getByte(b1) <<= MMU.reg.getByte(b2);
      break;

    case OP_RSHB:
      b1 = PMU.getByte();
      b2 = PMU.getByte();

      MMU.reg.getByte(b1) >>= MMU.reg.getByte(b2);
      break;

    /*** 16-BIT MATH ***/
    case OP_ILTW:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      b3 = PMU.getByte();

      MMU.reg.getByte(b1) =
        (MMU.reg.getWord(b2) <
        MMU.reg.getWord(b3)) ? TRUE : FALSE;
      break;

    case OP_IGTW:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      b3 = PMU.getByte();

      MMU.reg.getByte(b1) =
        (MMU.reg.getWord(b2) >
        MMU.reg.getWord(b3)) ? TRUE : FALSE;
      break;

    case OP_ILEW:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      b3 = PMU.getByte();

      MMU.reg.getByte(b1) =
        (MMU.reg.getWord(b2) <=
        MMU.reg.getWord(b3)) ? TRUE : FALSE;
      break;

    case OP_IGEW:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      b3 = PMU.getByte();

      MMU.reg.getByte(b1) =
        (MMU.reg.getWord(b2) >=
        MMU.reg.getWord(b3)) ? TRUE : FALSE;
      break;

    case OP_IETW:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      b3 = PMU.getByte();

      MMU.reg.getByte(b1) =
        (MMU.reg.getWord(b2) ==
        MMU.reg.getWord(b3)) ? TRUE : FALSE;
      break;

    case OP_INEW:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      b3 = PMU.getByte();

      MMU.reg.getByte(b1) =
        (MMU.reg.getWord(b2) !=
        MMU.reg.getWord(b3)) ? TRUE : FALSE;
      break;

    case OP_INCW:
      b1 = PMU.getByte();
      MMU.reg.getWord(b1)++;
      break;

    case OP_DECW:
      b1 = PMU.getByte();
      MMU.reg.getWord(b1)--;
      break;

    case OP_ADDW:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      MMU.reg.getWord(b1) += MMU.reg.getWord(b2);
      break;

    case OP_SUBW:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      MMU.reg.getWord(b1) -= MMU.reg.getWord(b2);
      break;

    case OP_MULW:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      MMU.reg.getWord(b1) *= MMU.reg.getWord(b2);
      break;

    case OP_DIVW:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      MMU.reg.getWord(b1) /= MMU.reg.getWord(b2);
      break;

    case OP_MODW:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      MMU.reg.getWord(b1) %= MMU.reg.getWord(b2);
      break;

    case OP_ANDW:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      MMU.reg.getWord(b1) &= MMU.reg.getWord(b2);
      break;

    case OP_IORW:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      MMU.reg.getWord(b1) |= MMU.reg.getWord(b2);
      break;

    case OP_XORW:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      MMU.reg.getWord(b1) ^= MMU.reg.getWord(b2);
      break;

    case OP_LSHW:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      MMU.reg.getWord(b1) <<= MMU.reg.getWord(b2);
      break;

    case OP_RSHW:
      b1 = PMU.getByte();
      b2 = PMU.getByte();
      MMU.reg.getWord(b1) >>= MMU.reg.getWord(b2);
      break;

    default:
      MMU.flags.setBit(2, true);
      break;
    } break;

  /*** GROUP: Print ***/
  case GP_PRNT:
    switch(OPCODE)
    {
    case OP_PTWP:
      w1 = PMU.getWord();
      terminal.printWord(w1);
      break;

    case OP_PTBP:
      b1 = PMU.getByte();
      terminal.printByte(b1);
      break;

    case OP_PTCP:
      b1 = PMU.getByte();
      terminal.printChar(b1);
      break;

    case OP_PTWM:
      w1 = PMU.getWord();
      terminal.printWord(MMU.mem.getWord(w1));
      break;

    case OP_PTBM:
      w1 = PMU.getWord();
      terminal.printByte(MMU.mem.getByte(w1));
      break;

    case OP_PTCM:
      w1 = PMU.getWord();
      terminal.printChar(MMU.mem.getByte(w1));
      break;

    case OP_PTWI:
      terminal.printWord(MMU.mem.getWord(MMU.mp));
      break;

    case OP_PTBI:
      terminal.printByte(MMU.mem.getByte(MMU.mp));
      break;

    case OP_PTCI:
      terminal.printChar(MMU.mem.getByte(MMU.mp));
      break;

    case OP_PTWR:
      b1 = PMU.getByte();
      terminal.printWord(MMU.reg.getWord(b1));
      break;

    case OP_PTBR:
      b1 = PMU.getByte();
      terminal.printByte(MMU.reg.getByte(b1));
      break;

    case OP_PTCR:
      b1 = PMU.getByte();
      terminal.printChar(MMU.reg.getByte(b1));
      break;

    default:
      MMU.flags.setBit(2, true);
      break;
    } break;

  default:
    MMU.flags.setBit(1, true);
    break;
  }
}

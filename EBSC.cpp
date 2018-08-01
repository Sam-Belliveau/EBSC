#include "include/EBSC.h"

void EBSC::runNextOPCODE()
{
  const BYTE GROUP = PMU.getByte();
  const BYTE OPCODE = PMU.getByte();

  if(GROUP == GP_PRGM)
  {
    if(OPCODE == OP_STOP)
    { MMU.flags.setBit(0, false); }

    else if(OPCODE == OP_SRPC)
    {
      BYTE p1 = PMU.getByte();
      MMU.reg.getWord(p1) = PMU.program_counter;
    }

    else if(OPCODE == OP_SPCR)
    {
      BYTE p1 = PMU.getByte();
      PMU.program_counter = MMU.reg.getWord(p1);
    }

    else if(OPCODE == OP_ISPR)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      if(MMU.reg.getByte(p1) != FALSE)
      { PMU.program_counter = MMU.reg.getWord(p2); }
    }

    else if(OPCODE == OP_PUPS)
    { MMU.pushWord(PMU.program_counter); }
    else if(OPCODE == OP_PUPS)
    { PMU.program_counter = MMU.popWord(); }

    else if(OPCODE == OP_IPPS)
    {
      BYTE p1 = PMU.getByte();
      if(MMU.reg.getByte(p1) != 0)
      { PMU.program_counter = MMU.popWord(); }
    }


    /*** Unknown OPCODE ***/
    else{ MMU.flags.setBit(2, true); }
  }

  else if(GROUP == GP_STACK)
  {
    if(OPCODE == OP_STOP)
    { MMU.flags.setBit(0, false); }

    else if(OPCODE == OP_POPB)
    {
      BYTE p1 = PMU.getByte();
      MMU.reg.getByte(p1) = MMU.popByte();
    }

    else if(OPCODE == OP_PUSB)
    {
      BYTE p1 = PMU.getByte();
      MMU.pushByte(MMU.reg.getByte(p1));
    }

    else if(OPCODE == OP_POPW)
    {
      BYTE p1 = PMU.getByte();
      MMU.reg.getWord(p1) = MMU.popWord();
    }

    else if(OPCODE == OP_PUSW)
    {
      BYTE p1 = PMU.getByte();
      MMU.pushWord(MMU.reg.getWord(p1));
    }

    /*** Unknown OPCODE ***/
    else{ MMU.flags.setBit(2, true); }
  }

  else if(GROUP == GP_RGMP)
  {
    if(OPCODE == OP_STBP)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getByte(p1) = p2;
    }
    else if(OPCODE == OP_STWP)
    {
      BYTE p1 = PMU.getByte();
      WORD p2 = PMU.getWord();

      MMU.reg.getWord(p1) = p2;
    }
    else if(OPCODE == OP_STBM)
    {
      BYTE p1 = PMU.getByte();
      WORD p2 = PMU.getWord();

      MMU.reg.getByte(p1) = MMU.mem.getByte(p2);
    }
    else if(OPCODE == OP_STWM)
    {
      BYTE p1 = PMU.getByte();
      WORD p2 = PMU.getWord();

      MMU.reg.getByte(p1) = MMU.mem.getWord(p2);
    }
    else if(OPCODE == OP_STBI)
    {
      BYTE p1 = PMU.getByte();

      MMU.reg.getByte(p1) = MMU.mem.getByte(MMU.mp);
    }
    else if(OPCODE == OP_STWI)
    {
      BYTE p1 = PMU.getByte();

      MMU.reg.getWord(p1) = MMU.mem.getWord(MMU.mp);
    }
    else if(OPCODE == OP_STBB)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getByte(p1) = MMU.reg.getByte(p2);
    }
    else if(OPCODE == OP_STWW)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getWord(p1) = MMU.reg.getWord(p2);
    }

    /*** 8-BIT MATH ***/
    else if(OPCODE == OP_ILTB)
    {
      BYTE p1 = PMU.getByte(); // Ensure Order Of The Inputs
      BYTE p2 = PMU.getByte();
      BYTE p3 = PMU.getByte();

      MMU.reg.getByte(p1) =
        (MMU.reg.getByte(p2) <
        MMU.reg.getByte(p3)) ? TRUE : FALSE;
    }
    else if(OPCODE == OP_IGTB)
    {
      BYTE p1 = PMU.getByte(); // Ensure Order Of The Inputs
      BYTE p2 = PMU.getByte();
      BYTE p3 = PMU.getByte();

      MMU.reg.getByte(p1) =
        (MMU.reg.getByte(p2) >
        MMU.reg.getByte(p3)) ? TRUE : FALSE;
    }
    else if(OPCODE == OP_ILEB)
    {
      BYTE p1 = PMU.getByte(); // Ensure Order Of The Inputs
      BYTE p2 = PMU.getByte();
      BYTE p3 = PMU.getByte();

      MMU.reg.getByte(p1) =
        (MMU.reg.getByte(p2) <=
        MMU.reg.getByte(p3)) ? TRUE : FALSE;
    }
    else if(OPCODE == OP_IGEB)
    {
      BYTE p1 = PMU.getByte(); // Ensure Order Of The Inputs
      BYTE p2 = PMU.getByte();
      BYTE p3 = PMU.getByte();

      MMU.reg.getByte(p1) =
        (MMU.reg.getByte(p2) >=
        MMU.reg.getByte(p3)) ? TRUE : FALSE;
    }
    else if(OPCODE == OP_IETB)
    {
      BYTE p1 = PMU.getByte(); // Ensure Order Of The Inputs
      BYTE p2 = PMU.getByte();
      BYTE p3 = PMU.getByte();

      MMU.reg.getByte(p1) =
        (MMU.reg.getByte(p2) ==
        MMU.reg.getByte(p3)) ? TRUE : FALSE;
    }
    else if(OPCODE == OP_INEB)
    {
      BYTE p1 = PMU.getByte(); // Ensure Order Of The Inputs
      BYTE p2 = PMU.getByte();
      BYTE p3 = PMU.getByte();

      MMU.reg.getByte(p1) =
        (MMU.reg.getByte(p2) !=
        MMU.reg.getByte(p3)) ? TRUE : FALSE;
    }

    else if(OPCODE == OP_INCB)
    {
      BYTE p1 = PMU.getByte();
      MMU.reg.getByte(p1)++;
    }
    else if(OPCODE == OP_DECB)
    {
      BYTE p1 = PMU.getByte();
      MMU.reg.getByte(p1)--;
    }
    else if(OPCODE == OP_ADDB)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getByte(p1) += MMU.reg.getByte(p2);
    }
    else if(OPCODE == OP_SUBB)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getByte(p1) -= MMU.reg.getByte(p2);  }
    else if(OPCODE == OP_MULB)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getByte(p1) *= MMU.reg.getByte(p2);
    }
    else if(OPCODE == OP_DIVB)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getByte(p1) /= MMU.reg.getByte(p2);
    }
    else if(OPCODE == OP_MODB)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getByte(p1) %= MMU.reg.getByte(p2);
    }
    else if(OPCODE == OP_ANDB)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getByte(p1) &= MMU.reg.getByte(p2);
    }
    else if(OPCODE == OP_IORB)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getByte(p1) |= MMU.reg.getByte(p2);
    }
    else if(OPCODE == OP_XORB)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getByte(p1) ^= MMU.reg.getByte(p2);
    }
    else if(OPCODE == OP_LSHB)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getByte(p1) <<= MMU.reg.getByte(p2);
    }
    else if(OPCODE == OP_RSHB)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getByte(p1) >>= MMU.reg.getByte(p2);
    }

    /*** 16-BIT MATH ***/
    else if(OPCODE == OP_ILTW)
    {
      BYTE p1 = PMU.getByte(); // Ensure Order Of The Inputs
      BYTE p2 = PMU.getByte();
      BYTE p3 = PMU.getByte();

      MMU.reg.getByte(p1) =
        (MMU.reg.getWord(p2) <
        MMU.reg.getWord(p3)) ? TRUE : FALSE;
    }
    else if(OPCODE == OP_IGTW)
    {
      BYTE p1 = PMU.getByte(); // Ensure Order Of The Inputs
      BYTE p2 = PMU.getByte();
      BYTE p3 = PMU.getByte();

      MMU.reg.getByte(p1) =
        (MMU.reg.getWord(p2) >
        MMU.reg.getWord(p3)) ? TRUE : FALSE;
    }
    else if(OPCODE == OP_ILEW)
    {
      BYTE p1 = PMU.getByte(); // Ensure Order Of The Inputs
      BYTE p2 = PMU.getByte();
      BYTE p3 = PMU.getByte();

      MMU.reg.getByte(p1) =
        (MMU.reg.getWord(p2) <=
        MMU.reg.getWord(p3)) ? TRUE : FALSE;
    }
    else if(OPCODE == OP_IGEW)
    {
      BYTE p1 = PMU.getByte(); // Ensure Order Of The Inputs
      BYTE p2 = PMU.getByte();
      BYTE p3 = PMU.getByte();

      MMU.reg.getByte(p1) =
        (MMU.reg.getWord(p2) >=
        MMU.reg.getWord(p3)) ? TRUE : FALSE;
    }
    else if(OPCODE == OP_IETW)
    {
      BYTE p1 = PMU.getByte(); // Ensure Order Of The Inputs
      BYTE p2 = PMU.getByte();
      BYTE p3 = PMU.getByte();

      MMU.reg.getByte(p1) =
        (MMU.reg.getWord(p2) ==
        MMU.reg.getWord(p3)) ? TRUE : FALSE;
    }
    else if(OPCODE == OP_INEW)
    {
      BYTE p1 = PMU.getByte(); // Ensure Order Of The Inputs
      BYTE p2 = PMU.getByte();
      BYTE p3 = PMU.getByte();

      MMU.reg.getByte(p1) =
        (MMU.reg.getWord(p2) !=
        MMU.reg.getWord(p3)) ? TRUE : FALSE;
    }

    else if(OPCODE == OP_INCW)
    {
      BYTE p1 = PMU.getByte();
      MMU.reg.getWord(p1)++;
    }
    else if(OPCODE == OP_DECW)
    {
      BYTE p1 = PMU.getByte();
      MMU.reg.getWord(p1)--; }
    else if(OPCODE == OP_ADDW)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getWord(p1) += MMU.reg.getWord(p2);
    }
    else if(OPCODE == OP_SUBW)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getWord(p1) -= MMU.reg.getWord(p2);  }
    else if(OPCODE == OP_MULW)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getWord(p1) *= MMU.reg.getWord(p2);
    }
    else if(OPCODE == OP_DIVW)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getWord(p1) /= MMU.reg.getWord(p2);
    }
    else if(OPCODE == OP_MODW)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getWord(p1) %= MMU.reg.getWord(p2);
    }
    else if(OPCODE == OP_ANDW)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getWord(p1) &= MMU.reg.getWord(p2);
    }
    else if(OPCODE == OP_IORW)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getWord(p1) |= MMU.reg.getWord(p2);
    }
    else if(OPCODE == OP_XORW)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getWord(p1) ^= MMU.reg.getWord(p2);
    }
    else if(OPCODE == OP_LSHW)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getWord(p1) <<= MMU.reg.getWord(p2);
    }
    else if(OPCODE == OP_RSHW)
    {
      BYTE p1 = PMU.getByte();
      BYTE p2 = PMU.getByte();

      MMU.reg.getWord(p1) >>= MMU.reg.getWord(p2);
    }

    /*** Unknown OPCODE ***/
    else{ MMU.flags.setBit(2, true); }
  }

  else if(GROUP == GP_PRNT)
  {
    if(OPCODE == OP_PTWP)
    {
      WORD p1 = PMU.getWord();
      terminal.printWord(p1);
    }
    else if(OPCODE == OP_PTBP)
    {
      BYTE p1 = PMU.getByte();
      terminal.printByte(p1);
    }
    else if(OPCODE == OP_PTCP)
    {
      BYTE p1 = PMU.getByte();
      terminal.printChar(p1);
    }

    else if(OPCODE == OP_PTWM)
    {
      WORD p1 = PMU.getWord();
      terminal.printWord(MMU.mem.getWord(p1));
    }
    else if(OPCODE == OP_PTBM)
    {
      WORD p1 = PMU.getWord();
      terminal.printByte(MMU.mem.getByte(p1)); }
    else if(OPCODE == OP_PTCM)
    {
      WORD p1 = PMU.getWord();
      terminal.printChar(MMU.mem.getByte(p1));
    }

    else if(OPCODE == OP_PTWI)
    { terminal.printWord(MMU.mem.getWord(MMU.mp)); }
    else if(OPCODE == OP_PTBI)
    { terminal.printByte(MMU.mem.getByte(MMU.mp)); }
    else if(OPCODE == OP_PTCI)
    { terminal.printChar(MMU.mem.getByte(MMU.mp)); }

    else if(OPCODE == OP_PTWR)
    {
      BYTE p1 = PMU.getByte();
      terminal.printWord(MMU.reg.getWord(p1)); }
    else if(OPCODE == OP_PTBR)
    {
      BYTE p1 = PMU.getByte();
      terminal.printByte(MMU.reg.getByte(p1));
    }
    else if(OPCODE == OP_PTCR)
    {
      BYTE p1 = PMU.getByte();
      terminal.printChar(MMU.reg.getByte(p1));
    }

    /*** Unknown OPCODE ***/
    else{ MMU.flags.setBit(2, true); }
  }

  /*** Unknown GROUP ***/
  else{ MMU.flags.setBit(1, true); }
}

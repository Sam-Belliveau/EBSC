#ifndef INSTRUCTIONSET_H
#define INSTRUCTIONSET_H

/*  FOR REFERENCE
 * 1 Word = 2 Bytes
 * Because The Program Is Split Into Bytes
 * A Word In The Program Is Seperated Into 2 Bytes
 *
 * Takes In Statements Are Saying How Many Parameters
 * Each Function Needs
 *
 * Changing The (f) Register Can And Will Cause Errors
 * The Functionality Is Kept Because This Is Assembly
 */

#define GP_PRGM 0x00 // Program Manager

  #define OP_STOP 0x00 // Stops The Computers

  /* Takes In 1 Byte */
  #define OP_SRPC 0x01 // Sets Regester To Program Counter
  #define OP_SPCR 0x02 // Sets Program Counter to Regester

  /* Takes In 2 Bytes */
  #define OP_ISPR 0x03 // If Register Is Set, Set Program Counter To Register

  /* Takes In Nothing */
  #define OP_PUPS 0x04 // Push Program Counter To Stack
  #define OP_POPS 0x05 // Pop Stack To Program Counter

  /*Takes In 1 Byte */
  #define OP_IPPS 0x06 // If Register Pop Stack To Program Counter


#define GP_STACK 0x01 // Stack

  /* Takes In 1 Byte */
  #define OP_POPB 0x00 // Pop Byte From Stack To Regester
  #define OP_PUSB 0x01 // Push Byte From Register To Stack

  #define OP_POPW 0x02 // Pop Word From Stack To Regester
  #define OP_PUSW 0x03 // Push Word From Register To Stack


#define GP_RGMP 0x02 // Register Manipulation

  /* Takes in 2 Bytes */
  #define OP_STBP 0x00 // Set Register To Byte From Program

  /* Takes in 1 Byte and 1 Word */
  #define OP_STWP 0x01 // Set Register To Word From Program

  /* Takes in 1 Byte and 1 Word */
  #define OP_STBM 0x02 // Set Register To Byte From Memory
  #define OP_STWM 0x03 // Set Register To Word From Memory

  /* Takes in 1 Byte */
  #define OP_STBI 0x04 // Set Register To Byte From Memory Pointer
  #define OP_STWI 0x05 // Set Register To Word From Memory Pointer

  /* Takes in 2 Bytes */
  #define OP_STBB 0x06 // Set Register Byte To Other Register Byte
  #define OP_STWW 0x07 // Set Register Word To Other Register Word

  /*** 8-BIT MATH ***/
  /* Takes 3 Bytes */
  #define OP_ILTB 0x10 // Sets Register to true if the First Register Is Less Than The Secound
  #define OP_IGTB 0x11 // Sets Register to true if the 1st Register Is Greater Than The Secound
  #define OP_ILEB 0x12 // Sets Register to true if the 1st Register Is Less Than Or Equal The Secound
  #define OP_IGEB 0x13 // Sets Register to true if the 1st Register Is Greater Than Or Equal The Secound
  #define OP_IETB 0x14 // Sets Register to true if the 1st Register Is Equal To The Secound
  #define OP_INEB 0x15 // Sets Register to true if the 1st Register Is Not Equal To The Secound

  /* Takes 1 Byte */
  #define OP_INCB 0x16 // Inc Register
  #define OP_DECB 0x17 // Dec Register

  /* Takes 2 Bytes */
  #define OP_ADDB 0x18 // Add 2nd Register to the 1st
  #define OP_SUBB 0x19 // Sub The 1st Regester By The 2nd
  #define OP_MULB 0x1A // Mul The 1st Regester By The 2nd
  #define OP_DIVB 0x1B // Div The 1st Regester By The 2nd
  #define OP_MODB 0x1C // Mod The 1st Regester By The 2nd
  #define OP_ANDB 0x1D // And The 1st Regester By The 2nd
  #define OP_IORB 0x1E // Or The 1st Regester By The 2nd
  #define OP_XORB 0x1F // Xor The 1st Regester By The 2nd
  #define OP_LSHB 0x20 // Left Shift The 1st Register By The 2nd
  #define OP_RSHB 0x21 // Right Shift The 1st Register By The 2nd


  /*** 16-BIT MATH ***/
  /* Takes 3 Bytes */
  #define OP_ILTW 0x30 // Sets Register to true if the First Register Is Less Than The Secound
  #define OP_IGTW 0x31 // Sets Register to true if the 1st Register Is Greater Than The Secound
  #define OP_ILEW 0x32 // Sets Register to true if the 1st Register Is Less Than Or Equal The Secound
  #define OP_IGEW 0x33 // Sets Register to true if the 1st Register Is Greater Than Or Equal The Secound
  #define OP_IETW 0x34 // Sets Register to true if the 1st Register Is Equal To The Secound
  #define OP_INEW 0x35 // Sets Register to true if the 1st Register Is Not Equal To The Secound

  /* Takes 1 Byte */
  #define OP_INCW 0x36 // Inc Register
  #define OP_DECW 0x37 // Dec Register

  /* Takes 2 Bytes */
  #define OP_ADDW 0x38 // Add 2nd Register to the 1st
  #define OP_SUBW 0x39 // Sub The 1st Regester By The 2nd
  #define OP_MULW 0x3A // Mul The 1st Regester By The 2nd
  #define OP_DIVW 0x3B // Div The 1st Regester By The 2nd
  #define OP_MODW 0x3C // Mod The 1st Regester By The 2nd
  #define OP_ANDW 0x3D // And The 1st Regester By The 2nd
  #define OP_IORW 0x3E // Or The 1st Regester By The 2nd
  #define OP_XORW 0x3F // Xor The 1st Regester By The 2nd
  #define OP_LSHW 0x40 // Left Shift The 1st Register By The 2nd
  #define OP_RSHW 0x41 // Right Shift The 1st Register By The 2nd

#define GP_PRNT 0xff // Printing

  /* Takes In 1 Word */
  #define OP_PTWP 0x00 // Print Word From Program

  /* Takes In 1 Byte */
  #define OP_PTBP 0x01 // Print Byte From Program
  #define OP_PTCP 0x02 // Print Char From Program

  /* Takes In 1 Word */
  #define OP_PTWM 0x03 // Print Word From Memory
  #define OP_PTBM 0x04 // Print Byte From Memory
  #define OP_PTCM 0x05 // Print Char From Memory

  /* Takes In Nothing */
  #define OP_PTWI 0x06 // Print Word From Memory Pointer
  #define OP_PTBI 0x07 // Print Byte From Memory Pointer
  #define OP_PTCI 0x08 // Print Char From Memory Pointer

  /* Takes In 1 Byte */
  #define OP_PTWR 0x09 // Print Word From Regester
  #define OP_PTBR 0x0A // Print Byte From Register
  #define OP_PTCR 0x0B // Print Char From Register





#endif

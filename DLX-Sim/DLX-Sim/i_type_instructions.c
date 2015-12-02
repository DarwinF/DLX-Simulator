#include "i_type_instructions.h"

#define   RS1_MASK        0x7C00  // 0111 1100 0000 0000
#define   RD_MASK         0x03E0  // 0000 0011 1110 0000

#define   IMMEDIATE_MASK  0x0000FFFF

WORD get_memory_address(WORD data, HWORD reg_info)
{
  WORD rs1 = (reg_info & RS1_MASK) >> 10;
  WORD imm = data & IMMEDIATE_MASK;

  return registers->gpr[rs1] + imm;
}
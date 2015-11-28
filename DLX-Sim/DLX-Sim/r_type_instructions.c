#include "r_type_instructions.h"

#define RS1_SHIFT     21
#define RS2_SHIFT     16
#define RS2_MASK      0x0000001F
#define RD_SHIFT      11  

WORD add_instruction(WORD data)
{
  // Rd = Rs1 + Rs2
  HWORD rs1 = (data >> RS1_SHIFT);
  HWORD rs2 = (data >> RS2_SHIFT) & RS2_MASK;

  return registers->gpr[rs1] + registers->gpr[rs2];
}

WORD sub_instruction(WORD data)
{
  // Rd = Rs1 - Rs2
  HWORD rs1 = data >> RS1_SHIFT;
  HWORD rs2 = data >> RS2_SHIFT;

  return registers->gpr[rs1] - registers->gpr[rs2];
}
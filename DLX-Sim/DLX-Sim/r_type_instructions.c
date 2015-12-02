#include "r_type_instructions.h"

#define   RS1_MASK    0x7C00  // 0111 1100 0000 0000
#define   RS2_MASK    0x03E0  // 0000 0011 1110 0000
#define   RD_MASK     0x001F  // 0000 0000 0001 1111

#define   RS1_OFFSET  10
#define   RS2_OFFSET  5

WORD add_instruction(HWORD reg_info)
{
  // Rd = Rs1 + Rs2
  HWORD rs1 = (reg_info & RS1_MASK) >> RS1_OFFSET;
  HWORD rs2 = (reg_info & RS2_MASK) >> RS2_OFFSET;

  return registers->gpr[rs1] + registers->gpr[rs2];
}

WORD sub_instruction(HWORD reg_info)
{
  // Rd = Rs1 - Rs2
  HWORD rs1 = (reg_info & RS1_MASK) >> RS1_OFFSET;
  HWORD rs2 = (reg_info & RS2_MASK) >> RS2_OFFSET;

  return registers->gpr[rs1] - registers->gpr[rs2];
}
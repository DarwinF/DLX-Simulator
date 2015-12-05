#include "r_type_instructions.h"

#define   RS1_MASK    0x7C00  // 0111 1100 0000 0000
#define   RS2_MASK    0x03E0  // 0000 0011 1110 0000
#define   RD_MASK     0x001F  // 0000 0000 0001 1111

#define   RS1_OFFSET  10
#define   RS2_OFFSET  5

HWORD extract_register(HWORD mask, HWORD offset, HWORD reg_info)
{
  return (reg_info & mask) >> offset;
}

WORD add_instruction(WORD data, HWORD reg_info)
{
  // Rd = Rs1 + Rs2
  HWORD rs1 = extract_register(RS1_MASK, RS1_OFFSET, reg_info);
  HWORD rs2 = extract_register(RS2_MASK, RS2_OFFSET, reg_info);

  return registers->gpr[rs1] + registers->gpr[rs2];
}

WORD sub_instruction(WORD data, HWORD reg_info)
{
  // Rd = Rs1 - Rs2
  HWORD rs1 = extract_register(RS1_MASK, RS1_OFFSET, reg_info);
  HWORD rs2 = extract_register(RS2_MASK, RS2_OFFSET, reg_info);

  return registers->gpr[rs1] - registers->gpr[rs2];
}

WORD sll_instruction(WORD data, HWORD reg_info)
{
  // Rd = Rs1 << (Rs2 % 8)
  HWORD rs1 = extract_register(RS1_MASK, RS1_OFFSET, reg_info);
  HWORD rs2 = extract_register(RS2_MASK, RS2_OFFSET, reg_info);

  return (registers->gpr[rs1] << (registers->gpr[rs2] % 8));
}

WORD srl_instruction(WORD data, HWORD reg_info)
{
  // Rd = Rs1 >> (Rs2 % 8)
  HWORD rs1 = extract_register(RS1_MASK, RS1_OFFSET, reg_info);
  HWORD rs2 = extract_register(RS2_MASK, RS2_OFFSET, reg_info);

  return (registers->gpr[rs1] >> (registers->gpr[rs2] % 8));
}

WORD sra_instruction(WORD data, HWORD reg_info)
{
  return srl_instruction(data, reg_info);
}


WORD and_instruction(WORD data, HWORD reg_info)
{
  // Rd = Rs1 & Rs2
  HWORD rs1 = extract_register(RS1_MASK, RS1_OFFSET, reg_info);
  HWORD rs2 = extract_register(RS2_MASK, RS2_OFFSET, reg_info);

  return registers->gpr[rs1] & registers->gpr[rs2];
}

WORD  or_instruction(WORD data, HWORD reg_info)
{
  // Rd = Rs1 | Rs2
  HWORD rs1 = extract_register(RS1_MASK, RS1_OFFSET, reg_info);
  HWORD rs2 = extract_register(RS2_MASK, RS2_OFFSET, reg_info);

  return registers->gpr[rs1] | registers->gpr[rs2];
}

WORD xor_instruction(WORD data, HWORD reg_info)
{
  // Rd = Rs1 ^ Rs2
  HWORD rs1 = extract_register(RS1_MASK, RS1_OFFSET, reg_info);
  HWORD rs2 = extract_register(RS2_MASK, RS2_OFFSET, reg_info);

  return registers->gpr[rs1] ^ registers->gpr[rs2];
}

WORD seq_instruction(WORD data, HWORD reg_info)
{
  // Rd = (Rs1 == Rs2) ? 1 : 0

  HWORD rs1 = extract_register(RS1_MASK, RS1_OFFSET, reg_info);
  HWORD rs2 = extract_register(RS2_MASK, RS2_OFFSET, reg_info);

  if (registers->gpr[rs1] == registers->gpr[rs2])
    return 1;
  else
    return 0;
}

WORD sne_instruction(WORD data, HWORD reg_info)
{
  // Rd = (Rs1 != Rs2) ? 1 : 0
  HWORD rs1 = extract_register(RS1_MASK, RS1_OFFSET, reg_info);
  HWORD rs2 = extract_register(RS2_MASK, RS2_OFFSET, reg_info);

  if (registers->gpr[rs1] == registers->gpr[rs2])
    return 0;
  else
    return 1;
}

WORD slt_instruction(WORD data, HWORD reg_info)
{
  // Rd = (Rs1 < Rs2) ? 1 : 0
  HWORD rs1 = extract_register(RS1_MASK, RS1_OFFSET, reg_info);
  HWORD rs2 = extract_register(RS2_MASK, RS2_OFFSET, reg_info);

  if (registers->gpr[rs1] < registers->gpr[rs2])
    return 1;
  else
    return 0;
}

WORD sle_instruction(WORD data, HWORD reg_info)
{
  // Rd = (Rs1 <= Rs2) ? 1 : 0
  HWORD rs1 = extract_register(RS1_MASK, RS1_OFFSET, reg_info);
  HWORD rs2 = extract_register(RS2_MASK, RS2_OFFSET, reg_info);

  if (registers->gpr[rs1] <= registers->gpr[rs2])
    return 1;
  else
    return 0;
}
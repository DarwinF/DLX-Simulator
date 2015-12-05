#include "i_type_instructions.h"

#define   RS1_MASK        0x7C00  // 0111 1100 0000 0000
#define   RD_MASK         0x03E0  // 0000 0011 1110 0000

#define   RS1_OFFSET      10

#define   IMMEDIATE_MASK  0x0000FFFF

WORD get_memory_address(WORD data, HWORD reg_info)
{
  HWORD rs1 = (reg_info & RS1_MASK) >> RS1_OFFSET;
  HWORD imm = data & IMMEDIATE_MASK;

  return registers->gpr[rs1] + imm;
}

WORD beqz_instruction(WORD data, HWORD reg_info)
{
  // PC += (Rs1 == 0) ? extend(immediate) : 0
  HWORD rs1 = (reg_info & RS1_MASK) >> RS1_OFFSET;

  if (registers->gpr[rs1] == 0)
    return data & IMMEDIATE_MASK;
  else
    return 0;
}

WORD bnez_instruction(WORD data, HWORD reg_info)
{
  // PC += (Rs1 != 0) ? extend(immediate) : 0
  HWORD rs1 = (reg_info & RS1_MASK) >> RS1_OFFSET;

  if (registers->gpr[rs1] != 0)
    return data & IMMEDIATE_MASK;
  else
    return 0;
}

WORD addi_instruction(WORD data, HWORD reg_info)
{
  // Rd = Rs1 + extend(immediate)
  HWORD rs1 = (reg_info & RS1_MASK) >> RS1_OFFSET;
  HWORD imm = data & IMMEDIATE_MASK;

  return registers->gpr[rs1] + imm;
}

WORD subi_instruction(WORD data, HWORD reg_info)
{
  // Rd = Rs1 - extend(immediate)
  HWORD rs1 = (reg_info & RS1_MASK) >> RS1_OFFSET;
  HWORD imm = data & IMMEDIATE_MASK;

  return registers->gpr[rs1] - imm;
}

WORD andi_instruction(WORD data, HWORD reg_info)
{
  // Rd = Rs1 & immediate
  HWORD rs1 = (reg_info & RS1_MASK) >> RS1_OFFSET;
  HWORD imm = data & IMMEDIATE_MASK;

  return registers->gpr[rs1] & imm;
}

WORD  ori_instruction(WORD data, HWORD reg_info)
{
  // Rd = Rs1 | immediate
  HWORD rs1 = (reg_info & RS1_MASK) >> RS1_OFFSET;
  HWORD imm = data & IMMEDIATE_MASK;

  return registers->gpr[rs1] | imm;
}

WORD xori_instruction(WORD data, HWORD reg_info)
{
  // Rd = Rs1 ^ immediate
  HWORD rs1 = (reg_info & RS1_MASK) >> RS1_OFFSET;
  HWORD imm = data & IMMEDIATE_MASK;

  return registers->gpr[rs1] ^ imm;
}

WORD lhi_instruction(WORD data, HWORD reg_info)
{
  // Rd = immediate << 16
  HWORD rs1 = (reg_info & RS1_MASK) >> RS1_OFFSET;
  HWORD imm = data & IMMEDIATE_MASK;

  return imm << 16;
}

WORD jr_instruction(WORD data, HWORD reg_info)
{
  // PC = Rs1
  HWORD rs1 = (reg_info & RS1_MASK) >> RS1_OFFSET;
  HWORD imm = data & IMMEDIATE_MASK;

  return registers->gpr[rs1];
}

WORD jalr_instruction(WORD data, HWORD reg_info)
{
  // R31 = PC + 4; PC = Rs1
  HWORD rs1 = (reg_info & RS1_MASK) >> RS1_OFFSET;
  HWORD imm = data & IMMEDIATE_MASK;

  return registers->gpr[rs1];
}

WORD slli_instruction(WORD data, HWORD reg_info)
{
  // Rd = Rs1 << (immediate % 8)
  HWORD rs1 = (reg_info & RS1_MASK) >> RS1_OFFSET;
  HWORD imm = data & IMMEDIATE_MASK;
  
  return registers->gpr[rs1] << (imm % 8);
}

WORD srli_instruction(WORD data, HWORD reg_info)
{
  // Rd = Rs1 >> (immediate % 8)
  HWORD rs1 = (reg_info & RS1_MASK) >> RS1_OFFSET;
  HWORD imm = data & IMMEDIATE_MASK;

  return registers->gpr[rs1] >> (imm % 8);
}

WORD srai_instruction(WORD data, HWORD reg_info)
{
  return srli_instruction(data, reg_info);
}

WORD seqi_instruction(WORD data, HWORD reg_info)
{
  // Rd = (Rs1 == extend(immediate)) ? 1 : 0
  HWORD rs1 = (reg_info & RS1_MASK) >> RS1_OFFSET;
  HWORD imm = data & IMMEDIATE_MASK;

  if (registers->gpr[rs1] == imm)
    return 1;
  else
    return 0;
}

WORD snei_instruction(WORD data, HWORD reg_info)
{
  // Rd = (Rs1 != extend(immediate)) ? 1 : 0
  HWORD rs1 = (reg_info & RS1_MASK) >> RS1_OFFSET;
  HWORD imm = data & IMMEDIATE_MASK;

  if (registers->gpr[rs1] != imm)
    return 1;
  else
    return 0;
}

WORD slti_instruction(WORD data, HWORD reg_info)
{
  // Rd = (Rs1 < extend(immediate)) ? 1 : 0
  HWORD rs1 = (reg_info & RS1_MASK) >> RS1_OFFSET;
  HWORD imm = data & IMMEDIATE_MASK;

  if (registers->gpr[rs1] < imm)
    return 1;
  else
    return 0;
}

WORD slei_instruction(WORD data, HWORD reg_info)
{
  // Rd = (Rs1 <= extend(immediate)) ? 1 : 0
  HWORD rs1 = (reg_info & RS1_MASK) >> RS1_OFFSET;
  HWORD imm = data & IMMEDIATE_MASK;

  if (registers->gpr[rs1] <= imm)
    return 1;
  else
    return 0;
}

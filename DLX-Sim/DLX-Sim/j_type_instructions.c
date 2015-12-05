#include "j_type_instructions.h"

WORD j_instruction(WORD data, HWORD reg_info)
{
  // PC += extend(value)
  return data;
}

WORD jal_instruction(WORD data, HWORD reg_info)
{
  // R31 = PC + 4; PC += extend(value)
  return data;
}
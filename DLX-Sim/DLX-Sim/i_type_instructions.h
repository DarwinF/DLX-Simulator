#ifndef dlx_i_type_instructions_h_
#define dlx_i_type_instructions_h_

#include "dlx_sim.h"
#include "register_file_handler.h"

// Instructions
WORD get_memory_address(WORD, HWORD);

WORD beqz_instruction(WORD, HWORD);
WORD bnez_instruction(WORD, HWORD);
WORD addi_instruction(WORD, HWORD);
WORD subi_instruction(WORD, HWORD);
WORD andi_instruction(WORD, HWORD);
WORD  ori_instruction(WORD, HWORD);
WORD xori_instruction(WORD, HWORD);
WORD  lhi_instruction(WORD, HWORD);
WORD   jr_instruction(WORD, HWORD);
WORD jalr_instruction(WORD, HWORD);
WORD slli_instruction(WORD, HWORD);
WORD srli_instruction(WORD, HWORD);
WORD srai_instruction(WORD, HWORD);
WORD seqi_instruction(WORD, HWORD);
WORD snei_instruction(WORD, HWORD);
WORD slti_instruction(WORD, HWORD);
WORD slei_instruction(WORD, HWORD);

#endif
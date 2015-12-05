#ifndef dlx_instruction_handler_h_
#define dlx_instruction_handler_h_

#include "dlx_sim.h"

#include "r_type_instructions.h"
#include "i_type_instructions.h"
#include "j_type_instructions.h"
#include "custom_instructions.h"

// Function Pointer for Instructions
typedef WORD(*InstructionFunc)(WORD, HWORD);

static InstructionFunc r_type_instructions[] = {
  nop_instruction, nop_instruction, nop_instruction, nop_instruction, sll_instruction, nop_instruction,     //  0-5
  srl_instruction, sra_instruction, nop_instruction, nop_instruction, nop_instruction, nop_instruction,     //  6-11
  nop_instruction, nop_instruction, nop_instruction, nop_instruction, nop_instruction, nop_instruction,     // 12-17
  nop_instruction, nop_instruction, nop_instruction, nop_instruction, nop_instruction, nop_instruction,     // 18-23
  nop_instruction, nop_instruction, nop_instruction, nop_instruction, nop_instruction, nop_instruction,     // 24-29
  nop_instruction, nop_instruction, add_instruction, nop_instruction, sub_instruction, nop_instruction,     // 30-35
  and_instruction,  or_instruction, xor_instruction, nop_instruction, seq_instruction, sne_instruction,     // 36-41
  slt_instruction, nop_instruction, sle_instruction                                                         // 42-44
};

static InstructionFunc ij_type_instructions[] = {
  nop_instruction, nop_instruction, j_instruction, jal_instruction, beqz_instruction, bnez_instruction,
  nop_instruction, nop_instruction, addi_instruction, nop_instruction, subi_instruction, nop_instruction,
  andi_instruction, ori_instruction, xori_instruction, lhi_instruction, nop_instruction, nop_instruction,
  jr_instruction, jalr_instruction, slli_instruction, nop_instruction, srli_instruction, srai_instruction,
  seqi_instruction, snei_instruction, slti_instruction, nop_instruction, slei_instruction, nop_instruction,
  nop_instruction, nop_instruction, nop_instruction, nop_instruction, nop_instruction, get_memory_address, // lw
  nop_instruction, nop_instruction, nop_instruction, nop_instruction, nop_instruction, nop_instruction,
  nop_instruction, get_memory_address // sw
};

#endif

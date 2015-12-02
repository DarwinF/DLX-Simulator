#ifndef dlx_instruction_handler_h_
#define dlx_instruction_handler_h_

#include "dlx_sim.h"

#include "r_type_instructions.h"
#include "i_type_instructions.h"
#include "j_type_instructions.h"
#include "custom_instructions.h"

// Function Pointer for Instructions
typedef WORD(*InstructionFunc)(HWORD);

static InstructionFunc instruction_table[] = {
  nop_instruction, nop_instruction, nop_instruction, nop_instruction, nop_instruction, nop_instruction, //  0-5
  nop_instruction, nop_instruction, nop_instruction, nop_instruction, nop_instruction, nop_instruction, //  6-11
  nop_instruction, nop_instruction, nop_instruction, nop_instruction, nop_instruction, nop_instruction, // 12-17
  nop_instruction, nop_instruction, nop_instruction, nop_instruction, nop_instruction, nop_instruction, // 18-23
  nop_instruction, nop_instruction, nop_instruction, nop_instruction, sub_instruction, nop_instruction, // 24-29
  nop_instruction, nop_instruction, add_instruction, nop_instruction, nop_instruction, nop_instruction, // 30-35
  nop_instruction, nop_instruction, nop_instruction, nop_instruction, nop_instruction, nop_instruction, // 36-41
  nop_instruction, nop_instruction, nop_instruction                                                     // 42-45
};

#endif

#ifndef dlx_r_type_instructions_h_
#define dlx_r_type_instructions_h_

#include "dlx_sim.h"
#include "register_file_handler.h"

// Instructions
WORD add_instruction(WORD, HWORD);
WORD sub_instruction(WORD, HWORD);
WORD sll_instruction(WORD, HWORD);
WORD srl_instruction(WORD, HWORD);
WORD sra_instruction(WORD, HWORD);
WORD and_instruction(WORD, HWORD);
WORD  or_instruction(WORD, HWORD);
WORD xor_instruction(WORD, HWORD);
WORD seq_instruction(WORD, HWORD);
WORD sne_instruction(WORD, HWORD);
WORD slt_instruction(WORD, HWORD);
WORD sle_instruction(WORD, HWORD);

#endif
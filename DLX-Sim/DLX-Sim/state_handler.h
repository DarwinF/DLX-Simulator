#ifndef dlx_state_handler_h_
#define dlx_state_handler_h_

#include "dlx_sim.h"
#include "instruction_handler.h"
#include "memory_handler.h"

typedef enum
{
	INSTRUCTION_FETCH,
	INSTRUCTION_DECODE,
	INSTRUCTION_EXECUTE,
	MEMORY_ACCESS,
	WRITE_BACK
}Stages;

typedef struct
{
	// Current Stage
	Stages current_stage;

	// Instruction
	WORD instruction;
  WORD data;

  // Registers in use
  HWORD reg_info;      // R: (Return Flag, rs1, rs2, rd) I: (Return Flag, rs1, rd, GARGBAGE) J: (GARBAGE)

	// Function
  InstructionFunc function;

  // Return Value
  WORD return_value;

	// Result: register value, loaded/to store data
	// List of registers (?)
}State;

// Function Declerations
State* CreateState();
int DestroyState(State *);
DWORD ProcessState(State *, DWORD);

#endif
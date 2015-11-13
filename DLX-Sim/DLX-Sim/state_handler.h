#ifndef dlx_state_handler_h_
#define dlx_state_handler_h_

#include "dlx_sim.h"
#include "instruction_handler.h"

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

	// Function
  InstructionFunc function;

	// Result: register value, loaded/to store data
	// List of registers (?)
}State;

// Function Declerations
State* CreateState();
int DestroyState(State *);
void ProcessState(State *);

#endif
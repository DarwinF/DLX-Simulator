#ifndef dlx_state_handler_h_
#define dlx_state_handler_h_

#include "dlx_sim.h"
#include "instruction_handler.h"

typedef enum
{
	InstructionFetch,
	InstructionDecode,
	InstructionExecute,
	MemoryAccess,
	WriteBack
}Stages;

typedef struct
{
	uint32_t
		zeros : 6,
		rs1 : 5,
		rs2 : 5,
		rd : 5,
		unused : 5,
		opcode : 6;
}RTypeInstruction;

typedef struct
{
	uint32_t
		opcode : 6,
		rs1 : 5,
		rd : 5,
		immediate : 16;
}ITypeInstruction;

typedef struct
{
	uint32_t
		opcode : 6,
		value : 26;
}JTypeInstruction;

typedef union
{
	RTypeInstruction r_instruction;
	ITypeInstruction i_instruction;
	JTypeInstruction j_instruction;
}Instruction;

typedef struct
{
	// Current Stage
	Stages current_stage;

	// Instruction
	uint32_t instruction;

	// Opcode, Parameters
	Instruction formatted_instruction;

	// Function
  InstructionFunc function;

	// Result: register value, loaded/to store data
	// List of registers (?)
}State;

// Function Declerations
State* CreateState();
int DestroyState(State *);

#endif
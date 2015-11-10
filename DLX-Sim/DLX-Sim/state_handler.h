#ifndef dlx_state_handler_h_
#define dlx_state_handler_h_

#include "dlx_sim.h"

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
	uint
		zeros : 6,
		rs1 : 5,
		rs2 : 5,
		rd : 5,
		unused : 5,
		opcode : 6;
}RTypeInstruction;

typedef struct
{
	uint
		opcode : 6,
		rs1 : 5,
		rd : 5,
		immediate : 16;
}ITypeInstruction;

typedef struct
{
	uint
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
	uint instruction;

	// Opcode, Parameters
	Instruction formatted_instruction;

	// Function
	// Result: register value, loaded/to store data
	// List of registers (?)
}State;

#endif
#ifndef dlx_register_file_handler_h_
#define dlx_register_file_handler_h_

#include "dlx_sim.h"

#define r0 0

// General Purpose
typedef struct
{
	WORD r1;
	WORD r2;
	WORD r3;
}GPRegisters;

// Floating Point
typedef struct
{
	WORD f0;
	WORD f1;
	WORD f2;
	WORD f3;
}FPRegisters;

typedef struct
{
	// 32 General Purpose Registers
	GPRegisters *gprs;
	// 32 Floating Point Registers
	FPRegisters *fprs;
}Registers;

// Function Declerations
Registers* CreateRegisters();
int DestroyRegisters(Registers *);

#endif
#ifndef dlx_register_file_handler_h_
#define dlx_register_file_handler_h_

#include "dlx_sim.h"

#define r0 0

// General Purpose
typedef struct
{
	uint32_t r1;
	uint32_t r2;
	uint32_t r3;
}GPRegisters;

// Floating Point
typedef struct
{
	uint32_t f0;
	uint32_t f1;
	uint32_t f2;
	uint32_t f3;
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
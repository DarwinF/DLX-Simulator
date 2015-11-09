#ifndef dlx_register_file_handler_h_
#define dlx_register_file_handler_h_

typedef unsigned int uint;

// General Purpose
typedef struct
{
	const uint r0;
	uint r1;
	uint r2;
	uint r3;
}GPRegisters;

// Floating Point
typedef struct
{
	uint f0;
	uint f1;
	uint f2;
	uint f3;
}FPRegisters;

typedef struct
{
	// 32 General Purpose Registers
	GPRegisters *gprs;
	// 32 Floating Point Registers
	FPRegisters *fprs;
}Registers;

#endif
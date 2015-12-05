#ifndef dlx_register_file_handler_h_
#define dlx_register_file_handler_h_

#include "dlx_sim.h"

typedef struct
{
	// 32 General Purpose Registers
  WORD gpr[32];
	// 32 Floating Point Registers
  WORD fpr[32];
  DWORD program_counter;
}Registers;

extern Registers* registers;

// Function Declerations
Registers* CreateRegisters();
int DestroyRegisters(Registers *);

#endif
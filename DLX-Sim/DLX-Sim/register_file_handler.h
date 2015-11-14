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
  WORD r4;
  WORD r5;
  WORD r6;
  WORD r7;
  WORD r8;
  WORD r9;
  WORD r10;
  WORD r11;
  WORD r12;
  WORD r13;
  WORD r14;
  WORD r15;
  WORD r16;
  WORD r17;
  WORD r18;
  WORD r19;
  WORD r20;
  WORD r21;
  WORD r22;
  WORD r23;
  WORD r24;
  WORD r25;
  WORD r26;
  WORD r27;
  WORD r28;
  WORD r29;
  WORD r30;
  WORD r31;
}GPRegisters;

// Floating Point
typedef struct
{
	WORD f0;
	WORD f1;
	WORD f2;
	WORD f3;
  WORD f4;
  WORD f5;
  WORD f6;
  WORD f7;
  WORD f8;
  WORD f9;
  WORD f10;
  WORD f11;
  WORD f12;
  WORD f13;
  WORD f14;
  WORD f15;
  WORD f16;
  WORD f17;
  WORD f18;
  WORD f19;
  WORD f20;
  WORD f21;
  WORD f22;
  WORD f23;
  WORD f24;
  WORD f25;
  WORD f26;
  WORD f27;
  WORD f28;
  WORD f29;
  WORD f30;
  WORD f31;
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
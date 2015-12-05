#ifndef dlx_memory_handler_h_
#define dlx_memory_handler_h_

#include "dlx_sim.h"

typedef struct
{
  WORD *mem;
}Memory;

// Constants
#define MEMORY_SIZE_MB  64
#define MEMORY_SIZE_KB  MEMORY_SIZE_MB * 1024
#define MEMORY_SIZE_B   MEMORY_SIZE_KB * 1024
#define MEMORY_SIZE_W   MEMORY_SIZE_B / 4

// Gloabl Memory Object
extern Memory *memory;

// Function Declerations
Memory *CreateMemory();
void PrintMemory(Memory *);
void DestroyMemory(Memory *);

#endif

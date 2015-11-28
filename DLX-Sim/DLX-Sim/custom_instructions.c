#include "custom_instructions.h"

WORD nop_instruction(WORD w, HWORD r)
{
  logger->info("Executing NOP instruction.\n");
  return 0;
}
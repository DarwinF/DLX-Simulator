#include "dlx_sim.h"
#include "register_file_handler.h"

// Function Declerations

Registers* CreateRegisters()
{
  int status = REG_SUCCESS;
  Registers *r = (Registers*)malloc(sizeof(Registers));

  if (r == NULL)
  {
    logger->error("Unable to allocate memory for the registers.\n");
    status = REG_NO_MEMORY_ERROR;
  }

  if (status < 0)
  {
    logger->error("Registers could not be initialized. Freeing the memory allocated for the registers.\n");
    DestroyRegisters(r);
  }

  return r;
}

int DestroyRegisters(Registers *r)
{
  free(r);

  return REG_SUCCESS;
}
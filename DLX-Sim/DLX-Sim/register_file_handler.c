#include "dlx_sim.h"
#include "register_file_handler.h"

// Function Declerations
int InitializeRegisters(Registers *);

Registers* CreateRegisters()
{
  int status = REG_SUCCESS;
  Registers *r = (Registers*)malloc(sizeof(Registers));

  if (r == NULL)
  {
    logger->error("Unable to allocate memory for the registers.\n");
    status = REG_NO_MEMORY_ERROR;
  }
  else
    status = InitializeRegisters(r);

  if (status < 0)
  {
    logger->error("Registers could not be initialized. Freeing the memory allocated for the registers.\n");
    DestroyRegisters(r);
  }

  return r;
}

int InitializeRegisters(Registers *r)
{
  int status = REG_SUCCESS;

  // Setup Default Values
  GPRegisters *gp = (GPRegisters *)malloc(sizeof(GPRegisters));
  FPRegisters *fp = (FPRegisters *)malloc(sizeof(FPRegisters));

  if (gp == NULL || fp == NULL)
  {
    logger->error("Unable to allocate memory for the general purpose or floating point registers.\n");
    status = REG_NO_MEMORY_ERROR;
  }
  else
  {
    r->gprs = gp;
    r->fprs = fp;
  }

  return status;
}

int DestroyRegisters(Registers *r)
{
  free(r->gprs);
  free(r->fprs);
  free(r);

  return REG_SUCCESS;
}
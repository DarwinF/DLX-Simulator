#include "memory_handler.h"

Memory *CreateMemory()
{
  int status = MEMORY_SUCCESS;
  char *msg[128];
  Memory *m = (Memory *)malloc(sizeof(Memory));

  if (m == NULL)
  {
    status = MEMORY_GENERAL_INIT_ERROR;
    logger->error("Couldn't allocate memory object.\n");
  }
  else
  {
    WORD *mem = malloc(MEMORY_SIZE_B);

    if (mem == NULL)
    {
      status = MEMORY_NO_MEMORY_ERROR;
      sprintf(msg, "Couldn't allocate %d bytes of memory.\n", MEMORY_SIZE_B);

      logger->error(msg);
      free(m);
    }
    
    m->mem = mem;

    sprintf(msg, "Allocated %d bytes of memory.\n", MEMORY_SIZE_B);
    logger->info(msg);
  }

  return m;
}

void PrintMemory(Memory *m)
{
  int i = 0;
  for (; i < MEMORY_SIZE_W; i++)
  {
    printf("%d\n", m->mem[i]);
  }
}

void DestoryMemory(Memory *m)
{
  free(m->mem);
  free(m);
}
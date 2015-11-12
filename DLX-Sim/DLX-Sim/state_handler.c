#include "dlx_sim.h"
#include "state_handler.h"

// Function Declerations
int InitializeState(State *);

State* CreateState()
{
  int status = STATE_SUCCESS;
  State *s = (State *)malloc(sizeof(State));
  
  if (s == NULL)
    status = STATE_NO_MEMORY_ERROR;
  else
    status = InitializeState(s);

  if (status < 0)
  {
    // TODO: Add logging
    DestroyState(s);
  }

  return s;
}

int InitializeState(State* s)
{
  s->current_stage = InstructionFetch;
  s->instruction = 0;

  return STATE_SUCCESS;
}

int DestroyState(State *s)
{
  free(s);

  return STATE_SUCCESS;
}
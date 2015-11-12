#include <stdlib.h>

#include "state_machine.h"

int InitializeStateMachine(StateMachine *);

StateMachine* CreateStateMachine()
{
	int status = SM_GENERAL_INIT_ERROR;
	StateMachine *sm = (StateMachine *)malloc(sizeof(StateMachine));
	
  if (sm == NULL)
    status = SM_NO_MEMORY_ERROR;
  else
    status = InitializeStateMachine(sm);

	if (0 > status)
	{
		// TODO: Add Logging
		sm->error = status;
	}
  else
  {
    sm->error = SM_SUCCESS;
  }

	return sm;
}

int InitializeStateMachine(StateMachine *sm)
{
  int status = SM_SUCCESS;
	// Setup Current State
  State *current_state = CreateState();
	// Setup Registers
  Registers *current_registers = CreateRegisters();

  if (current_state == NULL || current_registers == NULL)
    status = SM_GENERAL_INIT_ERROR;
  else
  {
    sm->registers = current_registers;
    sm->state = current_state;
  }

	return status;
}

int DestroyStateMachine(StateMachine *sm)
{
	// Cleanup State
  DestroyState(sm->state);
	// Cleanup Registers
  DestroyRegisters(sm->registers);

	free(sm);

  return SM_SUCCESS;
}

void RunStateMachine(StateMachine *sm)
{

}
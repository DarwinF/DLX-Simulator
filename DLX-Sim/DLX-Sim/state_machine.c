#include <stdlib.h>

#include "state_machine.h"

int InitializeStateMachine(StateMachine *);

StateMachine* CreateStateMachine()
{
	int ret_status = SM_GENERAL_INIT_ERROR;
	StateMachine *sm = (StateMachine *)malloc(sizeof(StateMachine));
	
	sm->status = SM_NOT_INITIALZED;
	sm->error = SM_NO_ERROR;
	sm->current_state = NULL;
	sm->registers = NULL;

	ret_status = InitializeStateMachine(sm);

	if (0 > ret_status)
	{
		// TODO: Add Logging
		sm->error = ret_status;
	}

	return sm;
}

int InitializeStateMachine(StateMachine *sm)
{
	// Setup Current State
	// Setup Registers

	// On success
	sm->status = SM_INITIALIZED;

	return SM_INITIALIZED;
}

void DestroyStateMachine(StateMachine *sm)
{
	// Cleanup State
	// Cleanup Registers

	free(sm);
}

void RunStateMachine(StateMachine *sm)
{
	
}
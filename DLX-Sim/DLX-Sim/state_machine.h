#ifndef dlx_state_machine_h_
#define dlx_state_machine_h_

#include "state_handler.h"
#include "register_file_handler.h"
#include "errors.h"

// Constants
#define SM_NOT_INITIALZED	0
#define SM_INITIALIZED		1

typedef struct
{
	int status;
	int error;
	// Current State
	State *current_state;
	// Registers
	Registers *registers;
}StateMachine;

// Function Declerations
StateMachine* CreateStateMachine();
void DestroyStateMachine(StateMachine *);
void RunStateMachine(StateMachine *);

#endif

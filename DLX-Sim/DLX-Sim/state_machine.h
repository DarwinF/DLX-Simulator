#ifndef dlx_state_machine_h_
#define dlx_state_machine_h_

#include "state_handler.h"

typedef struct
{
	int status;
	int error;

  // States
  State *state;
}StateMachine;

// Function Declerations
StateMachine* CreateStateMachine();
int DestroyStateMachine(StateMachine *);
void RunStateMachine(StateMachine *);

#endif

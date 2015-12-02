#ifndef dlx_state_machine_h_
#define dlx_state_machine_h_

#include "dlx_sim.h"

#include "state_handler.h"
#include "register_file_handler.h"
#include "memory_handler.h"
#include "file_handler.h"

typedef struct
{
	int status;
	int error;

  // States
  State *state;
}StateMachine;

DWORD program_counter;

// Function Declerations
StateMachine* CreateStateMachine();
int DestroyStateMachine(StateMachine *);
void RunStateMachine(StateMachine *);

#endif

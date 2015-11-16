#include "state_machine.h"

int main(void)
{
  // Exit if the logger can't be created
  int logger_status = CreateLogger(NULL);

  if (logger_status != LOGGER_INITALIZED)
    return -1;

  // Logger was created, start the program
	StateMachine *sm = CreateStateMachine();

	if (SM_SUCCESS != sm->error)
	{
    logger->error("State machine was not created.\n");
		DestroyStateMachine(sm);
	}
	else
	{
    logger->info("State machine was created. Starting the state machine main loop.\n");
		RunStateMachine(sm);
	}

  DestroyLogger();
	return 0;
}
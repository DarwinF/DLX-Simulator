#include <stdlib.h>

#include "state_machine.h"
#include "memory_handler.h"
#include "file_handler.h"

// Function Declerations
int InitializeStateMachine(StateMachine*);

Registers *registers;
Memory *memory;

StateMachine* CreateStateMachine()
{
  int status = SM_GENERAL_INIT_ERROR;
  StateMachine* sm = (StateMachine *)malloc(sizeof(StateMachine));

  if (sm == NULL)
  {
    logger->error("Unable to allocate memory for the state machine.\n");
    status = SM_NO_MEMORY_ERROR;
  }
  else
    status = InitializeStateMachine(sm);

  if (0 > status)
  {
    logger->error("Unable to initialize the state machine. Freeing memory allocated for the state machine.\n");
    sm->error = status;
  }
  else
  {
    sm->error = SM_SUCCESS;
  }

  return sm;
}

int InitializeStateMachine(StateMachine* sm)
{
  int status = SM_SUCCESS;
  // Setup Current State
  State* current_state = CreateState();
  // Setup Registers
  Registers* current_registers = CreateRegisters();
  // Setup Memory
  Memory* current_memory = CreateMemory();

  if (current_state == NULL || current_registers == NULL || current_memory == NULL)
    status = SM_GENERAL_INIT_ERROR;
  else
  {
    memory = current_memory;
    registers = current_registers;
    sm->state = current_state;

    WriteFileToMemory();

    registers->program_counter = 0;
  }

  return status;
}

int DestroyStateMachine(StateMachine* sm)
{
  // Cleanup State
  DestroyState(sm->state);
  // Cleanup Registers
  DestroyRegisters(registers);

  free(sm);

  return SM_SUCCESS;
}

void RunStateMachine(StateMachine* sm)
{
  // Setup
  DWORD cycle_counter = 0;

  // Loop
  while (cycle_counter < 1000000) // Temporary
  {
    registers->program_counter = ProcessState(sm->state, registers->program_counter);

    cycle_counter++;
  }

  // Cleanup
  DestroyStateMachine(sm);
}

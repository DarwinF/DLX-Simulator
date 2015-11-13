#include "dlx_sim.h"
#include "state_handler.h"

// Bit Manipulation Constants
#define             OPCODE_MASK           0xFC000000
#define             R_OPCODE_MASK         0x0000003F
#define             DATA_MASK             0x03FFFFFF
#define             OPCODE_OFFSET         26

// Function Declerations
int InitializeState(State *);

// Stage Functions
WORD Fetch();
HWORD DecodeOpcode(WORD);
WORD DecodeData(WORD);
void Execute(InstructionFunc, WORD);
void AccessMemory();
void WriteBack();

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
  s->current_stage = INSTRUCTION_FETCH;
  s->instruction = 0;

  return STATE_SUCCESS;
}

int DestroyState(State *s)
{
  free(s);

  return STATE_SUCCESS;
}

void ProcessState(State *s)
{
  switch (s->current_stage)
  {
  case INSTRUCTION_FETCH:
    s->instruction = Fetch();
    s->current_stage = INSTRUCTION_DECODE;
    break;
  case INSTRUCTION_DECODE:
    s->function = DecodeOpcode(s->instruction); // jumptable[DecodeOpcode]
    s->data = DecodeData(s->instruction);
    s->current_stage = INSTRUCTION_EXECUTE;
    break;
  case INSTRUCTION_EXECUTE:
    Execute(s->function, s->data);
    s->current_stage = MEMORY_ACCESS;
    break;
  case MEMORY_ACCESS:
    AccessMemory();
    s->current_stage = WRITE_BACK;
    break;
  case WRITE_BACK:
    WriteBack();
    s->current_stage = INSTRUCTION_FETCH;
    break;
  }
}

WORD Fetch()
{
  // ADD r1,r2,r3 (rd, rs1, rs2)
  WORD instruction = 0b00000000010000110000100000100000;

  return instruction;
}

HWORD DecodeOpcode(WORD i)
{
  HWORD opcode = 0;

  if (i & OPCODE_MASK)
  {
    // I or J Type
    opcode = (i >> OPCODE_OFFSET);
  }
  else
  {
    // R Type
    opcode = i & R_OPCODE_MASK;
  }

  return opcode;
}

WORD DecodeData(WORD instruction)
{
  return (instruction & DATA_MASK);
}

void Execute(InstructionFunc func, WORD data)
{
  // func(data);
}

void AccessMemory()
{
  
}

void WriteBack()
{
  
}
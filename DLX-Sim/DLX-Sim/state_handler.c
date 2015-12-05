#include "state_handler.h"
#include "memory_handler.h"

// Bit Manipulation Constants
#define             OPCODE_OFFSET         26
#define             J_TYPE_MAX_OPCODE     3

// WORD BASED MASKS
#define             OPCODE_MASK           0xFC000000
#define             R_OPCODE_MASK         0x0000003F
#define             DATA_MASK             0x03FFFFFF
#define             REGISTER_INFO_MASK    0x0000FFFF
#define             OPCODE_INFO_MASK      0xFFFF0000
#define             RS1_MASK_W            0x03E00000  // 0000 0011 1110 00....00
#define             RS2_MASK_W            0x001F0000
#define             RD_MASK_W             0x0000F800

// HALF WORD BASED MASKS
#define             RETURN_FLAG_HW        0x8000
#define             RS1_MASK_HW           0x7C00  // 0111 1100 0000 0000
#define             RS2_MASK_HW           0x03E0  // 0000 0011 1110 0000
#define             RD_MASK_HW            0x001F  // 0000 0000 0001 1111

#define             SW_OPCODE             0x2b
#define             LW_OPCODE             0x23

// Function Declerations
int InitializeState(State *);

// Stage Functions
WORD Fetch(DWORD);
WORD DecodeInformation(WORD);
WORD DecodeData(WORD);
WORD Execute(InstructionFunc, WORD, HWORD);
WORD AccessMemory(WORD, WORD, HWORD);
void WriteBack(WORD, HWORD, WORD);
void SaveValue(WORD, HWORD, HWORD);

State* CreateState()
{
  int status = STATE_SUCCESS;
  State *s = (State *)malloc(sizeof(State));
  
  if (s == NULL)
  {
    logger->error("Unable to allocate memory for the state.\n");
    status = STATE_NO_MEMORY_ERROR;
  }
  else
    status = InitializeState(s);

  if (status < 0)
  {
    logger->error("Unable to initialize the state. Freeing the memory allocated for the state.\n");
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

WORD ProcessState(State *s, WORD pc)
{
  WORD response;
  WORD new_pc = pc;

  switch (s->current_stage)
  {
  case INSTRUCTION_FETCH:
    s->instruction = Fetch(pc);
    s->current_stage = INSTRUCTION_DECODE;
    new_pc++;
    break;
  case INSTRUCTION_DECODE:
    response = DecodeInformation(s->instruction);

    s->reg_info = response & REGISTER_INFO_MASK;
    if ((s->instruction & OPCODE_MASK) >> OPCODE_OFFSET == 0)
      s->function = r_type_instructions[(response & OPCODE_INFO_MASK) >> 16];
    else
      s->function = ij_type_instructions[(response & OPCODE_INFO_MASK) >> 16];

    s->data = DecodeData(s->instruction);
    s->current_stage = INSTRUCTION_EXECUTE;
    break;
  case INSTRUCTION_EXECUTE:
    s->return_value = Execute(s->function, s->data, s->reg_info);
    s->current_stage = MEMORY_ACCESS;
    break;
  case MEMORY_ACCESS:
    s->return_value = AccessMemory(s->return_value, s->instruction, s->reg_info);
    s->current_stage = WRITE_BACK;
    break;
  case WRITE_BACK:
    WriteBack(s->return_value, s->reg_info, s->instruction);
    s->current_stage = INSTRUCTION_FETCH;
    break;
  }

  return new_pc;
}

WORD Fetch(DWORD pc)
{
  WORD instruction = memory->mem[pc];

  return instruction;
}

WORD DecodeInformation(WORD i)
{
  WORD response = 0;
  HWORD opcode = 0, registers = 0;

  if (i & OPCODE_MASK) {
    // I or J Type
    opcode = (i >> OPCODE_OFFSET);

    if (opcode != SW_OPCODE)
      registers = 1;

    registers = registers << 5;

    registers |= (i & RS1_MASK_W) >> 21;
    registers = registers << 5;

    registers |= (i & RS2_MASK_W) >> 16;
    registers = registers << 5;

    registers |= (i & RS2_MASK_W) >> 16;
  }
  else {
    // R Type
    opcode = i & R_OPCODE_MASK;
    registers = 1;
    registers = registers << 5;

    registers |= (i & RS1_MASK_W) >> 21;
    registers = registers << 5;

    registers |= (i & RS2_MASK_W) >> 16;
    registers = registers << 5;

    registers |= (i & RD_MASK_W) >> 11;
  }

  response = opcode;
  response = response << 16;
  response |= registers;

  return response;
}

WORD DecodeData(WORD instruction)
{
  return (instruction & DATA_MASK);
}

WORD Execute(InstructionFunc func, WORD data, HWORD reg_info)
{
  return func(data, reg_info);
}

WORD AccessMemory(WORD location, WORD instruction, HWORD reg_info)
{
  WORD memory_value = 0;
  WORD rd = 0;

  if (((instruction & OPCODE_MASK) >> OPCODE_OFFSET) == LW_OPCODE)
  {
    // LW: Rd = MEM[Rs1 + extend(immediate)]
    memory_value = memory->mem[location];
  }
  else if (((instruction & OPCODE_MASK) >> OPCODE_OFFSET) == SW_OPCODE)
  {
    // SW: MEM[Rs1 + extend(immediate)] = Rd  
    rd = (reg_info & RS2_MASK_HW) >> 5;
    memory->mem[location] = registers->gpr[rd];
  }

  return memory_value;
}

void WriteBack(WORD value, HWORD reg_info, WORD instruction)
{
  HWORD opcode = ((instruction & OPCODE_MASK) >> OPCODE_OFFSET);
  HWORD rd = reg_info & RD_MASK_HW;

  switch (opcode)
  {
  case 3:
    registers->gpr[31] = registers->program_counter + 1;
  case 2:
  case 4:
  case 5:
    registers->program_counter += value;
    break;
  case 19:
    registers->gpr[31] = registers->program_counter + 1;
  case 18:
    registers->program_counter += value;
    break;
  default:
    SaveValue(value, reg_info, rd);
    break;
  }
}

void SaveValue(WORD value, HWORD reg_info, HWORD dest)
{
  if ((reg_info & RETURN_FLAG_HW) == RETURN_FLAG_HW)
    registers->gpr[dest] = value;
}
#include "file_handler.h"

void WriteFileToMemory()
{
  FILE *source_file = fopen("binary", "rb");

  // Open our binary file
  // Read 4 bytes (1 WORD) at a time until EOF
  WORD instruction = 0, counter = 0;
  fread(&instruction, 4, 1, source_file);

  while (instruction != 0x00) {
    memory->mem[counter++] = instruction;
    fread(&instruction, 4, 1, source_file);
  }

  fclose(source_file);
}
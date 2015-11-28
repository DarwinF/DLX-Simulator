#ifndef dlx_logger_h_
#define dlx_logger_h_

#include "dlx_sim.h"

// Logging Functions
typedef (*Logging)(char *);

// Logger Struct
typedef struct
{
  char *file_path;
  int debugging;

  Logging debug;
  Logging info;
  Logging warn;
  Logging error;
  Logging dump_registers;
}Logger;

// Logger object
extern Logger *logger;

// Function Declerations
int CreateLogger(char *);
int DestroyLogger();

#endif
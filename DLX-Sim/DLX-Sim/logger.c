#include "logger.h"
#include "register_file_handler.h"

// Function Decleration
int InitializeLogger(char*, Logger*);
void Debug(char *);
void Info(char *);
void Warning(char *);
void Error(char *);
void DumpRegisters(char *);

Logger *logger;

int CreateLogger(char *file_path)
{
  int status = LOGGER_SUCCESS;
  Logger *l = (Logger *)malloc(sizeof(Logger));

  if (l != NULL)
    status = InitializeLogger(file_path, l);
  else
  {
    fprintf(stderr, "Unable to allocate memory for the logger.\n");
    status = LOGGER_NO_MEMORY_ERROR;
  }

  if (status == LOGGER_SUCCESS)
  {
    logger = l;
    Info("Logger initialized.\n");
    status = LOGGER_INITALIZED;
  }

  return status;
}

int InitializeLogger(char *file_path, Logger* l)
{
  int status = LOGGER_SUCCESS;

  // Set the file path to current directory or specified directory
  file_path = (file_path == NULL) ? "./dlx.log" : file_path;

  // Try opening the file to see if the path exists
  FILE *f = fopen(file_path, "a+");

  if (f == NULL) 
  {
    // Problem with the file path
    status = LOGGER_FILE_PATH_ERROR;
    fprintf(stderr, "Unable to use the file path (%s) specified.\n", file_path);
    DestroyLogger(l);
  }
  else
  {
    // Set file path
    l->file_path = file_path;

    // Set write functions
    l->debug = Debug;
    l->info = Info;
    l->warn = Warning;
    l->error = Error;
    l->dump_registers = DumpRegisters;

    // Set debugging
#if DNDEBUG
    l->debugging = 0;
#else
    l->debugging = 1;
#endif

    fclose(f);
  }

  return status;
}

int DestroyLogger()
{
  Info("Destroying the logger.\n");

  free(logger);

  return LOGGER_SUCCESS;
}

void Debug(char *msg)
{
  if (logger->debugging)
  {
    FILE *f = fopen(logger->file_path, "a");
    fprintf(f, "[DEBUG] :: %s", msg);
    fclose(f);
  }
}

void Info(char *msg)
{
  FILE *f = fopen(logger->file_path, "a");
  fprintf(f, "[INFO] :: %s", msg);
  fclose(f);
}

void Warning(char *msg)
{
  FILE *f = fopen(logger->file_path, "a");
  fprintf(f, "[WARN] :: %s", msg);
  fclose(f);
}

void Error(char *msg)
{
  FILE *f = fopen(logger->file_path, "a");
  fprintf(f, "[ERROR] :: %s", msg);
  fclose(f);
}

void DumpRegisters(char *msg)
{
  FILE *f = fopen(logger->file_path, "a");
  fprintf(f, "Dumping Registers.... \n");
  fprintf(f, "\tRS1: %d\n\tRS2: %d\n\tRD: %d\n", registers->gpr[2], registers->gpr[3], registers->gpr[1]);
  fclose(f);
}
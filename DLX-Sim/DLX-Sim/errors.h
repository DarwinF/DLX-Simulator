#ifndef dlx_errors_h_
#define dlx_errors_h_

// State Machine Errors
#define SM_SUCCESS 				         0
#define SM_GENERAL_INIT_ERROR	    -1
#define SM_NO_MEMORY_ERROR        -2

// Register Errors
#define REG_SUCCESS                0
#define REG_GENERAL_INIT_ERROR    -1
#define REG_NO_MEMORY_ERROR       -2

// State Errors
#define STATE_SUCCESS              0
#define STATE_GENERAL_INIT_ERROR  -1
#define STATE_NO_MEMORY_ERROR     -2

// Logger Errors
#define LOGGER_INITALIZED          1
#define LOGGER_SUCCESS             0
#define LOGGER_GENERAL_INIT_ERROR -1
#define LOGGER_NO_MEMORY_ERROR    -2
#define LOGGER_FILE_PATH_ERROR    -3

// Memory Errors
#define MEMORY_INITIALIZED         1
#define MEMORY_SUCCESS             0
#define MEMORY_GENERAL_INIT_ERROR -1
#define MEMORY_NO_MEMORY_ERROR    -2

#endif

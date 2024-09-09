#include <stdint.h>

#define LOGGER_BUFFER_SIZE 50

struct logger_t
{
  // Logger name maximum of 20 characters
  char name[LOGGER_BUFFER_SIZE];
};

// creates the logger if not created otherwise returns the pointer
struct logger_t* get_logger(const unsigned long thread_id);

// prints the log message
int print(const char* log_message);
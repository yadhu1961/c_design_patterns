#include "logger.h"
#include <assert.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// Logger is a singleton object
static struct logger_t* _logger = NULL;
pthread_mutex_t         mutex   = PTHREAD_MUTEX_INITIALIZER;

struct logger_t* get_logger(const unsigned long thread_id)
{
  if (_logger != NULL)
    return _logger;

  // serialize the logger creation
  pthread_mutex_lock(&mutex);   // Lock
  char logger_name[LOGGER_BUFFER_SIZE];
  sprintf(logger_name, "LOG_%ld: ", thread_id);
  printf("thread %ld created logger\n", thread_id);
  static struct logger_t logger;
  strcpy(logger.name, logger_name);
  _logger = &logger;
  pthread_mutex_unlock(&mutex);   // Unlock

  return _logger;
}

int print(const char* log_message)
{
  if (_logger == NULL)
  {
    assert(_logger != NULL);
    return -1;
  }
  // Print the log message
  printf("%s\n", log_message);
  return 0;
}
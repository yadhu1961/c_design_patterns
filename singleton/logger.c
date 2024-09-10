#include "logger.h"
#include <assert.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

struct logger_t
{
  // Logger name maximum of 20 characters
  char name[LOGGER_BUFFER_SIZE];
};

// Logger is a singleton object
static struct logger_t* _logger = NULL;
pthread_mutex_t         mutex   = PTHREAD_MUTEX_INITIALIZER;

int get_logger(const uint8_t thread_id)
{
  // TODO handle the case when error occurs then return -1
  // serialize the logger creation
  pthread_mutex_lock(&mutex);   // Lock
  if (_logger == NULL)
  {
    printf("thread %u created logger\n", thread_id);
    static struct logger_t logger;
    sprintf(logger.name, "LOG_%u: ", thread_id);
    _logger = &logger;
  }
  pthread_mutex_unlock(&mutex);   // Unlock

  return 0;
}

int print(const char* log_message)
{
  if (_logger == NULL)
  {
    assert(_logger != NULL && "Have you instantiated logger?");
    return -1;
  }

  char final_log_message[LOGGER_BUFFER_SIZE + 10];
  sprintf(final_log_message, "%s: %s", _logger->name, log_message);
  // Print the log message
  printf("%s\n", final_log_message);
  return 0;
}
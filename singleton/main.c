#include <limits.h>    // for limits of uint8 type
#include <pthread.h>   // for pthread functionality
#include <stdint.h>    // for uint8_t
#include <stdio.h>     // for printf/snprintf
#include <stdlib.h>    // for srand
#include <unistd.h>    // for sleep
#include "logger.h"

#define LOG(msg, thread_id) \
  {                         \
    get_logger(thread_id);  \
    print(msg);             \
  }

void* thread_func(void* arg)
{
  char    log_message[LOGGER_BUFFER_SIZE];
  uint8_t thread_id = *(uint8_t*)arg;
  // printf("identified thread id %d\n", thread_id);

  {
    // To randomize which thread creates the logger
    uint8_t r = rand() & UCHAR_MAX;   // number ranging from 0 to 255
    usleep(r);
  }

  for (uint8_t count = 0; count < 5; ++count)   // Sleep 10 times for random number of micro seconds
  {
    uint8_t r = rand() & UCHAR_MAX;   // number ranging from 0 to 255
    usleep(r);
    sprintf(log_message, "thread %u, random number %u", thread_id, r);
    LOG(log_message, thread_id);
  }
}

int main()
{
  srand(time(NULL));   // Initialization, should only be called once.

  pthread_t ptid_0;
  pthread_t ptid_1;
  uint8_t   thread_ids[2] = {0, 1};

  // uncommenting this line should cause assertion
  print("test for assertion");

  // Creating a new threads
  pthread_create(&ptid_0, NULL, &thread_func, &thread_ids[0]);
  // Creating a new thread
  pthread_create(&ptid_1, NULL, &thread_func, &thread_ids[1]);
  // printf(
  //     "This line may be printed"
  //     " before thread terminates\n");

  // Waiting for the created thread to terminate
  pthread_join(ptid_0, NULL);
  pthread_join(ptid_1, NULL);

  // printf(
  //     "This line will be printed"
  //     " after thread ends\n");

  pthread_exit(NULL);

  return 0;
}
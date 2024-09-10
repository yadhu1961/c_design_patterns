#include <stdint.h>

#define LOGGER_BUFFER_SIZE 50

/**
 * Logger is implemented as combination of opaque pattern and singleton pattern
 * Logger can be instantiatiated only by one thread at a time. first to call get_logger, creates the logger
 * It cannot be instatiated directly due to opaqueness, caller needs to instantiate using thread safe get_logger API
 */

/**
 * thread safe function to create the logger, if created
 * creates the logger if not created otherwise returns the pointer.
 */
int get_logger(const uint8_t thread_id);

/**
 *  prints the log message returns 0 if successful, -1 if logging failed
 */
int print(const char* log_message);
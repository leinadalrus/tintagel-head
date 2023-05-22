#pragma GCC diagnostic warning "-Wformat"
#pragma GCC diagnostic error "-Wuninitialized"

#ifdef __linux__
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#endif // !__linux__

#ifdef _WIN32
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#endif

#ifndef NDEBUG_TESTASSERT_MESSAGES_H
#define NDEBUG_TESTASSERT_MESSAGES_H

#define DEBUG_CHECK(_str, ...)

#define ASSERT_VARGS(_str)                                                     \
  {                                                                            \
    if (!(_str, ...))                                                          \
      DEBUG_CHECK(#_str, __FILE__, __LINE__);                                  \
  }

#define ASSERT_MESSAGE(sz_message)                                             \
  { printf("%s in %s, line: %d", sz_message, __FILE__, __LINE__); }

#define ASSERT_VERBOSE(sz_message, sz_file, xn_line)                           \
  { printf("%s in %s, line %ld", sz_message, sz_file, xn_line); }

#endif // !NDEBUG_TESTASSERT_MESSAGES_H

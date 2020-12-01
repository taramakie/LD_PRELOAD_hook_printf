#include <stdio.h>
#include <stdarg.h>
#include <dlfcn.h>

typedef int (*ORIGINAL_PRINTF)(const char *__restrict __format, ...);
ORIGINAL_PRINTF orig_printf = NULL;

int printf(const char *__restrict __format, ...)
{
  int ret = 0;

  if(!orig_printf) orig_printf = (ORIGINAL_PRINTF)dlsym(RTLD_NEXT, "printf");
  orig_printf("Called printf func\n");

  va_list args;
  va_start(args, __format);

  ret = vprintf(__format, args);

  va_end(args);

  return ret;
}

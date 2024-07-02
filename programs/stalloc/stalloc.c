#include "stalloc.h"
#include <stdbool.h>
#include <stddef.h>

#define ALLOCBUF_SIZE 8192

static char allocbuf[ALLOCBUF_SIZE];
static char* allocp = allocbuf;

void* stalloc(int nbytes) {
  if (allocp + nbytes >= allocbuf + ALLOCBUF_SIZE)
    return NULL;

  void* result = allocp;
  allocp += nbytes;

  return result;
}

void stfree(void* p) {
  bool is_out_of_bounds =
      (char*)p < allocbuf || (char*)p > (allocbuf + ALLOCBUF_SIZE);

  if (is_out_of_bounds)
    return;

  allocp = p;
}

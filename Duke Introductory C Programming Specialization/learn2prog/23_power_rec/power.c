#include <stdio.h>

unsigned power(unsigned x, unsigned y) {
  if (y <= 0) return 1;
  return x * power(x, y - 1);
}

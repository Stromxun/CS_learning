#include <stddef.h>


int max(int a, int b) {
  return (a > b) ? a : b;
}

size_t maxSeq(int * array, size_t n) {
  int ans = 0;
  int tmp = 0;
  for (int i = 0; i < n; i++) {
    if (i != 0 && array[i - 1] >= array[i]) {
      ans = max(ans, tmp);
      tmp = 1;
    } else {
      tmp += 1;
    }
  }
  return max(ans, tmp);
}

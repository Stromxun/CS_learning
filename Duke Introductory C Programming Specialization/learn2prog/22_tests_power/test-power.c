#include<stdio.h>
#include<stdlib.h>

unsigned power (unsigned x, unsigned y);

void run_check(unsigned x, unsigned y, unsigned expected_ans) {
  unsigned int ans = power(x, y);
  if (ans == expected_ans) {
    return;
  }
  printf("power(x, y) = %d, but expected_ans = %d", ans, expected_ans);
  exit(EXIT_FAILURE);
}

int main() {
  run_check(1, 0, 1);
  run_check(9999, 0, 1);
  run_check(0, 100, 0);
  run_check(0, 0, 1);
  run_check(2, 2, 4);
  run_check(3, 3, 27);
  run_check(100, 4, 100000000);
  run_check(1, 100000, 1);
  run_check(7, 3, 343);
  return EXIT_SUCCESS;
}

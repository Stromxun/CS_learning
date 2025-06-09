#include <stdio.h>
#include <stdlib.h>

void g(int x, int * y) {
  printf("In g, x = %d, *y = %d\n", x, *y);
  x++;
  *y = *y - x;
  y = &x;
}

void f(int * a, int b) {
  printf("In f, *a = %d, b = %d\n", *a, b);
  *a += b;
  b *= 2;
  g(*a, &b);
  printf("Back in f, *a = %d, b = %d\n", *a, b);
}


int main(void) {
  int x = 3;
  int y = 4;
  f(&x, y);
  printf("In main: x = %d, y = %d\n", x, y);
  return EXIT_SUCCESS;
}

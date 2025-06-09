#include <stdio.h>
#include <stdlib.h>

int f(int ** r, int ** s) {
  int temp = ** r;
  int temp2 = **s;
  int * z = *r;
  *r = *s;
  *s = z;
  printf("**r = %d\n",**r);
  printf("**s = %d\n",**s);
  *z += 3;
  **s -= 8;
  **r -= 19;
  return temp + temp2;
}

int main(void) {
  int a = 80;
  int b = 12;
  int * p = &a;
  int * q = &b;
  int x = f(&p, &q);
  printf("x = %d\n", x);
  printf("*p = %d\n", *p);
  printf("*q = %d\n", *q);
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  return EXIT_SUCCESS;
}

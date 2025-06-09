#include <stdio.h>
#include <stdlib.h>

int* aFunction(int x, int *p, int ** q) {
  printf("x = %d\n", x);
  printf("*p = %d\n", *p);
  printf("**q= %d\n", **q);
  *p = 42;
  **q = 99;
  *q = &p[1];
  return &p[2];
}

int main (void) {
  int anArray[3][3] = { {1,2,3},
			{4,5,6},
			{7,8,9} };

  int * p = anArray[1];
  int * q = aFunction(anArray[0][0],
		      anArray[2],
		      &p);
  for (int i =0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d\n", anArray[i][j]);
    }
  }
  printf("*q=%d\n", *q);

  return EXIT_SUCCESS;
}

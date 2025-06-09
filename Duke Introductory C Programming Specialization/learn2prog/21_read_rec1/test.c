#include <stdio.h>
#include <stdlib.h>

void printDigits(int x) {
  if (x == 0) {
    printf("0");
  }
  else if (x < 0) {
    printf("-");
    printDigits(-x);
  }
  else {
    int a = x/10;
    int b = x %10;
    printf("a=%d, b=%d\n",a,b);
    if (a != 0) {
      printDigits(a);
    }
    printf("%d",b);
  }
}


int main(void) {
  printDigits(297);
  printf("\n");
  return EXIT_SUCCESS;
}

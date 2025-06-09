#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

void ERROR(int i) {
  printf("Test %d case error!\n", i);
}

int main() {
  // test 1
  int array1[] = {};
  if (maxSeq(array1, 0) != 0) {
    ERROR(1);
    return EXIT_FAILURE;
  }

  // test 2
  int* array2 = NULL;
  if (maxSeq(array2, 0) != 0) {
    ERROR(2);
    return EXIT_FAILURE;
  }
  
  // test 3
  int array3[6] = {1, 2, 3, 4, 5, 6};
  if (maxSeq(array3, 6) != 6) {
    ERROR(3);
    return EXIT_FAILURE;
  }

  // test 4
  int array4[7] = {1, 2, 3, 4, 2, 6, 9};
  if (maxSeq(array4, 7) != 4) {
    ERROR(4);
    return EXIT_FAILURE;
  }

  // test 5
  int array5[] = {1, 1, 1, 1, 1};
  if (maxSeq(array5, 5) != 1) {
    ERROR(5);
    return EXIT_FAILURE;
  }

  // test 6
  int array6[] = {1, -1, 0, 1, 2, -3, -5, -7, -8, -9};
  if (maxSeq(array6, 10) != 4) {
    ERROR(6);
    return EXIT_FAILURE;
  }

  // test 7
  int array7[] = {5, 4, 3, 2, 1};
  if (maxSeq(array7, 5) != 1) {
    ERROR(7);
    return EXIT_FAILURE;
  }

  int array8[] = {1, 2, 2, 3};
  if (maxSeq(array8, 4) != 2) {
    ERROR(8);
    return EXIT_FAILURE;
  }

  int array9[] = {100000002, 100000003, 100000004, 1, 2};
  if (maxSeq(array9, 5) != 3) {
    ERROR(9);
    return EXIT_FAILURE;
  }

  int array10[] = {-1, -2, -3, 1};
  if (maxSeq(array10, 4) != 2){
    ERROR(10);
    printf("%ld", maxSeq(array10, 10));
    return EXIT_FAILURE;
  }

  
  // passed all test cases
  return EXIT_SUCCESS;
}

#include "outname.h"
#include <stdio.h>
#include <stdlib.h>


#define NUM_TESTS 3
int main(void) {
  char * testNames[NUM_TESTS] = {"input.txt",
				 "anotherTestFileName.txt",
				 "somethingelse"};
  
  for (int i = 0; i < NUM_TESTS; i++) {
    char * outName = computeOutputFileName(testNames[i]);
    printf("'%s' => '%s'\n", testNames[i], outName);
    free(outName);
  }
  return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
  char* outFile = (char *) malloc(sizeof(*outFile) * (strlen(inputName) + 8));
  strcpy(outFile, inputName);
  strcat(outFile, ".counts");
  return outFile;
}

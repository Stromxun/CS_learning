#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME
  counts_t* c = createCounts();
  FILE* p = fopen(filename, "r");
  if (p == NULL) {
    perror("Could not open file");
    return NULL;
  }
  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  while ((read = getline(&line, &len, p)) != -1) {
    int k = strlen(line);
    if (line[k - 1] == '\n') {
        line[k - 1] = '\0';
    }
    char *s = lookupValue(kvPairs, line);
    addCount(c, s);
    free(line);
    line = NULL;
  }
  free(line);
  fclose(p);
  return c;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
  if (argc < 3) {
    perror("Usage: count_values kv*.txt list*.txt (the num of list*.txt better 0)");
    return EXIT_FAILURE;
  }
 //read the key/value pairs from the file named by argv[1] (call the result kv)
  kvarray_t* kv = readKVs(argv[1]);
 //count from 2 to argc (call the number you count i)
  for (int i = 2; i < argc; i++) {
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)
    counts_t* c = countFile(argv[i], kv);
    if (c == NULL) {
        return EXIT_FAILURE;
    }
    //compute the output file name from argv[i] (call this outName)
    char* outputFileName = computeOutputFileName(argv[i]);
    //open the file named by outName (call that f)
    FILE* p = fopen(outputFileName, "w");
    //print the counts from c into the FILE f
    printCounts(c, p);
    //close f
    fclose(p);
    //free the memory for outName and c
    freeCounts(c);
    free(outputFileName);
  }

 //free the memory for kv
  freeKVs(kv);
  return EXIT_SUCCESS;
}

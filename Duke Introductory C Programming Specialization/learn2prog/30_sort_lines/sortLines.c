#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

void print_result(char **data, size_t count) {
  for(int i = 0; i < count; i++) {
    printf("%s", data[i]);
  }
}

void doStandard() {
    char** data = NULL;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int n = 0;
    while ((read = getline(&line, &len, stdin)) != -1) {
        n++;
        char** new = realloc(data, sizeof(*data) * n);
	data = new;
	data[n - 1] = strdup(line);
    }
    sortData(data, n);
    print_result(data, n);
    for (int i = 0; i < n; i++) free(data[i]);
    free(data);
    free(line);
}

void doFileInput(FILE* f) {
    char** data = NULL;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int n = 0;
    while ((read = getline(&line, &len, f)) != -1) {
        n++;
        char** new = realloc(data, sizeof(*data) * n);
	data = new;
	data[n - 1] = strdup(line);
    }
    sortData(data, n);
    print_result(data, n);
    for (int i = 0; i < n; i++) free(data[i]);
    free(data);
    free(line);
}

int main(int argc, char ** argv) {

  //WRITE YOUR CODE HERE!            
  if (argc == 1) {
    doStandard();
  } else {
    // open file                                                                           
    for (int i = 1; i < argc; i++) {
        FILE* f = fopen(argv[i], "r");
	if (f == NULL) {
	  perror("Could not open file");
	  return EXIT_FAILURE;
	} else {
	  doFileInput(f);
	  fclose(f);
	}
    }
  }
  return EXIT_SUCCESS;
}

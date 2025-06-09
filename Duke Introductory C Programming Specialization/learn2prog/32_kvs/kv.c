#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

int first_equal(char* s, int n) { // find the first '=' in string
    for (int i = 0; i < n; i++) {
        if (s[i] == '=') {
            return i;
        }
    }
    return -1;
}

char* substr(char* s, int start, int end) {
    char* ans = (char *) malloc ((end - start + 1) * sizeof(*ans));
    int len = 0;
    for (int i = start; i < end; i++) {
        ans[len++] = s[i];
    }
    ans[end - start] = '\0';
    return ans;
}

void add_kv(kvarray_t* pairs, kvpair_t* kv) {
  int n = pairs->n + 1;
    kvpair_t** new_array = realloc(pairs->array, n * sizeof(*new_array));
    pairs->array = new_array;
    pairs->array[n - 1] = kv;
    pairs->n = n;
}

kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE* p = fopen(fname, "r");
  if (p == NULL) {
    perror("Could not open file");
    return NULL;
  }
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  kvarray_t* pairs = malloc(sizeof(*pairs));
  pairs->n = 0;
  pairs->array = NULL;
  while ((read = getline(&line, &len, p)) != -1) {
    int n = strlen(line);
    if (line[n - 1] == '\n') line[n - 1] = '\0';
    int eq = first_equal(line, n);
    kvpair_t* kv = (kvpair_t*) malloc(sizeof(*kv));
    kv->key = substr(line, 0, eq);
    kv->value = substr(line, eq + 1, n);
    add_kv(pairs, kv);
    free(line);
    line = NULL;
  }
  free(line);
  fclose(p);
  return pairs;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
    int n = pairs->n;
    for (int i = 0; i < n; i++) {
      free(pairs->array[i]->key);
      free(pairs->array[i]->value);
      free(pairs->array[i]);
    }
     free(pairs->array);
    free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  int n = pairs->n;
  for (int i = 0; i < n; i++) {
    printf("key = '%s' value = '%s'\n", pairs->array[i]->key, pairs->array[i]->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  int n = pairs->n;
  for (int i = 0; i < n; i++) {
    if (strcmp(key, pairs->array[i]->key) == 0) {
        return pairs->array[i]->value;
    }
  }
  return NULL;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"

void addNewCount(counts_t* c, const char* name) {
  one_count_t* o = (one_count_t*) malloc(sizeof(*o));
  o->count = (strcmp(name, "<unknown> ") ? 1 : 0);
  int n = strlen(name);
  o->name = (char*) malloc((n + 1) * sizeof(char));
  strcpy(o->name, name);
  c->n += 1;
  one_count_t** tmp = realloc(c->counts, (c->n) * sizeof(*tmp));
  c->counts = tmp;
  c->counts[c->n - 1] = o;
}

counts_t * createCounts(void) {
  //WRITE ME                                                                                                                
  counts_t* counts = (counts_t*) malloc(sizeof(*counts));
  counts->counts = NULL;
  counts->n = 0;
  addNewCount(counts, "<unknown> ");
  return counts;
}

void addCount(counts_t * c, const char * name) {
  //WRITE ME
  if (name == NULL) {
    c->counts[0]->count += 1;
    return;
  }
  int n = c->n;
  for (int i = 0; i < n; i++) {
    if (strcmp(name, c->counts[i]->name) == 0) {
      c->counts[i]->count += 1;
      return;
    }
  }
  addNewCount(c, name);
}
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  int n = c->n;
  for (int i = 1; i < n; i++) {
    fprintf(outFile, "%s: %d\n", c->counts[i]->name, c->counts[i]->count);
  }
  if (c->counts[0]->count)
  fprintf(outFile, "%s: %d\n", c->counts[0]->name, c->counts[0]->count);
}

void freeCounts(counts_t * c) {
  //WRITE ME
  int n = c->n;
  for(int i = 0; i < n; i++) {
    free(c->counts[i]->name);
    free(c->counts[i]);
  }
  free(c->counts);
  free(c);
}

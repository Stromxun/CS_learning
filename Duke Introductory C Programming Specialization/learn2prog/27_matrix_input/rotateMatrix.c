#include <stdio.h>
#include <stdlib.h>

void rotate(char matrix[10][10]) {
    int len = 10;
    for (int i = 0; i < (len + 1) / 2; i++) {
        for (int j = i; j < len - i - 1; j++) {
        // rotate
        char tmp = matrix[j][i]; // lt                                                    
        matrix[j][i] = matrix[len - i - 1][j]; // ld                                      
        matrix[len - i - 1][j] = matrix[len - j - 1][len - i - 1]; // rd     
        matrix[len - j - 1][len - i - 1] = matrix[i][len - j - 1]; // rt                  
        matrix[i][len - j - 1] = tmp; // finish
        }
    }
}

void init(char matrix[10][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      matrix[i][j]  = ' ';
    }
  }
}


int main(int args, char** argv) {
  if (args != 2) {
    fprintf(stderr,"Usage: rotateMatrix inputFileName\n");    
    return EXIT_FAILURE;
  }
  FILE* f = fopen(argv[1], "r");
    if (f == NULL) {
        fprintf(stderr,"Can't open the file\n");
        return EXIT_FAILURE;
    }
    char matrix[10][10];
    init(matrix);
    int c, index = 0;
    while((c = fgetc(f)) != EOF) {
      if ((char) c == '\n') {
	if (index % 10 != 0) {
	  fprintf(stderr,"Is short-line or long-line\n");
            return EXIT_FAILURE;
	}
	continue;
      }
      if (index > 100) {
	fprintf(stderr,"Is Long File\n");
        return EXIT_FAILURE;
      }
      
      int x = index / 10, y = index % 10;
      matrix[x][y] = (char) c;
      index++;
    }
    if (index < 100) {
      fprintf(stderr,"Not have 100 chars\n");
      return EXIT_FAILURE;
    }
    rotate(matrix);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
    fclose(f);
    return EXIT_SUCCESS;
}

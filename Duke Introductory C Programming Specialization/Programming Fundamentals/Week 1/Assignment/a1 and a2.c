#include <stdio.h>

char grid[10][10];

// red: '*', blue: '$', green: '#', white: ' '

int main() {
    // init grid
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j] = ' ';
        }
    }

    // main body of Algorithm
    int N;
    scanf("%d", &N);
    
    // red block
    for (int i = 0; i <= N; i++) {
        grid[i][N - i] = '*';
    }

    char base = (N & 1 ? '$' : '#');

    // blue and green block
    for (int i = 0; i <= N + 1; i++) {
        grid[i][N - i + 1] = base;
        
        if (base == '#') {
            base = '$'; // blue
        } else {
            base = '#'; // green
        }
    }

    // print grid
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < 10; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}
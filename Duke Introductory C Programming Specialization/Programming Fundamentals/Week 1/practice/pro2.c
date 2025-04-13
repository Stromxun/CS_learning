#include <stdio.h>

char grid[10][10];

// red: '*', blue: '$', green: '#', white: ' '

int main() {

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j] = ' ';
        }
    }

    int N;
    scanf("%d", &N);
    for (int i = 0; i <= N; i++) {
        for (int j = i; j < i + 2; j++) {
            grid[j][i] = '*';
        }
    }

    if (N & 1) { 
        grid[N + 2][N + 2] = grid[N][N + 2] = '$';
    } else {
        grid[N + 1][N + 1] = '#';
    }

    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < 10; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N * 2; i++) {
        int num = i;
        if (i < N) {
            num = num * 2;
        }
        printf("%d ", num);
    }
    return 0;
}
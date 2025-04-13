#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int base = N * 3;
    for (int i = 0; i < (N + 1) * 2; i++) {
        printf("%d ", base);
        base += 2;
    }
    return 0;
}
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int n = 3 * N;
    int base = -1 * N * N;
    for (int i = 0; i < n; i++) {
        printf("%d ", base);
        base += i * 2 + 1;
    }
    return 0;
}
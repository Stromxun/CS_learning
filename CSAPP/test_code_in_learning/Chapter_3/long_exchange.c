#include<stdio.h>

long exchange(long *xp, long y){
    long x = *xp;
    *xp = y;
    return x;
}

int main(){
    long a = 4;
    long b = exchange(&a, 3);
    printf("a = %ld, b = %ld\n", a, b);
    return 0;
}
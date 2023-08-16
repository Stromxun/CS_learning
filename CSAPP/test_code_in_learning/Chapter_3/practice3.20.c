#include<stdio.h>

#define OP /

long arith(long x){
    return x OP 8 ;
}

int main(){
    int x = 2;
    printf("%ld\n", arith(x));
    return 0;
}

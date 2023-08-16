#include<stdio.h>

long shift_left4_rightn(long x, long n){
    x <<= 4;
    x >>= n;
    return x;
}
int main(){
    int i = 0xffffff73;
    printf("%x\n", 0x4005ed + i);
    return 0;
}
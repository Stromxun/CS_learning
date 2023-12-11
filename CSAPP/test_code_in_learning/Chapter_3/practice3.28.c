#include<stdio.h>

long fun_b(unsigned long x){
    long val = 0;
    long i;
    for( i = 64 ; i != 0 ; i-- ){
        val = (val << 1) | (x & 1);
        x >>= 1;
    }
    return val;
}
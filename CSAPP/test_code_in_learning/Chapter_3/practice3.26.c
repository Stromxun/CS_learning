#include<stdio.h>

long fun_a(unsigned long x){
    long val = 0;
    while (x > 0) {
        val ^= x;
        x >>= 1;
    }
    val &= 1;
    return val;
}
#include<stdio.h>

long lt_cnt = 0;
long ge_cnt = 0;

long absdiff_se(long x, long y){
    long t = x < y, result = 0;
    if(t)
        goto True;
    ge_cnt++;
    result = x - y;
    goto Done;
True:
    result = y - x;
    lt_cnt++;
Done:
    return result;
}
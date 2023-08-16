#include<stdio.h>

void cond(long a, long *p){
    if(!p || a <= *p)
        goto lable1;
    *p = a;

lable1:
    return ;
}
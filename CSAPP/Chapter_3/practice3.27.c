#include<stdio.h>

long fact_for(long n){
    long i = 2;
    long result = 1;
    if (i > n )
        goto label2;
label1:        
    result *= i;
    i++;
    if( i<= n)
        goto label1;
label2:
    return result;
}

#include<stdio.h>

typedef long type;

int main(){
    type k = 1,result = 1;
    do{
        if (result > result * k)
            break;
        result *= k;
        printf("%ld\n", result);
        k++;
    }while(result >= 0);

    return 0;
}
#include<stdio.h>

int main(){
    int sum = 0;
    long i = 0;
    while(i < 10){
        if(i & 1)
            goto update;
        sum += i;
    update:
        i++;
    }
    return 0;
}
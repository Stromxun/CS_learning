#include<stdio.h>

typedef char src_t;
typedef short dest_t;

void test(src_t *sp, dest_t *dp){
    *dp = (dest_t) *sp;
}

int main(){
    int c = 0xffffffff;
    char l = c;
    printf("%d",l);
}
#include<stdio.h>

struct ELE
{
    /* data */
    long v;
    struct ELE *p;
};

long fun(struct ELE *ptr){
    long result = 0;
    while(ptr){
        result = result + (ptr->v);
        ptr = ptr ->p ;
    }
}

int main(){

    return 0;
}
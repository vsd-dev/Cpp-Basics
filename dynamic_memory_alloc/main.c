#include <stdlib.h>


int main(){
    int a; // goes on stack
    int *p;//Defines pointer
    p = (int*) malloc(sizeof(int));
    *p = 10;
    return 0;
}
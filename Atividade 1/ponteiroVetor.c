#include<stdio.h>

int main(){
    int vet[] = {1,2,3,4,5};
    int *p = vet;
    printf("p: %d\n", *p);

    p+=2;

    printf("p após ++: %d\n", *p);
    return 0;
}
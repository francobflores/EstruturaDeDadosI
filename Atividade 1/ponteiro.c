#include<stdio.h>

int main(){
int x = 10;

int *p = &x;

*p++;
*p--;

printf("p: %d\n", *p);

return 0;
}
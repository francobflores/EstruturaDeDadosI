#include<stdio.h>
#include<stdlib.h>

 int main ( ) {
    int num = 10;
    
    int *p;
    //ponteiro apontando para o endereço de memoria da variavel num
    p = &num;
    
    int num2;
    //acessando valor armazenado na posição da memoria apontada.
    num2 = *p;

    printf("num: %d\np: %d\nnum2: %d\n",num, *p, num2);
 return 0 ;
 }
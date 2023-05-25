#include<stdio.h>
#include<stdlib.h>

typedef struct no {
    int valor;
    struct no prox;
}No;

No *criaNo(int valor){
    No *novo = (No*)malloc(sizeof(No*));
    if(novo == NULL){
        printf("Erro de Alocação de Memória\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

void insereInicio(No *L, int valor){
    No *novo = criaNo(valor);
    novo->prox = L->prox;
    L->prox = novo;
}

void imprimir(No *L){
    No *aux = L->prox;
    while(aux != NULL){
        printf("[%d] ", aux->valor);
        aux = aux->prox;
    }printf("\n\n");
}


int main(){
    
    No *L = NULL;
    insereInicio(4);
    insereInicio(2);
    insereInicio(5);

    imprimir(L);

    return 0;
}
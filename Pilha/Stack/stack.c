#include "stack.h"

void iniciaPilha(Pilha *P)
{
    P->topo = NULL;
}

int verificaVazia(Pilha *P)
{
    return P->topo == NULL;
}

void empilhar(Pilha *P, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    
    if(novo == NULL)
    {
        printf("Erro de alocação de memória!\n ");
        exit(1);
    }
    
    novo->chave = valor;
    novo->prox = P->topo;
    P->topo  = novo; 

}

void imprime(Pilha *P)
{
    No *aux = P->topo;
    while(aux != NULL)
    {
        printf("[ %d ] ",aux->chave);
        aux= aux->prox;
    }
    printf("\n");
}
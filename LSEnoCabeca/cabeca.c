#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int chave;
    struct no *prox;
}No;

No *novaLista(){
    No *novo = (No*)calloc(1,sizeof(No));
    if(novo == NULL){
        printf("Erro de Alocação de Memória!\n");
        exit(1);
    }
    return novo;
}

No *criaNo(int valor){
    No *novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro de Alocação de Memória!\n");
        exit(1);
    }
    novo->chave = valor;
    novo->prox = NULL;

    return novo;
}

void insereInicio(No *L, int valor){
    No *novo = criaNo(valor);
    novo->prox = L->prox;
    L->prox = novo;
}

void insereFinal(No *L, int valor){
    No *novo = criaNo(valor);
    No *aux = L;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
}

void imprime(No *L){
    No *aux = L->prox;
    if(L->prox == NULL){
        printf("Lista Vazia!\n");
    }
    while(aux != NULL){
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}

int main(){
    No *Lista;

    Lista  = novaLista();

    insereFinal(Lista, 2);
    insereFinal(Lista, 2);
    insereFinal(Lista, 2);
    insereFinal(Lista, 2);
    insereFinal(Lista, 2);
    insereFinal(Lista, 2);

    imprime(Lista);

}
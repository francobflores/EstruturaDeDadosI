#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No* prox;
} No;

typedef struct {
    No* topo;
} Pilha;

void iniciaPilha(Pilha* P) {
    P->topo = NULL;
}

int verificaVazia(Pilha* P) {
    return P->topo == NULL;
}

void empilhar(Pilha* P, int valor) {
    No* novo = (No*)malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    novo->chave = valor;
    novo->prox = P->topo;
    P->topo = novo;
}

int desempilhar(Pilha* P) {
    if (verificaVazia(P)) {
        printf("Erro: a pilha está vazia!\n");
        exit(1);
    }

    No* temp = P->topo;
    int valor = temp->chave;
    P->topo = temp->prox;
    free(temp);

    return valor;
}

void imprime(Pilha* P) {
    No* aux = P->topo;
    while (aux != NULL) {
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}

int main() {
    Pilha pilha;
    iniciaPilha(&pilha);

    empilhar(&pilha, 10);
    empilhar(&pilha, 20);
    empilhar(&pilha, 30);

    printf("Elementos na pilha: ");
    imprime(&pilha);

    int elemento = desempilhar(&pilha);
    printf("Elemento desempilhado: %d\n", elemento);

    printf("Elementos restantes na pilha: ");
    imprime(&pilha);

    return 0;
}
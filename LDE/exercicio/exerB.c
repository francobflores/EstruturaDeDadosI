#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista duplamente encadeada
typedef struct no {
    int chave;
    struct no *ant, *prox;
} No;

// Função para criar um novo nó
No *criaNo(int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de Alocação de Memória!");
        exit(1);
    }
    novo->chave = valor;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

// Função para inserir um novo nó no final da lista
No *insereFinal(No *L, int valor) {
    No *novo = criaNo(valor);
    if (L == NULL) {
        L = novo;
    } else {
        No *aux = L;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
        novo->ant = aux;
    }
    return L;
}

// Função para imprimir a lista
void imprime(No *L) {
    if (L == NULL) {
        printf("Lista Vazia!\n");
    } else {
        No *aux = L;
        while (aux != NULL) {
            printf("[ %d ]", aux->chave);
            aux = aux->prox;
        }
        printf("\n");
    }
}

// Função para fundir duas listas ordenadas em uma única lista ordenada
No *fusaoListas(No *L1, No *L2) {
    if (L1 == NULL) {
        return L2;
    } else if (L2 == NULL) {
        return L1;
    } else {
        No *listaFusionada = NULL; // Lista fundida
        No *fim = NULL; // Ponteiro para o último nó da lista fundida

        // Comparando os primeiros nós das duas listas
        if (L1->chave < L2->chave) {
            listaFusionada = L1;
            fim = L1;
            L1 = L1->prox;
        } else {
            listaFusionada = L2;
            fim = L2;
            L2 = L2->prox;
        }

        // Percorrendo as duas listas e fundindo-as
        while (L1 != NULL && L2 != NULL) {
            if (L1->chave < L2->chave) {
                fim->prox = L1;
                L1->ant = fim;
                fim = L1;
                L1 = L1->prox;
            } else {
                fim->prox = L2;
                L2->ant = fim;
                fim = L2;
                L2 = L2->prox;
            }
        }

        // Anexando os nós restantes, se houver, à lista fundida
        if (L1 != NULL) {
            fim->prox = L1;
            L1->ant = fim;
        } else if (L2 != NULL) {
            fim->prox = L2;
            L2->ant = fim;
        }

        return listaFusionada; // Retorna a lista fundida
    }
}

int main() {
    No *L1 = NULL;
    No *L2 = NULL;

    // Inserindo elementos na L1
    L1 = insereFinal(L1, 2);
    L1 = insereFinal(L1, 4);
    L1 = insereFinal(L1, 6);

    // Inserindo elementos na L2
    L2 = insereFinal(L2, 1);
    L2 = insereFinal(L2, 3);
    L2 = insereFinal(L2, 5);

    printf("Lista L1: ");
    imprime(L1);

    printf("Lista L2: ");
    imprime(L2);

    // Realizando a fusão das listas
    No *listaFusionada = fusaoListas(L1, L2);

    printf("Lista Fusionada: ");
    imprime(listaFusionada);

    return 0;
}

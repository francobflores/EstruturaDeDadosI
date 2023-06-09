#include "LSE.h"
/*#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;
*/

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

No* criarLista() {
    return NULL;
}

// Função para inserir um elemento no início da lista
No* insereInicio(No* L, int valor) {
    No* novo = criarNo(valor);
    novo->prox = L;
    return novo;
}

// Função para inserir um elemento no final da lista
No* insereFinal(No* L, int valor) {
    No* novo = criarNo(valor);

    if (L == NULL) {
        return novo;
    }

    No* aux = L;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = novo;
    return L;
}

// Função para excluir o nó do início da lista
No* excluiInicio(No* L) {
    if (L == NULL) {
        printf("Lista vazia.\n");
        return NULL;
    }

    No* aux = L->prox;
    free(L);
    return aux;
}

// Função para excluir o nó do final da lista
No* excluiFinal(No* L) {
    if (L == NULL) {
        printf("Lista vazia.\n");
        return NULL;
    }

    if (L->prox == NULL) {
        free(L);
        return NULL;
    }

    No* aux = L;
    No* pred = NULL;

    while (aux->prox != NULL) {
        pred = aux;
        aux = aux->prox;
    }

    free(aux);

    if (pred != NULL) {
        pred->prox = NULL;
        return L;
    } else {
        return NULL;
    }
}

No *buscaOrdenada(No* L, int valor, No** pred) {
    No* aux = L;
    *pred = NULL;

    while (aux != NULL && aux->valor < valor) {
        *pred = aux;
        aux = aux->prox;
    }

    if (aux != NULL && aux->valor == valor) {
        return aux;
    } else {
        return NULL;
    }
}

No* insereOrdenado(No* L, int valor) {
    No* novo = criarNo(valor);
    if (novo == NULL) {
        return L;
    }

    No* pred;
    No* encontrado = buscaOrdenada(L, valor, &pred);
    if (encontrado != NULL) {
        // Elemento já existe na lista, inserção não é necessária
        free(novo);
        return L;
    }

    if (pred == NULL) {
        // Inserção no início da lista
        novo->prox = L;
        return novo;
    }

    // Inserção no meio da lista
    novo->prox = pred->prox;
    pred->prox = novo;

    return L;
}

No* excluiOrdenado(No* L, int valor) {
    No* pred;
    No* encontrado = buscaOrdenada(L, valor, &pred);
    if (encontrado == NULL) {
        // Elemento não encontrado na lista
        return L;
    }

    if (pred == NULL) {
        // Elemento encontrado é o primeiro da lista
        L = encontrado->prox;
    } else {
        // Elemento encontrado está no meio ou no final da lista
        pred->prox = encontrado->prox;
    }

    free(encontrado);
    return L;
}



// Função para imprimir os elementos da lista
void imprimeLista(No* L) {
    No* aux = L;

    if (aux == NULL) {
        printf("Lista vazia.\n");
    } else {
        printf("Elementos da lista: ");

        while (aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }

        printf("\n");
    }
}

No* concatenaListas(No* L1, No* L2) {
    if (L1 == NULL) {
        return L2;
    }

    No* aux = L1;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = L2;

    return L1;
}

No* mesclaListas(No* L1, No* L2) {
    // Verifica se alguma das listas é vazia
    if (L1 == NULL) {
        return L2;
    }

    if (L2 == NULL) {
        return L1;
    }

    No* merge = NULL;

    // Define o primeiro nó da lista mesclada
    if (L1->valor <= L2->valor) {
        merge = L1;
        L1 = L1->prox;
    } else {
        merge = L2;
        L2 = L2->prox;
    }

    No* aux = merge;

    // Percorre as duas listas, comparando e mesclando os nós
    while (L1 != NULL && L2 != NULL) {
        if (L1->valor <= L2->valor) {
            aux->prox = L1;
            L1 = L1->prox;
        } else {
            aux->prox = L2;
            L2 = L2->prox;
        }
        aux = aux->prox;
    }

    // Verifica se ainda restam nós na lista L1 ou L2
    if (L1 != NULL) {
        aux->prox = L1;
    } else if (L2 != NULL) {
        aux->prox = L2;
    }

    return merge;
}




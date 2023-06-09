#include<stdio.h>
#include<stdlib.h>

/*Estruturas*/

/*Estrutura de nó para Lista Simplismente Encadeada*/

typedef struct no{
    int chave;
    struct no *prox;
} No;

/*Estrutura para Pilha*/

typedef struct pilha{
    No *topo;
}Pilha;

/* Função que inicializa uma Pilha */
/* Parametros: tipo Pilha */

void iniciaPilha(Pilha *P);

/* Função que verifica se uma Pilha está vazia*/
/* Parametros: tipo Pilha */
int verificaVazia(Pilha *P);

/* Função para empilhar novo item na Pilha */
/* Parametros: tipo Pilha, inteiro  valor */

void empilhar(Pilha *P, int valor);

void imprime(Pilha *P);
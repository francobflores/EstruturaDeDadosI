#ifndef __LSE_H__
#define __LSE_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

/* 
 * Função para criar um novo nó em uma lista encadeada.
 * 
 * Parâmetros:
 *   - valor: o valor a ser atribuído ao novo nó.
 * 
 * Retorna:
 *   - O ponteiro para o novo nó criado.
 * 
 * Observação:
 *   - É necessário definir a estrutura 'No' antes de utilizar esta função.
 *   - É importante liberar a memória alocada quando o nó não for mais necessário.
 */
No* criarNo(int valor);

/* 
 * Função para criar uma lista encadeada vazia.
 * 
 * Retorna:
 *   - O ponteiro para a lista encadeada vazia (NULL).
 * 
 * Observação:
 *   - A lista encadeada é representada pelo ponteiro para o primeiro nó.
 */
No* criarLista(); 

/* 
 * Função para inserir um novo nó no início da lista encadeada.
 * 
 * Parâmetros:
 *   - L: ponteiro para o primeiro nó da lista.
 *   - valor: o valor a ser atribuído ao novo nó.
 * 
 * Retorna:
 *   - O ponteiro para o novo primeiro nó da lista.
 * 
 * Observação:
 *   - É necessário definir a estrutura 'No' antes de utilizar esta função.
 *   - A função 'criarNo' é utilizada para criar o novo nó.
 *   - Caso a alocação de memória falhe na função 'criarNo', o programa é encerrado.
 */
No* insereInicio(No* L, int valor) ;

/* 
 * Função para inserir um novo nó no final da lista encadeada.
 * 
 * Parâmetros:
 *   - L: ponteiro para o primeiro nó da lista.
 *   - valor: o valor a ser atribuído ao novo nó.
 * 
 * Retorna:
 *   - O ponteiro para o primeiro nó da lista (pode ter sido modificado).
 * 
 * Observação:
 *   - É necessário definir a estrutura 'No' antes de utilizar esta função.
 *   - A função 'criarNo' é utilizada para criar o novo nó.
 *   - Caso a alocação de memória falhe na função 'criarNo', o programa é encerrado.
 */
No* insereFinal(No* L, int valor);

/* 
 * Função para excluir o primeiro nó de uma lista encadeada.
 * 
 * Parâmetros:
 *   - L: ponteiro para o primeiro nó da lista.
 * 
 * Retorna:
 *   - O ponteiro para o novo primeiro nó da lista (pode ser NULL se a lista ficar vazia).
 * 
 * Observação:
 *   - É necessário definir a estrutura 'No' antes de utilizar esta função.
 *   - A função assume que a memória do primeiro nó será liberada corretamente fora da função.
 */
No* excluiInicio(No* L);

/* 
 * Função para excluir o último nó de uma lista encadeada.
 * 
 * Parâmetros:
 *   - L: ponteiro para o primeiro nó da lista.
 * 
 * Retorna:
 *   - O ponteiro para o primeiro nó da lista (pode ter sido modificado).
 * 
 * Observação:
 *   - É necessário definir a estrutura 'No' antes de utilizar esta função.
 *   - A função assume que a memória do último nó será liberada corretamente fora da função.
 */
No* excluiFinal(No* L);

#endif // __LSE_H__
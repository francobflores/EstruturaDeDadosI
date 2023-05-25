#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int chave;
    struct no *ant, *prox;
}No;

No *criaNo(int valor){
    No *novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro de Alocação de Memória!");
        exit(1);
    }
    novo->chave = valor;
    novo->ant = NULL;
    novo->prox = NULL;
}

No *insereInicio(No *L, int valor){
    No *novo = criaNo(valor);
    novo->prox = L;
    if(L != NULL){
        L->ant = novo;
        L=novo;
    return L;
    }
}

No *insereFinal(No *L, int valor){
    No *novo = criaNo(valor);
    if(L == NULL){
        L= novo;
        return L;
    }
    No *aux = L;
    while(aux->prox != NULL)
        aux = aux->prox;
    aux->prox = novo;
    novo->ant = aux;
    return L;
}

No* busca(No* L, int ch) {
    No* aux = L;
    while (aux != NULL && ch != aux->chave) {
        if (aux->prox == NULL)
            break;
        aux = aux->prox;
    }
    return aux;
}

No* buscaOrdenada(No* L, int ch) {
    No* aux = L;
    while (aux != NULL && ch > aux->chave) {
        if (aux->prox == NULL)
            break;
        aux = aux->prox;
    }
    return aux;
}

No *insereOrdenado(No *L, int chave){
    No *novo = criaNo(chave);
    No *aux = buscaOrdenada(L,chave);
    if(aux == NULL)
    L = novo;
    else{
        if(aux->chave < chave){
            aux->prox = novo;
            novo->ant = aux;
        }else{
            novo->prox = aux;
            if(aux->ant == NULL)
            L = novo;
            else{
                aux->ant->prox = novo;
                novo->ant = aux->ant;
            }
            aux->ant = novo;
        }
    }
    return L;
}

No *excluiInicio(No *L) {
    No *aux = L;
    if (L == NULL)
        return NULL;
    L = aux->prox;
    if (L != NULL)
        L->ant = NULL;
    free(aux);
    return L;
}

No *excluiFinal(No *L) {
    No *aux = L;
    if (L == NULL)
        return NULL;
    while (aux->prox != NULL)
        aux = aux->prox;
    if (aux->ant == NULL)
        L = NULL;
    else
        aux->ant->prox = NULL;
    free(aux);
    return L;
}
No *excluiChave(No *L, int ch) {
    No *aux = busca(L, ch);
    if (aux == NULL || aux->chave != ch) {
        printf("Chave inexistente.\n");
    } else {
        if (aux != NULL) {
            if (aux->ant == NULL) {
                L = aux->prox;
            } else {
                aux->ant->prox = aux->prox;
            }
            if (aux->prox != NULL) {
                aux->prox->ant = aux->ant;
            }
            free(aux);
        }
    }
    return L;
}
void imprime(No *L){
    if(L==NULL){
        printf("Lista Vazia!\n");
    }else{
        No *aux = L;
        while(aux != NULL){
            printf("[ %d ]",aux->chave);
            aux= aux->prox;
        }
        printf("\n");
    }
}

No *removeIesimo(No *L, int i){
    No *aux = L;
    int contador = 0;
    if(L == NULL){
        return NULL;
    }
    while (aux != NULL && contador != i){
        aux = aux->prox;
        contador++;
    }
    if(aux != NULL)
    L = excluiChave(L, aux->chave);
    else
        printf("Indice Iválide\n");
    return L;

}

int main() {
    No* lista = NULL;
    int opcao, chave;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir no início\n");
        printf("2. Inserir no final\n");
        printf("3. Inserir ordenado\n");
        printf("4. Imprimir lista\n");
        printf("5. Exclui no Inicio\n");
        printf("6. Excluir no Final\n");
        printf("7. Excluir Chave\n");
        printf("8. Remover Iesimo\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a chave a ser inserida no início: ");
                scanf("%d", &chave);
                lista = insereInicio(lista, chave);
                break;
            case 2:
                printf("Digite a chave a ser inserida no final: ");
                scanf("%d", &chave);
                lista = insereFinal(lista, chave);
                break;
            case 3:
                printf("Digite a chave a ser inserida ordenadamente: ");
                scanf("%d", &chave);
                lista = insereOrdenado(lista, chave);
                break;
            case 4:
                printf("Lista atual: ");
                imprime(lista);
                break;
            case 5:
                lista = excluiInicio(lista);
                break;
            case 6:
                lista = excluiFinal(lista);
                break;
            case 7:
                printf("Digite a Chave que deseja excluir:\n");
                scanf("%d", &chave);
                lista = excluiChave(lista, chave);
                break;
            case 8:
                printf("Digite o iesimo termo que deseja excluir:\n");
                int i;
                scanf("%d", &i);
                lista = removeIesimo(lista, i);
                break;

            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
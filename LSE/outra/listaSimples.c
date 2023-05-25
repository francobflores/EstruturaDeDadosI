#include<stdio.h>
#include<stdlib.h>

//estrutura de um nó de lista simplismente encadeada.
struct no {
    int chave;
    struct no *prox;
};

//função que cria um nó
struct no *criaNo(int valor){
    struct no *novo;
    novo = (struct no *)malloc(sizeof(struct no));
    if(novo == NULL){
        printf("ERRO: problemas com alocação de memória");
        exit(1);
    }
    novo->chave = valor;
    novo->prox = NULL;
    return novo;
}

//função que insere um nó no inicio da lista 

struct no *insereInicio(struct no *L, int valor){
    struct no *novo = criaNo(valor);
    novo->prox = L;
    L = novo;
    return L;
}

//função que isere um nó no final da lista

struct no *insereFinal(struct no *L, int valor){
    struct no *novo = criaNo(valor);
    struct no *aux = L;
    if(L == NULL) L = novo;
    else{
        while(aux->prox != NULL)
        aux = aux->prox;

        aux->prox = novo;
    }
    return L;
}

//Buca uma chave na Lista Simplismente Endadeada

struct no *buscaChave(struct no *L, int chave){
    struct no *aux = L;
    if( L == NULL ) return NULL;
    else{
        while( aux != NULL){
            if(aux->chave == chave) break;
            aux = aux->prox;
        }
        return aux;
    }

}

//função para imprimir uma lista
void imprimeLista( struct no *L){
    struct no *aux = L;
    while( aux != NULL){
        printf("[%d] ", aux->chave);
        aux =aux->prox;
    }
    printf("\n");
}

//Buca uma chave na Lista Ordenada Simplismente Endadeada

struct no *buscaOrd(struct no *L, int chave){
    struct no *aux = L;
    if( L == NULL ) return NULL;
    else{
        while( aux != NULL){
            if(aux->chave >= chave) break;
            aux = aux->prox;
        }
        return aux;
    }

}

//Inserção em uma lista Ordenada

struct no *insereOrd(struct no *L, int valor){
    struct no *novo = criaNo(valor);
    struct no *aux = L;
    struct no *pred = NULL;
    if( L == NULL ) L = novo;
    else{
        while(aux != NULL && aux->chave < valor){
            pred = aux;
            aux = aux->prox;
        }
        if(pred == NULL){
            novo->prox = aux;
            L = novo;
        }
        else{
            novo->prox =aux;
            pred->prox = novo;
        }
    }
    return L;

}

// função que exclui o primeiro nó da lista
struct no *excluiPrimeiro(struct no *L){
    struct no *aux = L;
    if(L == NULL)return NULL;
    else{
        L= L->prox;
        free(aux);
        return L;   
    }    
}

//Exclusão do último da Lista

struct no *excluiUltimo(struct no *L){
    struct no *aux = L;
    struct no *pred = NULL;
    if(L ==NULL)return NULL;
    else{
        while(aux->prox != NULL){
            pred = aux;
            aux = aux->prox;
        }
        if(pred == NULL)L= NULL;
        else pred->prox = NULL;
        free (aux);
        return L;
    }
}

//Exclusão de uma chave na Lista

struct no *excluiChave(struct no *L, int valor){
    struct no *aux = L;
    struct no *pred = NULL;
    if( L== NULL)return NULL;
    else{
        while (aux != NULL && aux->chave != valor ){
            pred = aux;
            aux = aux->prox;
        }
        if(pred == NULL)L= aux->prox;
        else pred->prox = aux->prox;
        free (aux);
        return L;
    }

}

// Merge de duas Listas
struct no *mesclarListas(struct no* L1, struct no *L2) {
    // Verificar se alguma das listas é vazia
    if (L1 == NULL) {
        return L2;
    }
    if (L2 == NULL) {
        return L1;
    }

    // Cabeça da lista mesclada
    struct no *L1ML2;

    // Escolher o nó inicial
    if (L1->chave <= L2->chave) {
        L1ML2 = L1;
        L1 = L1->prox;
    } else {
        L1ML2 = L2;
        L2 = L2->prox;
    }

    // Nó auxiliar para percorrer a lista mesclada
    struct no *aux = L1ML2;

    // Mesclar as listas até que uma delas seja totalmente percorrida
    while (L1 != NULL && L2 != NULL) {
        if (L1->chave <= L2->chave) {
            aux->prox = L1;
            L1 = L1->prox;
        } else {
            aux->prox = L2;
            L2 = L2->prox;
        }
        aux = aux->prox;
    }

    // Anexar os elementos restantes da L1, se houver
    if (L1 != NULL) {
        aux->prox = L1;
    }

    // Anexar os elementos restantes da L2, se houver
    if (L2 != NULL) {
        aux->prox = L2;
    }

    return L1ML2;
}


//função principal
int main(){
    struct no *L = NULL;
    
    int opcao, valor;

    do {
        printf("Menu:\n");
        printf("1 - Inserir no início\n");
        printf("2 - Inserir no final\n");
        printf("3 - Imprimir lista\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
                switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido no início: ");
                scanf("%d", &valor);
                L = insereInicio(L, valor);
                break;
            case 2:
                printf("Digite o valor a ser inserido no final: ");
                scanf("%d", &valor);
                L = insereFinal(L, valor);
                break;
            case 3:
                imprimeLista(L);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
                break;
        }
        printf("\n");
    } while (opcao != 0);


    return 0;
}
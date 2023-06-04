#include "LSE.h"
int main() {
    No* lista1 = NULL;
    No* lista2 = NULL;
    int opcao, valor, listaSelecionada;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Inserir elemento no início da lista\n");
        printf("2. Inserir elemento no final da lista\n");
        printf("3. Excluir elemento do início da lista\n");
        printf("4. Excluir elemento do final da lista\n");
        printf("5. Inserir elemento ordenadamente na lista\n");
        printf("6. Excluir elemento ordenado da lista\n");
        printf("7. Mesclar duas listas\n");
        printf("8. Imprimir lista\n");
        printf("9. Encerrar o programa\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Digite a lista desejada (1 ou 2): ");
                scanf("%d", &listaSelecionada);
                if (listaSelecionada == 1) {
                    lista1 = insereInicio(lista1, valor);
                } else if (listaSelecionada == 2) {
                    lista2 = insereInicio(lista2, valor);
                } else {
                    printf("Lista inválida.\n");
                }
                break;
            case 2:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Digite a lista desejada (1 ou 2): ");
                scanf("%d", &listaSelecionada);
                if (listaSelecionada == 1) {
                    lista1 = insereFinal(lista1, valor);
                } else if (listaSelecionada == 2) {
                    lista2 = insereFinal(lista2, valor);
                } else {
                    printf("Lista inválida.\n");
                }
                break;
            case 3:
                printf("Digite a lista desejada (1 ou 2): ");
                scanf("%d", &listaSelecionada);
                if (listaSelecionada == 1) {
                    lista1 = excluiInicio(lista1);
                } else if (listaSelecionada == 2) {
                    lista2 = excluiInicio(lista2);
                } else {
                    printf("Lista inválida.\n");
                }
                break;
            case 4:
                printf("Digite a lista desejada (1 ou 2): ");
                scanf("%d", &listaSelecionada);
                if (listaSelecionada == 1) {
                    lista1 = excluiFinal(lista1);
                } else if (listaSelecionada == 2) {
                    lista2 = excluiFinal(lista2);
                } else {
                    printf("Lista inválida.\n");
                }
                break;
            case 5:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Digite a lista desejada (1 ou 2): ");
                scanf("%d", &listaSelecionada);
                if (listaSelecionada == 1) {
                    lista1 = insereOrdenado(lista1, valor);
                } else if (listaSelecionada == 2) {
                    lista2 = insereOrdenado(lista2, valor);
                } else {
                    printf("Lista inválida.\n");
                }
                break;
            case 6:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                printf("Digite a lista desejada (1 ou 2): ");
                scanf("%d", &listaSelecionada);
                if (listaSelecionada == 1) {
                    lista1 = excluiOrdenado(lista1, valor);
                } else if (listaSelecionada == 2) {
                    lista2 = excluiOrdenado(lista2, valor);
                } else {
                    printf("Lista inválida.\n");
                }
                break;
            case 7:
                lista1 = mesclaListas(lista1, lista2);
                printf("As listas foram mescladas.\n");
                break;
            case 8:
                printf("Lista 1: ");
                imprimeLista(lista1);
                printf("\n");
                printf("Lista 2: ");
                imprimeLista(lista2);
                printf("\n");
                break;
            case 9:
                printf("Encerrando o programa...\n");
                return 0;
            
            default:
                printf("Opção inválida. Digite novamente.\n");
        }
    }
}
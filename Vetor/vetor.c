#include<stdio.h>
#include <stdlib.h>


int encontrar_maior(int *vetor, int tamanho) {
    int maior = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    return maior;
}
#include <stdlib.h>

int encontrar_menor(int *vetor, int tamanho) {
    int menor = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    return menor;
}

int busca_binaria(int *vetor, int tamanho, int valor){
    int inicio = vetor[0];
    int ultimo = tamanho - 1;
    while(inicio <= ultimo){
        int meio = (inicio + ultimo)/2;
        if(vetor[meio] == valor)return meio;
        else if(vetor[meio]< valor)inicio = meio + 1;
        else ultimo = meio - 1;
        ultimo = meio -1;

        return -1;
    }
}
int main() {
    int tamanho = 5;
    int *vetor = (int *) malloc(tamanho * sizeof(int));
    vetor[0] = 60;
    vetor[1] = 60;
    vetor[2] = 90;
    vetor[3] = 40;
    vetor[4] = 50;
    int maior = encontrar_maior(vetor, tamanho);
    int menor = encontrar_menor(vetor, tamanho);
    printf("maior: %d \n", maior);
    printf("menor: %d \n", menor);
    free(vetor);
    return 0;
}

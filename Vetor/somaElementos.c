#include<stdio.h>
#include<stdlib.h>

int somaElementos(int *vetor, int tamanho){
    int soma = 0;
    for(int i = 0; i< tamanho; i++)
        soma += vetor[i];
    return soma;
}
int produtoElementos(int *vetor, int tamanho){
    int produto = 1;
    for(int i = 0; i < tamanho; i++)
        produto *= vetor[i];
    return produto;
}

int main() {
    int tamanho = 2;
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    vetor[0] = 5;
    vetor[1] = 5;
    

    int somaEle = somaElementos(vetor, tamanho);
    printf("soma: %d\n", somaEle);
    printf("%d\n",vetor[0]);
    printf("%d\n",vetor[1]);
    int produtoEle = produtoElementos(vetor, tamanho);
    printf("produto: %d\n", produtoEle);

}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initialize(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Elemento %d inserido na pilha.\n", value);
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: a pilha está vazia.\n");
        return -1;
    }
    Node* temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    printf("Elemento %d removido da pilha.\n", value);
    return value;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: a pilha está vazia.\n");
        return -1;
    }
    return stack->top->data;
}

int main() {
    Stack stack;
    initialize(&stack);

    // Inserindo elementos na pilha
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Obtendo o elemento do topo
    int topElement = peek(&stack);
    printf("Elemento do topo: %d\n", topElement);

    // Removendo elementos da pilha
    int removedElement1 = pop(&stack);
    int removedElement2 = pop(&stack);
    printf("Elementos removidos: %d, %d\n", removedElement1, removedElement2);

    // Verificando se a pilha está vazia
    int empty = isEmpty(&stack);
    if (empty) {
        printf("A pilha está vazia.\n");
    } else {
        printf("A pilha não está vazia.\n");
    }

    return 0;
}

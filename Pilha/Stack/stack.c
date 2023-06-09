#include "stack.h"

void iniciaPilha(Pilha *P)
{
    P->topo = NULL;
}

int verificaVazia(Pilha *P)
{
    return P->topo == NULL;
}

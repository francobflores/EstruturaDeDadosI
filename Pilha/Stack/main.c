#include"stack.h"

int main()
{
    Pilha P ;
    iniciaPilha(&P);

    empilhar(&P, 2);
    empilhar(&P, 8);
    empilhar(&P, 9);
    empilhar(&P, 1);

    imprime(&P);

    return 0;

}
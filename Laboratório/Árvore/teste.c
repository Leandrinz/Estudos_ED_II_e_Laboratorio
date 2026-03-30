#include <stdlib.h>
typedef struct no{
    int valor;
    int nfilhos;
    struct no *filhos[10];
} No;

int main(){
    No *raiz = malloc(sizeof(No));
    raiz->valor = 1;
    raiz->nfilhos = 2;

    No *filho1 = malloc(sizeof(No));
    filho1->valor = 2;
    filho1->nfilhos = 0;

    No *filho2 = malloc(sizeof(No));
    filho2->valor = 3;
    filho2->nfilhos = 0;


    return 0;
}

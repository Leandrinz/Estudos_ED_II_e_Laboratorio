#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} No;

No *criar_no(int valor){
    No *raiz = malloc(sizeof(No));
    raiz->esq = NULL;
    raiz->dir = NULL;
    raiz->valor = valor;

    return raiz;
}

int main(){
    No *raiz = criar_no(50);
    printf("%d, \n", raiz->valor);
    return 0;
}
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

void adicionarFilhos(No *pai, No *esq, No *dir){
    pai->esq = esq;
    pai->dir = dir;
}

int main(){
    No *no10 = criar_no(10);
    No *no30 = criar_no(30);
    No *no40 = criar_no(40);
    No *no50 = criar_no(50);
    No *no60 = criar_no(60);
    No *no80 = criar_no(80);
    No *no90 = criar_no(90);

    adicionarFilhos(no30, no10, no40);
    adicionarFilhos(no50, no30, no80);
    adicionarFilhos(no80, no60, no90);

    return 0;
}


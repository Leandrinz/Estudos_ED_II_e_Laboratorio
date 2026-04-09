/*
 * Implementação de uma árvore binária de busca.
 *
 * Data: 06/04/26
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} No;

No *criar_no(int valor) {
    No *raiz = malloc(sizeof(No));
    raiz->esq = NULL;
    raiz->dir = NULL;
    raiz->valor = valor;

    return raiz;
}

No *inserir(No *pai, int valor) {
    if (pai == NULL) {
        return criar_no(valor);
    }

    if (valor > pai->valor) {
        pai->dir = inserir(pai->dir, valor);
    }

    else {
        pai->esq = inserir(pai->esq, valor);
    }

    return pai;
}

void adicionar_filhos(No *pai, No *esq, No *dir) {
    pai->esq = esq;
    pai->dir = dir;
}

int altura(No *raiz) {
    if (raiz == NULL) {
        return -1;
    }

    int al_esq = altura(raiz->esq);
    int al_dir = altura(raiz->dir);

    return (al_esq > al_dir ? al_esq : al_dir) + 1;
}

int main() {
    No *raiz = NULL;
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 90);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    printf("Altura da raiz: %d\n", altura(raiz));

    return 0;
}

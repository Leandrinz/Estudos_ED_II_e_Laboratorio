/*
 * Implementação de uma árvore geral.
 *
 * Data: 30/03/26
 */

#include <stdlib.h>

#define MAX 10

typedef struct no {
    int valor;
    int nfilhos;
    struct no *filhos[MAX];
} No;

No *criar_no(int valor) {
    No *saida = malloc(sizeof(No));

    saida->valor = valor;
    saida->nfilhos = 0;

    return saida;
}

No *add_filho(No *pai, No *filho) {
    if (pai->nfilhos < MAX) {
        pai->filhos[pai->nfilhos++] = filho;
        return pai;
    }

    return NULL;
}

void liberar_no(No *raiz) {
    for (int i = 0; i < raiz->nfilhos; i++) {
        liberar_no(raiz->filhos[i]);
    }

    free(raiz);
}

int main() {
    // Raiz
    No *raiz = criar_no(1);

    // Filhos
    add_filho(raiz, criar_no(3));
    add_filho(raiz, criar_no(2));
    add_filho(raiz, criar_no(5));

    // Netos
    add_filho(raiz->filhos[0], criar_no(4));
    add_filho(raiz->filhos[0], criar_no(5));

    return 0;
}
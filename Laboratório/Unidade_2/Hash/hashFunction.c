#include "aluno.c"

int hashFunction(Aluno A) {
    int hash = 0;

    for (int i = 0; A.nome[i] != '\0'; i++) {
        hash += A.nome[i];
    }

    return hash % 100;
}

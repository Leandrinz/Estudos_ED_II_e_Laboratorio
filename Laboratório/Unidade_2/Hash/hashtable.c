#include "aluno.c"
#include "hashFunction.c"
#include <stdlib.h>

typedef struct {
    Aluno *tabela[100];
} HashTable;

void initHashtable(HashTable **ht);
void inserir(HashTable *ht, Aluno A);

int main() {
    HashTable *ht;
    initHashtable(&ht);

    Aluno alunos[3] = {
        {"João", 10, 'A'}, {"Maria", 20, 'B'}, {"Pedro", 30, 'C'}
    };
    for (int i = 0; i < 3; i++) {
        inserir(ht, alunos[i]);
    }

    return 0;
}

void initHashtable(HashTable **ht) {
    *ht = malloc(sizeof(HashTable));

    for (int i = 0; i < 100; i++) {
        (*ht)->tabela[i] = malloc(sizeof(Aluno));
    }
}

void inserir(HashTable *ht, Aluno A) {
    int x = hashFunction(A);

    if (ht->tabela[x]->nome[0] == '\0') {
        ht->tabela[x] = &A;
    }
}

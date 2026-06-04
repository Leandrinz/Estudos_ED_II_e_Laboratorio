#  Estrutura de Dados II — Guia Completo: Tabelas Hash & Filtros de Bloom
---

## Sumário

1. [Tabelas Hash — Conceitos Fundamentais](#1-tabelas-hash--conceitos-fundamentais)
2. [Funções Hash](#2-funções-hash)
3. [Tratamento de Colisões](#3-tratamento-de-colisões)
4. [Sondagem Linear](#4-sondagem-linear)
5. [Sondagem Quadrática](#5-sondagem-quadrática)
6. [Duplo Hash](#6-duplo-hash)
7. [Encadeamento (Listas Ligadas)](#7-encadeamento-listas-ligadas)
8. [Fator de Carga e Desempenho](#8-fator-de-carga-e-desempenho)
9. [Hash de Placas de Veículos](#9-hash-de-placas-de-veículos)
10. [Filtros de Bloom](#10-filtros-de-bloom)
11. [Crivo de Eratóstenes + Bloom](#11-crivo-de-eratóstenes--bloom)
12. [Exemplos Resolvidos das Questões](#12-exemplos-resolvidos-das-questões)

---

## 1. Tabelas Hash — Conceitos Fundamentais

### O que é uma Tabela Hash?

Uma **tabela hash** é uma estrutura de dados que mapeia **chaves** a **valores** usando uma **função hash** para calcular o índice onde o dado será armazenado. O objetivo é obter acesso em tempo **O(1)** — constante — para inserção, busca e remoção.

### Vantagens sobre Árvores (Questão 1)

| Critério | Tabela Hash | Árvore (BST/AVL/Rubro-Negra) |
|---|---|---|
| Busca (caso médio) | **O(1)** | O(log n) |
| Inserção (caso médio) | **O(1)** | O(log n) |
| Remoção (caso médio) | **O(1)** | O(log n) |
| Ordem dos elementos | ❌ Não mantém | ✅ Mantém ordem |
| Uso de memória | Pode haver desperdício | Compacto |
| Pior caso (colisões) | O(n) | O(log n) garantido (AVL) |

**Resumo para a prova:** Tabelas hash são superiores em velocidade média de acesso, mas não mantêm a ordenação dos elementos e podem degradar para O(n) em caso de muitas colisões.

### Complexidades Esperadas (Questão 2)

| Operação | Caso Médio | Pior Caso |
|---|---|---|
| Inserção | **O(1)** | O(n) |
| Busca | **O(1)** | O(n) |
| Remoção | **O(1)** | O(n) |

O pior caso ocorre quando todas as chaves colidem no mesmo índice (degeneração para lista ligada).

---

## 2. Funções Hash

### Conceito

A função hash `h(x)` transforma uma chave `x` em um índice válido da tabela (entre 0 e m-1, onde m é o tamanho da tabela).

**Propriedades desejáveis de uma boa função hash:**
- Distribuição uniforme (evitar colisões)
- Determinística (mesma entrada → mesma saída)
- Rápida de calcular
- Efeito avalanche (pequenas mudanças na chave → grande mudança no hash)

### Tipos Comuns de Funções Hash

#### a) Resto da Divisão (Módulo)
```
h(x) = x % m
```
Simples e eficiente. Prefira `m` primo para melhor distribuição.

#### b) Função Linear
```
h(x) = (a*x + b) % m
```
Parâmetros `a` e `b` devem ser escolhidos cuidadosamente (idealmente primos).

#### c) Função para Strings
```c
int hash_string(char *s, int m) {
    int h = 0;
    while (*s) {
        h = (h * 31 + *s) % m;
        s++;
    }
    return h;
}
```

---

## 3. Tratamento de Colisões

Uma **colisão** ocorre quando duas chaves diferentes produzem o mesmo índice hash. É inevitável (pelo Princípio das Pombas). Existem duas categorias de tratamento:

1. **Endereçamento Aberto** — tudo na própria tabela (sondagem linear, quadrática, duplo hash)
2. **Encadeamento** — cada posição aponta para uma lista de elementos

---

## 4. Sondagem Linear (Questão 8)

### Conceito

Quando ocorre colisão na posição `h(x)`, procura-se a próxima posição livre de forma sequencial:

```
posição = (h(x) + i) % m,   para i = 0, 1, 2, 3, ...
```

### Variantes da Lista (sA e sB)

- **sA** — Busca a partir da posição seguinte até o **final da tabela** (sem circular). Se não encontrar posição livre, falha.
- **sB** — Busca a partir da posição seguinte, avança até o final e **reinicia do início** se necessário (circular).

### Implementação em C

```c
#define TAM 100
#define VAZIO -1
#define REMOVIDO -2

int tabela[TAM];

void inicializar() {
    for (int i = 0; i < TAM; i++)
        tabela[i] = VAZIO;
}

int hash(int x) {
    return x % TAM;
}

// --- sA: inserção sem circular ---
int inserir_sA(int x) {
    int pos = hash(x);
    for (int i = pos; i < TAM; i++) {
        if (tabela[i] == VAZIO || tabela[i] == REMOVIDO) {
            tabela[i] = x;
            return i;
        }
    }
    return -1; // tabela cheia ou não encontrou posição
}

// --- sB: inserção circular ---
int inserir_sB(int x) {
    int pos = hash(x);
    for (int i = 0; i < TAM; i++) {
        int idx = (pos + i) % TAM;
        if (tabela[idx] == VAZIO || tabela[idx] == REMOVIDO) {
            tabela[idx] = x;
            return idx;
        }
    }
    return -1; // tabela cheia
}

// --- Busca sA ---
int buscar_sA(int x) {
    int pos = hash(x);
    for (int i = pos; i < TAM; i++) {
        if (tabela[i] == x) return i;
        if (tabela[i] == VAZIO) return -1;
    }
    return -1;
}

// --- Busca sB ---
int buscar_sB(int x) {
    int pos = hash(x);
    for (int i = 0; i < TAM; i++) {
        int idx = (pos + i) % TAM;
        if (tabela[idx] == x) return idx;
        if (tabela[idx] == VAZIO) return -1;
    }
    return -1;
}

// --- Remoção (marca como REMOVIDO para não quebrar a cadeia) ---
int remover_sB(int x) {
    int idx = buscar_sB(x);
    if (idx != -1) {
        tabela[idx] = REMOVIDO;
        return idx;
    }
    return -1;
}
```

> ⚠️ **Atenção:** Nunca marque posições removidas como VAZIO, pois isso quebra a cadeia de busca. Use um marcador especial como `REMOVIDO`.

### Problema: Agrupamento Primário

A sondagem linear sofre de **agrupamento primário**: blocos contíguos de posições ocupadas crescem, degradando o desempenho.

### Vantagens e Desvantagens

| | Sondagem Linear |
|---|---|
| ✅ | Simples de implementar |
| ✅ | Boa localidade de cache |
| ❌ | Agrupamento primário |
| ❌ | Desempenho degrada com fator de carga alto |

---

## 5. Sondagem Quadrática (Questão 9)

### Conceito

Em vez de incrementos de 1, usa incrementos quadráticos:

```
posição = (h(x) + i²) % m,   para i = 0, 1, 2, 3, ...
```

Ou com coeficientes:
```
posição = (h(x) + c1*i + c2*i²) % m
```

### Implementação em C

```c
// --- sA: quadrática sem circular ---
int inserir_quad_sA(int x) {
    int pos = hash(x);
    for (int i = 0; i < TAM; i++) {
        int idx = pos + i * i;
        if (idx >= TAM) break; // sem circular
        if (tabela[idx] == VAZIO || tabela[idx] == REMOVIDO) {
            tabela[idx] = x;
            return idx;
        }
    }
    return -1;
}

// --- sB: quadrática circular ---
int inserir_quad_sB(int x) {
    int pos = hash(x);
    for (int i = 0; i < TAM; i++) {
        int idx = (pos + i * i) % TAM;
        if (tabela[idx] == VAZIO || tabela[idx] == REMOVIDO) {
            tabela[idx] = x;
            return idx;
        }
    }
    return -1;
}

int buscar_quad_sB(int x) {
    int pos = hash(x);
    for (int i = 0; i < TAM; i++) {
        int idx = (pos + i * i) % TAM;
        if (tabela[idx] == x) return idx;
        if (tabela[idx] == VAZIO) return -1;
    }
    return -1;
}

int remover_quad_sB(int x) {
    int idx = buscar_quad_sB(x);
    if (idx != -1) {
        tabela[idx] = REMOVIDO;
        return idx;
    }
    return -1;
}
```

### Vantagens e Desvantagens

| | Sondagem Quadrática |
|---|---|
| ✅ | Reduz agrupamento primário |
| ✅ | Melhor distribuição que linear |
| ❌ | Agrupamento secundário (chaves com mesmo hash percorrem o mesmo caminho) |
| ❌ | Pode não encontrar posição livre mesmo com espaço disponível |
| ❌ | Requer m primo para garantir cobertura de toda a tabela |

---

## 6. Duplo Hash (Questão 4c)

### Conceito

Usa **duas funções hash**. A segunda função determina o tamanho do salto:

```
posição = (h1(x) + i * h2(x)) % m,   para i = 0, 1, 2, ...
```

### Requisitos

- `h2(x)` **nunca deve retornar 0**
- Para garantir que todos os slots são visitados, `m` deve ser primo e `h2(x)` deve retornar valores menores que `m`

### Exemplo típico

```c
int h1(int x) { return x % m; }
int h2(int x) { return 1 + (x % (m - 1)); }  // garante >= 1

int inserir_duplo_hash(int x) {
    int p1 = h1(x);
    int p2 = h2(x);
    for (int i = 0; i < TAM; i++) {
        int idx = (p1 + i * p2) % TAM;
        if (tabela[idx] == VAZIO || tabela[idx] == REMOVIDO) {
            tabela[idx] = x;
            return idx;
        }
    }
    return -1;
}
```

### Vantagens e Desvantagens

| | Duplo Hash |
|---|---|
| ✅ | Melhor distribuição de todos os métodos de endereçamento aberto |
| ✅ | Elimina agrupamento primário e secundário |
| ❌ | Mais complexo de implementar |
| ❌ | Pior localidade de cache |
| ❌ | Exige cuidado com a escolha de h2 |

---

## 7. Encadeamento (Listas Ligadas) (Questão 10)

### Conceito

Cada posição da tabela contém um ponteiro para uma **lista encadeada**. Colisões são resolvidas adicionando elementos na lista da posição.

```
tabela[0] -> [A] -> [B] -> NULL
tabela[1] -> [C] -> NULL
tabela[2] -> NULL
tabela[3] -> [D] -> [E] -> [F] -> NULL
```

### Implementação em C

```c
#include <stdio.h>
#include <stdlib.h>

#define TAM 100

typedef struct No {
    int dado;
    struct No *prox;
} No;

No *tabela[TAM];

void inicializar() {
    for (int i = 0; i < TAM; i++)
        tabela[i] = NULL;
}

int hash(int x) {
    return x % TAM;
}

void inserir(int x) {
    int pos = hash(x);
    No *novo = malloc(sizeof(No));
    novo->dado = x;
    novo->prox = tabela[pos]; // insere no início
    tabela[pos] = novo;
}

No* buscar(int x) {
    int pos = hash(x);
    No *atual = tabela[pos];
    while (atual != NULL) {
        if (atual->dado == x) return atual;
        atual = atual->prox;
    }
    return NULL;
}

void remover(int x) {
    int pos = hash(x);
    No *atual = tabela[pos];
    No *anterior = NULL;
    while (atual != NULL) {
        if (atual->dado == x) {
            if (anterior == NULL)
                tabela[pos] = atual->prox;
            else
                anterior->prox = atual->prox;
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}
```

### Vantagens e Desvantagens

| | Encadeamento |
|---|---|
| ✅ | Simples de implementar |
| ✅ | Fator de carga pode ultrapassar 1 |
| ✅ | Remoção é simples |
| ❌ | Overhead de ponteiros (mais memória) |
| ❌ | Pior localidade de cache |
| ❌ | Alocação dinâmica é mais lenta |

---

## 8. Fator de Carga e Desempenho (Questão 6)

### Definição

```
α (alpha) = n / m
```

onde `n` = número de elementos inseridos e `m` = tamanho da tabela.

### Impacto no Desempenho

| Fator de Carga (α) | Comportamento |
|---|---|
| < 0.5 | Excelente — poucas colisões |
| 0.5 – 0.7 | Bom — colisões moderadas |
| > 0.7 | Degradação perceptível |
| → 1.0 | Performance ruim (endereçamento aberto) |

### Simulação da Questão 6

**Situação:** Tabela com `m` posições, 30% ocupadas (α = 0.3). Inserir mais 5% (0.05m elementos).

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 1000  // tamanho da tabela

int tabela[M];
int colisoes = 0;
int inseridos = 0;

int hash_simples(int x) { return x % M; }

void simular() {
    // Inicializa tabela
    for (int i = 0; i < M; i++) tabela[i] = -1;

    // Preenche 30% com elementos fictícios
    srand(42);
    int elementos_iniciais = (int)(0.30 * M);
    int count = 0;
    while (count < elementos_iniciais) {
        int x = rand();
        int pos = hash_simples(x);
        if (tabela[pos] == -1) {
            tabela[pos] = x;
            count++;
        }
    }

    // Tenta inserir 5% adicionais
    int novos = (int)(0.05 * M);
    for (int i = 0; i < novos; i++) {
        int x = rand();
        int pos = hash_simples(x);
        if (tabela[pos] == -1) {
            tabela[pos] = x;
            inseridos++;
        } else {
            colisoes++;  // colisão → não insere
        }
    }

    printf("Tentativas de inserção: %d\n", novos);
    printf("Inseridos com sucesso: %d\n", inseridos);
    printf("Colisões (não inseridos): %d\n", colisoes);
    printf("Percentual de colisão: %.1f%%\n", 100.0 * colisoes / novos);
    printf("Fator de carga final: %.2f%%\n",
           100.0 * (elementos_iniciais + inseridos) / M);
}
```

**Estimativa teórica:** Com α = 0.30, a probabilidade de uma posição estar ocupada é 30%. Portanto, aproximadamente **30% das novas inserções** devem colidir.

---

## 9. Hash de Placas de Veículos (Questão 5)

### Formato Mercosul: ABC1D23

- Posições 0,1,2: letras A-Z (26 valores cada)
- Posição 3: dígito 1-9 (9 valores)
- Posição 4: letra A-Z (26 valores)
- Posições 5,6: dígitos 0-9 (10 valores cada)

**Total de placas possíveis:** 26³ × 9 × 26 × 10² = 456.976.000

### a) Algoritmo de conversão para número único (1 a 456.976.000)

```c
int placa_para_numero(char placa[8]) {
    // placa = "ABC1D23\0"
    int l0 = placa[0] - 'A'; // 0-25
    int l1 = placa[1] - 'A';
    int l2 = placa[2] - 'A';
    int d3 = placa[3] - '1'; // 0-8 (dígito 1-9)
    int l4 = placa[4] - 'A'; // 0-25
    int d5 = placa[5] - '0'; // 0-9
    int d6 = placa[6] - '0'; // 0-9

    int num = l0 * (26 * 26 * 9 * 26 * 100)
            + l1 * (26 * 9 * 26 * 100)
            + l2 * (9 * 26 * 100)
            + d3 * (26 * 100)
            + l4 * 100
            + d5 * 10
            + d6;

    return num + 1; // garante range [1, 456.976.000]
}
```

### b) Função hash mapeando ~25% das posições

25% de 456.976.000 ≈ 114.244.000 posições

```c
int hash_placa_mercosul(char placa[8]) {
    int num = placa_para_numero(placa) - 1; // [0, 456975999]
    int tamanho_tabela = 114244000; // ~25%
    return num % tamanho_tabela;
}
```

### c) Formato Antigo: ABC1234

- Posições 0,1,2: letras A-Z
- Posições 3,4,5,6: dígitos 0-9

**Total:** 26³ × 10⁴ = 175.760.000 placas

Hash para ~12.5% → tabela com ~21.970.000 posições:

```c
int placa_antiga_para_numero(char placa[8]) {
    int l0 = placa[0] - 'A';
    int l1 = placa[1] - 'A';
    int l2 = placa[2] - 'A';
    int d3 = placa[3] - '0';
    int d4 = placa[4] - '0';
    int d5 = placa[5] - '0';
    int d6 = placa[6] - '0';

    return l0 * (26 * 26 * 10000)
         + l1 * (26 * 10000)
         + l2 * 10000
         + d3 * 1000
         + d4 * 100
         + d5 * 10
         + d6;
}

int hash_placa_antiga(char placa[8]) {
    int num = placa_antiga_para_numero(placa);
    int tamanho_tabela = 21970000; // 12.5% de 175.760.000
    return num % tamanho_tabela;
}
```

---

## 10. Filtros de Bloom

### O que é?

Um **Filtro de Bloom** é uma estrutura probabilística que permite verificar se um elemento **provavelmente pertence** ou **definitivamente não pertence** a um conjunto, usando muito menos memória que armazenar o conjunto completo.

### Características

- ✅ **Sem falsos negativos:** se o filtro diz "não está", definitivamente não está
- ⚠️ **Falsos positivos possíveis:** se o filtro diz "está", pode estar errado
- ✅ Extremamente eficiente em memória

### Estrutura

```
Vetor de bits: [0, 0, 1, 0, 1, 1, 0, 0, 1, 0, ...]
                 0  1  2  3  4  5  6  7  8  9
```

### Operações

**Inserção:**
1. Aplique k funções hash ao elemento
2. Para cada resultado, marque o bit correspondente como 1

**Consulta:**
1. Aplique as mesmas k funções hash
2. Se **todos** os bits estiverem em 1 → "provavelmente presente"
3. Se **qualquer** bit for 0 → "definitivamente ausente"

### Implementação Básica em C

```c
#include <stdio.h>
#include <string.h>

#define BITS 128  // 16 bytes × 8 bits

unsigned char filtro[BITS / 8]; // 16 bytes

// Funções hash (Questão 11)
int hash1(int x) { return (3 * x + 7)  % BITS; }
int hash2(int x) { return (5 * x + 11) % BITS; }
int hash3(int x) { return (7 * x + 13) % BITS; }

// Marca um bit no filtro
void marcar_bit(int pos) {
    int byte_idx = pos / 8;
    int bit_idx  = pos % 8;
    filtro[byte_idx] |= (1 << bit_idx);
}

// Verifica se um bit está marcado
int verificar_bit(int pos) {
    int byte_idx = pos / 8;
    int bit_idx  = pos % 8;
    return (filtro[byte_idx] >> bit_idx) & 1;
}

// Inserção
void bloom_inserir(int x) {
    marcar_bit(hash1(x));
    marcar_bit(hash2(x));
    marcar_bit(hash3(x));
}

// Busca
int bloom_buscar(int x) {
    return verificar_bit(hash1(x)) &&
           verificar_bit(hash2(x)) &&
           verificar_bit(hash3(x));
}
```

### Questão 14 — Bit em filtro de 16 bytes com h(x) = 3x + 7

```c
// Filtro de bloom com 16 bytes = 128 bits
// Bytes numerados de 0 a 15, bits de 0 (LSB) a 7 (MSB)

void encontrar_bit(int x) {
    int h = (3 * x + 7);       // sem módulo ainda
    int pos = h % 128;          // posição no filtro (0 a 127)
    int byte_num = pos / 8;     // qual byte (0 a 15)
    int bit_num  = pos % 8;     // qual bit dentro do byte (0=LSB, 7=MSB)

    printf("x=%d → h(x)=%d → pos=%d → byte %d, bit %d\n",
           x, h, pos, byte_num, bit_num);

    // Para marcar: filtro[byte_num] |= (1 << bit_num)
    // Para verificar: (filtro[byte_num] >> bit_num) & 1
}
```

### Questão 15 — Máximo de elementos para 95% de verdadeiros positivos

A taxa de falsos positivos de um Bloom filter é aproximada por:

```
p ≈ (1 - e^(-k*n/m))^k
```

onde:
- `m` = número de bits (1024 bytes × 8 = 8192 bits)
- `k` = número de funções hash
- `n` = número de elementos
- `p` = taxa de falsos positivos desejada (5% → p = 0.05)

Para `p = 0.05` e k ótimo = `m/n × ln(2)`:

```
n_max = m × (ln(2))² / (-ln(p))
      = 8192 × 0.4805 / 2.996
      ≈ 1314 elementos
```

### Questão 16 — Projeto com 128 dados, 3 funções hash, FP < 2%

```
m necessário para p ≤ 0.02, k=3, n=128:
p = (1 - e^(-3×128/m))^3 ≤ 0.02

Resolvendo: m ≈ -k × n / ln(1 - p^(1/k))
           m ≈ -3 × 128 / ln(1 - 0.02^(1/3))
           m ≈ -384 / ln(1 - 0.2714)
           m ≈ -384 / (-0.3175)
           m ≈ 1210 bits ≈ 152 bytes
```

```c
#define M_BITS 1216  // arredonda para múltiplo de 8: 152 bytes
#define M_BYTES 152

unsigned char bloom[M_BYTES];

int h1(int x) { return ((2 * x + 3) % M_BITS + M_BITS) % M_BITS; }
int h2(int x) { return ((5 * x + 7) % M_BITS + M_BITS) % M_BITS; }
int h3(int x) { return ((11 * x + 13) % M_BITS + M_BITS) % M_BITS; }

void inserir_q16(int x) {
    int bits[3] = {h1(x), h2(x), h3(x)};
    for (int i = 0; i < 3; i++)
        bloom[bits[i] / 8] |= (1 << (bits[i] % 8));
}

// Questão 17 — Busca para Q16
int buscar_q16(int x) {
    int bits[3] = {h1(x), h2(x), h3(x)};
    for (int i = 0; i < 3; i++)
        if (!((bloom[bits[i] / 8] >> (bits[i] % 8)) & 1))
            return 0; // definitivamente não está
    return 1; // provavelmente está
}
```

### Questão 11 — Gerador de Família de Funções Hash

```c
// h(x) = (a*x + b) % K
// a e b devem ser primos

int primos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
int num_primos = 12;

// Gera a i-ésima função hash
int gerar_hash(int x, int i, int K) {
    int a = primos[i % num_primos];
    int b = primos[(i + 1) % num_primos];
    return (a * x + b) % K;
}

// Questão 12 — Verificar se todas as posições são alcançáveis
int verifica_cobertura(int a, int b, int K) {
    int *visitados = calloc(K, sizeof(int));
    int cobertos = 0;

    for (int x = 0; x < K * 10; x++) {
        int pos = (a * x + b) % K;
        if (!visitados[pos]) {
            visitados[pos] = 1;
            cobertos++;
        }
        if (cobertos == K) break;
    }

    free(visitados);
    return cobertos == K;
}

// Questão 13 — Tempo para ocupar 50% da tabela
int tempo_para_50_porcento(int a, int b, int K) {
    int *tabela = calloc(K, sizeof(int));
    int ocupados = 0;
    int meta = K / 2;
    int tentativas = 0;

    for (int x = 0; ocupados < meta; x++) {
        int pos = (a * x + b) % K;
        if (!tabela[pos]) {
            tabela[pos] = 1;
            ocupados++;
        }
        tentativas++;
    }

    free(tabela);
    return tentativas;
}
```

---

## 11. Crivo de Eratóstenes + Bloom (Questões 18-21)

### Crivo de Eratóstenes

Algoritmo clássico para encontrar todos os primos até N:

```c
void crivo(int N, int *eh_primo) {
    for (int i = 0; i <= N; i++) eh_primo[i] = 1;
    eh_primo[0] = eh_primo[1] = 0;

    for (int i = 2; i * i <= N; i++)
        if (eh_primo[i])
            for (int j = i * i; j <= N; j += i)
                eh_primo[j] = 0;
}
```

### Questão 18 — Filtro de Bloom para Primos com 5 funções hash

```c
#define N_MAX 100000
#define BLOOM_BITS (N_MAX * 10)  // 10x para manter falsos positivos baixos
#define BLOOM_BYTES (BLOOM_BITS / 8)

unsigned char bloom_primos[BLOOM_BYTES];

int hash_primo(int x, int k) {
    int primos_a[] = {2, 3, 5, 7, 11};
    int primos_b[] = {3, 7, 11, 13, 17};
    return ((primos_a[k] * x + primos_b[k]) % BLOOM_BITS + BLOOM_BITS) % BLOOM_BITS;
}

void bloom_inserir_primo(int x) {
    for (int k = 0; k < 5; k++) {
        int pos = hash_primo(x, k);
        bloom_primos[pos / 8] |= (1 << (pos % 8));
    }
}

int bloom_verificar_primo(int x) {
    for (int k = 0; k < 5; k++) {
        int pos = hash_primo(x, k);
        if (!((bloom_primos[pos / 8] >> (pos % 8)) & 1))
            return 0;
    }
    return 1;
}

// Questão 19 — Busca completa (bloom + verificação real)
int eh_primo_real(int x) {
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return 0;
    return 1;
}

int verificar_primo_completo(int x) {
    if (!bloom_verificar_primo(x)) return 0;  // definitivamente não é primo
    return eh_primo_real(x);                   // verifica de fato
}
```

### Questão 21 — Bloom com unsigned int (4 bytes = 32 bits por posição)

```c
#define N_PRIMOS 2000000
#define BLOOM_SIZE ((N_PRIMOS + 31) / 32)  // número de unsigned ints necessários

unsigned int bloom_uint[BLOOM_SIZE];

// Dado índice i produzido por função hash:
// posição no vetor = i / 32
// deslocamento do bit = i % 32

void marcar_bit_uint(int i) {
    bloom_uint[i / 32] |= (1u << (i % 32));
}

int verificar_bit_uint(int i) {
    return (bloom_uint[i / 32] >> (i % 32)) & 1;
}

// Funções hash para este filtro
int hash_uint(int x, int k, int m) {
    int a[] = {2, 3, 5, 7, 11};
    int b[] = {3, 5, 7, 11, 13};
    return ((long long)a[k] * x + b[k]) % m;
}

void inserir_uint(int x, int m) {
    for (int k = 0; k < 5; k++)
        marcar_bit_uint(hash_uint(x, k, m));
}

int buscar_uint(int x, int m) {
    for (int k = 0; k < 5; k++)
        if (!verificar_bit_uint(hash_uint(x, k, m)))
            return 0;
    return 1;
}
```

**Little-endian afeta o Bloom?**

**Não**, little-endian **não afeta o funcionamento** do filtro de Bloom quando usamos operações bit a bit (`>>`, `<<`, `&`, `|`). Essas operações trabalham nos bits do inteiro na sua representação lógica, independente de como os bytes são armazenados na memória. O resultado de `i / 32` (qual unsigned int) e `i % 32` (qual bit dentro dele) é consistente em qualquer arquitetura. O problema só surgiria se você tentasse interpretar os bytes do filtro como um array de char e acessasse os bits diretamente pela memória física — o que não fazemos aqui.

### Questão 20 — Comparação: Crivo vs Crivo + Bloom

| Critério | Crivo Tradicional | Crivo + Bloom |
|---|---|---|
| Memória | O(N) inteiros | Muito menos (bits) |
| Primos: verificar se é primo | O(1) (array direto) | O(k) funções hash |
| Não-primos: verificar | O(1) | O(k), mas com possível falso positivo |
| Acesso aleatório | ✅ Direto | ✅ Rápido |
| Falsos positivos | ❌ Nenhum | ⚠️ Possível |
| **Conclusão** | Mais eficiente para primos | Útil quando memória é crítica |

**Para primos:** O crivo tradicional é superior, pois o array booleano ocupa 1 bit/byte por elemento e não tem falsos positivos.

**Para não-primos em grandes intervalos:** O filtro de Bloom pode ser vantajoso quando N é muito grande e memória é escassa.

---

## 12. Exemplos Resolvidos das Questões

### Questão 3a — h(x) = x % 13

Inserir: 18, 41, 22, 44, 59, 32, 31, 73, 85

| Chave | h(x) = x%13 | Posição |
|---|---|---|
| 18 | 18%13 = **5** | 5 |
| 41 | 41%13 = **2** | 2 |
| 22 | 22%13 = **9** | 9 |
| 44 | 44%13 = **5** ⚠️ | **colisão** com 18 |
| 59 | 59%13 = **7** | 7 |
| 32 | 32%13 = **6** | 6 |
| 31 | 31%13 = **5** ⚠️ | **colisão** com 18 |
| 73 | 73%13 = **8** | 8 |
| 85 | 85%13 = **7** ⚠️ | **colisão** com 59 |

### Questão 3b — h(x) = (3x + 11) % 13

| Chave | 3x+11 | h(x) | Posição |
|---|---|---|---|
| 18 | 65 | 65%13 = **0** | 0 |
| 41 | 134 | 134%13 = **4** | 4 |
| 22 | 77 | 77%13 = **12** | 12 |
| 44 | 143 | 143%13 = **0** ⚠️ | colisão |
| 59 | 188 | 188%13 = **7** | 7 |
| 32 | 107 | 107%13 = **3** | 3 |
| 31 | 104 | 104%13 = **0** ⚠️ | colisão |
| 73 | 230 | 230%13 = **9** | 9 |
| 85 | 266 | 266%13 = **6** | 6 |

### Tabela de Vantagens/Desvantagens (Questão 7 — resumo rápido)

| Método | Vantagem Principal | Desvantagem Principal |
|---|---|---|
| Sondagem Linear | Simples, cache-friendly | Agrupamento primário |
| Sondagem Quadrática | Reduz agrupamento primário | Agrupamento secundário, pode não achar vaga |
| Duplo Hash | Melhor distribuição | Mais complexo, pior cache |
| Encadeamento | Simples, suporta α > 1 | Overhead de ponteiros, pior cache |

---

##  Dicas Finais para a Prova

1. **Sempre use sentinelas:** Em endereçamento aberto, use `VAZIO` e `REMOVIDO` separados para não quebrar a cadeia de busca.

2. **Fator de carga:** Lembre-se que α = n/m. Manter α < 0.7 em endereçamento aberto é essencial.

3. **Bloom filter — regra de ouro:**
   - 0 no bit → elemento **definitivamente não está**
   - 1 em todos os bits → elemento **provavelmente está** (pode ser falso positivo)

4. **Little-endian e bits:** Operações `>>`, `<<`, `&`, `|` funcionam da mesma forma independente da arquitetura.

5. **Número primo como tamanho de tabela:** Usar `m` primo melhora a distribuição na maioria das funções hash.

6. **h2 no duplo hash nunca pode ser 0:** Use sempre `h2(x) = 1 + (x % (m-1))`.

---

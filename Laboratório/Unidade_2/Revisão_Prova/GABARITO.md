#  GABARITO — Lista de Exercícios: Tabelas Hash & Filtros de Bloom

---

## Questão 1 — Vantagens da Tabela Hash em relação às Árvores

As tabelas hash oferecem as seguintes vantagens sobre árvores de busca:

**1. Velocidade de acesso (caso médio O(1)):**
Em uma tabela hash bem dimensionada, inserção, busca e remoção são realizadas em tempo constante O(1) em média. Árvores balanceadas (AVL, Rubro-Negra) garantem O(log n) mesmo no melhor caso.

**2. Simplicidade de implementação:**
A implementação básica de uma tabela hash (com endereçamento aberto ou encadeamento simples) é mais direta do que o balanceamento de árvores AVL ou Rubro-Negras, que exigem rotações e recolorações.

**3. Desempenho independente da ordem de inserção:**
Em uma BST sem balanceamento, inserir elementos em ordem crescente degenera para O(n). A tabela hash distribui os elementos pela função hash, independente da ordem.

**Quando as árvores são melhores:**
- Quando se precisa manter os elementos em ordem (percurso in-order).
- Quando o pior caso garantido é essencial (árvores AVL/RN garantem O(log n) sempre).
- Quando o fator de carga da hash está alto e há muitas colisões.

---

## Questão 2 — Complexidades Esperadas para Tabela Hash

| Operação | Caso Médio | Pior Caso |
|---|---|---|
| Inserção | **O(1)** | O(n) |
| Busca | **O(1)** | O(n) |
| Remoção | **O(1)** | O(n) |

**O pior caso O(n)** ocorre quando todas as chaves colidem na mesma posição (por exemplo, uma função hash que sempre retorna 0), degenerando a estrutura em uma lista linear.

**O caso médio O(1)** é garantido quando:
- A função hash distribui uniformemente as chaves.
- O fator de carga α = n/m é mantido baixo (idealmente α < 0.7 para endereçamento aberto).

---

## Questão 3 — Inserção na tabela hash com 13 posições

Sequência: **18, 41, 22, 44, 59, 32, 31, 73, 85**

### a) h(x) = x % 13

| Chave | Cálculo | Posição | Observação |
|---|---|---|---|
| 18 | 18 % 13 = 5 | **5** | OK |
| 41 | 41 % 13 = 2 | **2** | OK |
| 22 | 22 % 13 = 9 | **9** | OK |
| 44 | 44 % 13 = 5 | **5** | ⚠️ Colisão com 18 |
| 59 | 59 % 13 = 7 | **7** | OK |
| 32 | 32 % 13 = 6 | **6** | OK |
| 31 | 31 % 13 = 5 | **5** | ⚠️ Colisão com 18 |
| 73 | 73 % 13 = 8 | **8** | OK |
| 85 | 85 % 13 = 7 | **7** | ⚠️ Colisão com 59 |

**Estado da tabela (sem tratamento de colisão — apenas mapeamento primário):**
```
Pos:  0   1   2   3   4   5   6   7   8   9  10  11  12
    [ - ][ - ][41][ - ][ - ][18][32][59][73][22][ - ][ - ][ - ]
```
*(44, 31 e 85 colidiriam e precisariam de tratamento)*

---

### b) h(x) = (3x + 11) % 13

| Chave | 3x + 11 | % 13 | Posição | Observação |
|---|---|---|---|---|
| 18 | 54 + 11 = 65 | 65 % 13 = 0 | **0** | OK |
| 41 | 123 + 11 = 134 | 134 % 13 = 4 | **4** | OK |
| 22 | 66 + 11 = 77 | 77 % 13 = 12 | **12** | OK |
| 44 | 132 + 11 = 143 | 143 % 13 = 0 | **0** | ⚠️ Colisão com 18 |
| 59 | 177 + 11 = 188 | 188 % 13 = 7 | **7** | OK |
| 32 | 96 + 11 = 107 | 107 % 13 = 3 | **3** | OK |
| 31 | 93 + 11 = 104 | 104 % 13 = 0 | **0** | ⚠️ Colisão com 18 |
| 73 | 219 + 11 = 230 | 230 % 13 = 9 | **9** | OK |
| 85 | 255 + 11 = 266 | 266 % 13 = 6 | **6** | OK |

**Estado da tabela (mapeamento primário):**
```
Pos:  0   1   2   3   4   5   6   7   8   9  10  11  12
    [18][ - ][ - ][32][41][ - ][85][59][ - ][73][ - ][ - ][22]
```
*(44 e 31 colidiriam com 18 na posição 0)*

---

### c) h(x) = (3x + 11) % 13 — com sondagem linear (circular)

*(A questão 3c repete a função da 3b — interpreta-se que deve-se aplicar tratamento de colisão por sondagem linear circular para inserir todos os elementos)*

Usando os mesmos valores calculados acima e resolvendo colisões com sondagem linear `(pos + 1) % 13`:

| Chave | h(x) | Colisão? | Posição Final |
|---|---|---|---|
| 18 | 0 | Não | **0** |
| 41 | 4 | Não | **4** |
| 22 | 12 | Não | **12** |
| 44 | 0 | Sim (0 ocupado) → tenta 1 | **1** |
| 59 | 7 | Não | **7** |
| 32 | 3 | Não | **3** |
| 31 | 0 | Sim (0 e 1 ocupados) → tenta 2 | **2** |
| 73 | 9 | Não | **9** |
| 85 | 6 | Não | **6** |

**Estado final da tabela:**
```
Pos:  0   1   2   3   4   5   6   7   8   9  10  11  12
    [18][44][31][32][41][ - ][85][59][ - ][73][ - ][ - ][22]
```

---

## Questão 4 — Conceitos de Tratamento de Colisões

### a) Sondagem Linear

Quando ocorre colisão na posição `h(x)`, busca-se a próxima posição disponível de forma sequencial:

```
pos(i) = (h(x) + i) % m,   i = 0, 1, 2, 3, ...
```

Continua incrementando `i` até encontrar uma posição vazia ou `REMOVIDA`.

**Problema:** Agrupamento primário — blocos contíguos de posições ocupadas crescem progressivamente, aumentando o número de sondagens e degradando o desempenho.

---

### b) Sondagem Quadrática

Em vez de incrementos de 1, usa incrementos quadráticos para dispersar melhor os elementos:

```
pos(i) = (h(x) + i²) % m,   i = 0, 1, 2, 3, ...
```

Ou na forma geral: `pos(i) = (h(x) + c1*i + c2*i²) % m`

**Melhoria:** Reduz o agrupamento primário, pois o padrão de sondagem "pula" posições.

**Problema remanescente:** Agrupamento secundário — duas chaves com o mesmo `h(x)` percorrem exatamente o mesmo caminho de sondagem. Além disso, com tabela de tamanho não-primo, pode não visitar todas as posições.

---

### c) Duplo Hash

Usa duas funções hash. A segunda determina o tamanho do salto entre tentativas:

```
pos(i) = (h1(x) + i * h2(x)) % m,   i = 0, 1, 2, 3, ...
```

**Requisitos:**
- `h2(x)` nunca deve ser 0 (senão fica preso na mesma posição)
- `m` deve ser primo para garantir que todas as posições sejam visitadas
- Implementação típica: `h2(x) = 1 + (x % (m - 1))`

**Vantagem:** Elimina agrupamento primário e secundário. É o método de endereçamento aberto com melhor distribuição.

---

## Questão 5 — Hash de Placas de Veículos

### a) Algoritmo de conversão da placa Mercosul (ABC1D23) para número único [1, 456.976.000]

A placa tem 7 caracteres com os seguintes domínios:
- Posições 0,1,2: letras A-Z → 26 valores cada
- Posição 3: dígito 1-9 → 9 valores
- Posição 4: letra A-Z → 26 valores
- Posições 5,6: dígitos 0-9 → 10 valores cada

Total: 26³ × 9 × 26 × 10² = 17.576 × 9 × 26 × 100 = **456.976.000**

```c
#include <stdio.h>

// Converte placa Mercosul para número único [1, 456.976.000]
// Formato: ABC1D23 (índices 0123456)
long long placa_para_numero(char placa[]) {
    int l0 = placa[0] - 'A'; // 0-25
    int l1 = placa[1] - 'A'; // 0-25
    int l2 = placa[2] - 'A'; // 0-25
    int d3 = placa[3] - '1'; // 0-8  (dígito 1-9)
    int l4 = placa[4] - 'A'; // 0-25
    int d5 = placa[5] - '0'; // 0-9
    int d6 = placa[6] - '0'; // 0-9

    // Base mista: 26 × 26 × 26 × 9 × 26 × 10 × 10
    long long num = (long long)l0 * (26LL * 26 * 9 * 26 * 100)
                  + (long long)l1 * (26LL * 9 * 26 * 100)
                  + (long long)l2 * (9LL * 26 * 100)
                  + (long long)d3 * (26LL * 100)
                  + (long long)l4 * 100
                  + d5 * 10
                  + d6;

    return num + 1; // [1, 456.976.000]
}

// Verificação:
// Menor placa AAA1A00 → 0+1 = 1           ✓
// Maior placa ZZZ9Z99 → 456.975.999 + 1 = 456.976.000  ✓
```

---

### b) Função hash mapeando ~25% das posições possíveis

25% de 456.976.000 ≈ **114.244.000** posições na tabela.

```c
#define TAMANHO_HASH_MERCOSUL 114244013LL  // número primo próximo de 25%

// Converte placa (como sequência de char) para índice na tabela hash
int hash_placa_mercosul(char placa[]) {
    long long num = placa_para_numero(placa) - 1; // [0, 456.975.999]
    return (int)(num % TAMANHO_HASH_MERCOSUL);
}

// Uso:
// char placa[] = "ABC1D23";
// int pos = hash_placa_mercosul(placa); // retorna índice em [0, 114.244.012]
```

---

### c) Hash para placas antigas (ABC1234) mapeando ~12,5%

Formato ABC1234:
- Posições 0,1,2: letras A-Z → 26³ = 17.576
- Posições 3,4,5,6: dígitos 0-9 → 10⁴ = 10.000

Total: 26³ × 10⁴ = **175.760.000** placas

12,5% de 175.760.000 ≈ **21.970.000** posições

```c
#define TAMANHO_HASH_ANTIGO 21970013  // número primo próximo de 12.5%

long long placa_antiga_para_numero(char placa[]) {
    int l0 = placa[0] - 'A'; // 0-25
    int l1 = placa[1] - 'A'; // 0-25
    int l2 = placa[2] - 'A'; // 0-25
    int d3 = placa[3] - '0'; // 0-9
    int d4 = placa[4] - '0'; // 0-9
    int d5 = placa[5] - '0'; // 0-9
    int d6 = placa[6] - '0'; // 0-9

    return (long long)l0 * (26LL * 26 * 10000)
         + (long long)l1 * (26LL * 10000)
         + (long long)l2 * 10000
         + d3 * 1000
         + d4 * 100
         + d5 * 10
         + d6;
}

int hash_placa_antiga(char placa[]) {
    long long num = placa_antiga_para_numero(placa);
    return (int)(num % TAMANHO_HASH_ANTIGO);
}
```

---

## Questão 6 — Simulação de Inserções com Colisão = Não Inserir

**Situação:** Tabela com `m` posições, fator de carga inicial de 30%. Tentar inserir mais 5% da capacidade. Se houver colisão, não inserir.

**Estimativa teórica:** Com α = 0,30, a probabilidade de uma posição aleatória estar ocupada é 30%. Portanto, ~30% das novas inserções devem colidir.

**Fator de carga final previsto:** 30% + (5% × 70%) = 30% + 3,5% = **~33,5%**

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10000  // tamanho da tabela (qualquer valor)

int tabela[M];

int hash_simples(int x) {
    return ((x % M) + M) % M; // garante positivo
}

int main() {
    srand(42);

    // Inicializa tabela
    for (int i = 0; i < M; i++) tabela[i] = -1;

    // Preenche 30% inicial
    int alvo_inicial = (int)(0.30 * M);
    int inseridos_iniciais = 0;
    while (inseridos_iniciais < alvo_inicial) {
        int x = rand();
        int pos = hash_simples(x);
        if (tabela[pos] == -1) {
            tabela[pos] = x;
            inseridos_iniciais++;
        }
    }

    // Tenta inserir 5% adicionais
    int tentativas = (int)(0.05 * M);
    int colisoes = 0;
    int novos_inseridos = 0;

    for (int i = 0; i < tentativas; i++) {
        int x = rand();
        int pos = hash_simples(x);
        if (tabela[pos] == -1) {
            tabela[pos] = x;
            novos_inseridos++;
        } else {
            colisoes++; // colisão → não insere
        }
    }

    int total = inseridos_iniciais + novos_inseridos;

    printf("=== Simulação de Inserções ===\n");
    printf("Tamanho da tabela (m): %d\n", M);
    printf("Elementos iniciais (30%%): %d\n", inseridos_iniciais);
    printf("Tentativas de inserção (5%%): %d\n", tentativas);
    printf("Inseridos com sucesso: %d\n", novos_inseridos);
    printf("Colisões (não inseridos): %d\n", colisoes);
    printf("\na) Percentual de colisões: %.2f%%\n",
           100.0 * colisoes / tentativas);
    printf("b) Fator de carga final: %.2f%%\n",
           100.0 * total / M);

    return 0;
}
```

**Saída esperada (aproximada):**
```
a) Percentual de colisões: ~30%
b) Fator de carga final: ~33.5%
```

---

## Questão 7 — Vantagens e Desvantagens de Cada Tratamento de Colisão

### Sondagem Linear

| ✅ Vantagens | ❌ Desvantagens |
|---|---|
| Simples de implementar | Agrupamento primário (clustering) |
| Excelente localidade de cache | Desempenho degrada com α alto |
| Sem overhead de ponteiros | Remoção exige marcador especial |
| Todos os elementos ficam na tabela | Pode não inserir se tabela cheia (sA sem circular) |

### Sondagem Quadrática

| ✅ Vantagens | ❌ Desvantagens |
|---|---|
| Reduz agrupamento primário | Agrupamento secundário |
| Melhor distribuição que linear | Pode não encontrar posição livre (se m não for primo) |
| Sem overhead de ponteiros | Mais complexo que linear |
| Boa localidade de cache | Remoção exige marcador especial |

### Duplo Hash

| ✅ Vantagens | ❌ Desvantagens |
|---|---|
| Melhor distribuição de todos | Mais complexo de implementar |
| Elimina agrupamentos primário e secundário | Pior localidade de cache |
| Comportamento próximo ao ideal | Requer cuidado com escolha de h2 |
| Sem overhead de ponteiros | h2(x) nunca pode ser 0 |

### Encadeamento (Listas Ligadas)

| ✅ Vantagens | ❌ Desvantagens |
|---|---|
| Simples de implementar | Overhead de ponteiros (mais memória) |
| Fator de carga pode ultrapassar 1 | Pior localidade de cache |
| Remoção é simples (sem marcador) | Alocação dinâmica é mais lenta |
| Não precisa de rehashing imediato | Lista pode crescer muito em má hash |

---

## Questão 8 — Sondagem Linear (tabela com 100 posições)

```c
#include <stdio.h>
#include <string.h>

#define TAM 100
#define VAZIO   -1
#define REMOVIDO -2

int tabela[TAM];

void inicializar() {
    for (int i = 0; i < TAM; i++)
        tabela[i] = VAZIO;
}

int hash(int x) {
    return ((x % TAM) + TAM) % TAM;
}

/* =================== sA: sem circular =================== */

// Inserção sA: busca da posição seguinte até o FINAL da tabela
int inserir_sA(int x) {
    int pos = hash(x);
    for (int i = pos; i < TAM; i++) {
        if (tabela[i] == VAZIO || tabela[i] == REMOVIDO) {
            tabela[i] = x;
            return i;
        }
    }
    return -1; // não encontrou posição livre
}

// Busca sA
int buscar_sA(int x) {
    int pos = hash(x);
    for (int i = pos; i < TAM; i++) {
        if (tabela[i] == x)     return i;  // encontrado
        if (tabela[i] == VAZIO) return -1; // não está
    }
    return -1;
}

// Remoção sA
int remover_sA(int x) {
    int idx = buscar_sA(x);
    if (idx != -1) {
        tabela[idx] = REMOVIDO;
        return idx;
    }
    return -1;
}

/* =================== sB: circular =================== */

// Inserção sB: busca circular (reinicia no início)
int inserir_sB(int x) {
    int pos = hash(x);
    for (int i = 0; i < TAM; i++) {
        int idx = (pos + i) % TAM;
        if (tabela[idx] == VAZIO || tabela[idx] == REMOVIDO) {
            tabela[idx] = x;
            return idx;
        }
    }
    return -1; // tabela completamente cheia
}

// Busca sB
int buscar_sB(int x) {
    int pos = hash(x);
    for (int i = 0; i < TAM; i++) {
        int idx = (pos + i) % TAM;
        if (tabela[idx] == x)     return idx;
        if (tabela[idx] == VAZIO) return -1;
    }
    return -1;
}

// Remoção sB
int remover_sB(int x) {
    int idx = buscar_sB(x);
    if (idx != -1) {
        tabela[idx] = REMOVIDO;
        return idx;
    }
    return -1;
}

/* =================== main de teste =================== */
int main() {
    inicializar();

    inserir_sB(15);
    inserir_sB(115); // colide com 15 (115 % 100 = 15)
    inserir_sB(215); // colide novamente

    printf("15  → posição %d\n", buscar_sB(15));
    printf("115 → posição %d\n", buscar_sB(115));
    printf("215 → posição %d\n", buscar_sB(215));

    remover_sB(115);
    printf("Após remover 115:\n");
    printf("115 → posição %d (esperado -1)\n", buscar_sB(115));
    printf("215 → posição %d (deve continuar encontrado)\n", buscar_sB(215));

    return 0;
}
```

> ⚠️ **Por que usar REMOVIDO e não VAZIO na remoção?**
> Se marcarmos como VAZIO, a busca por elementos inseridos APÓS a colisão será interrompida prematuramente, pois ela para ao encontrar VAZIO.

---

## Questão 9 — Sondagem Quadrática (tabela com 100 posições)

```c
#include <stdio.h>

#define TAM 100
#define VAZIO   -1
#define REMOVIDO -2

int tabela[TAM];

void inicializar() {
    for (int i = 0; i < TAM; i++)
        tabela[i] = VAZIO;
}

int hash(int x) {
    return ((x % TAM) + TAM) % TAM;
}

/* =================== sA: quadrática sem circular =================== */

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

int buscar_quad_sA(int x) {
    int pos = hash(x);
    for (int i = 0; i < TAM; i++) {
        int idx = pos + i * i;
        if (idx >= TAM) break;
        if (tabela[idx] == x)     return idx;
        if (tabela[idx] == VAZIO) return -1;
    }
    return -1;
}

int remover_quad_sA(int x) {
    int idx = buscar_quad_sA(x);
    if (idx != -1) { tabela[idx] = REMOVIDO; return idx; }
    return -1;
}

/* =================== sB: quadrática circular =================== */

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
        if (tabela[idx] == x)     return idx;
        if (tabela[idx] == VAZIO) return -1;
    }
    return -1;
}

int remover_quad_sB(int x) {
    int idx = buscar_quad_sB(x);
    if (idx != -1) { tabela[idx] = REMOVIDO; return idx; }
    return -1;
}

/* =================== main de teste =================== */
int main() {
    inicializar();

    inserir_quad_sB(10);
    inserir_quad_sB(110); // colide: 110%100 = 10
    inserir_quad_sB(210); // colide: 210%100 = 10

    // 110 vai para (10 + 1) % 100 = 11
    // 210 vai para (10 + 4) % 100 = 14
    printf("10  → posição %d\n", buscar_quad_sB(10));
    printf("110 → posição %d\n", buscar_quad_sB(110));
    printf("210 → posição %d\n", buscar_quad_sB(210));

    remover_quad_sB(110);
    printf("Após remover 110:\n");
    printf("210 → posição %d (deve continuar encontrado)\n", buscar_quad_sB(210));

    return 0;
}
```

---

## Questão 10 — Tabela Hash com Encadeamento (Listas Ligadas)

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
    return ((x % TAM) + TAM) % TAM;
}

/* =================== Inclusão =================== */
void inserir(int x) {
    int pos = hash(x);
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = x;
    novo->prox = tabela[pos]; // insere no início da lista
    tabela[pos] = novo;
}

/* =================== Busca =================== */
No* buscar(int x) {
    int pos = hash(x);
    No *atual = tabela[pos];
    while (atual != NULL) {
        if (atual->dado == x) return atual; // encontrado
        atual = atual->prox;
    }
    return NULL; // não encontrado
}

/* =================== Remoção (bônus) =================== */
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

/* =================== Exibição =================== */
void exibir() {
    for (int i = 0; i < TAM; i++) {
        if (tabela[i] != NULL) {
            printf("[%2d] → ", i);
            No *atual = tabela[i];
            while (atual) {
                printf("%d → ", atual->dado);
                atual = atual->prox;
            }
            printf("NULL\n");
        }
    }
}

int main() {
    inicializar();
    inserir(5); inserir(105); inserir(205); // todos na pos 5
    inserir(42); inserir(99);

    exibir();

    No *encontrado = buscar(105);
    printf("\nBuscar 105: %s\n", encontrado ? "Encontrado" : "Não encontrado");
    printf("Buscar 999: %s\n", buscar(999) ? "Encontrado" : "Não encontrado");

    remover(105);
    printf("Após remover 105:\n");
    printf("Buscar 105: %s\n", buscar(105) ? "Encontrado" : "Não encontrado");
    printf("Buscar 205: %s\n", buscar(205) ? "Encontrado" : "Não encontrado");

    return 0;
}
```

---

## Questão 11 — Gerador de Sequência de Funções Hash h(x) = (ax + b) % K

```c
#include <stdio.h>
#include <math.h>

// Verifica se um número é primo
int eh_primo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

// Retorna o i-ésimo número primo (i começa em 0)
int i_esimo_primo(int i) {
    int count = 0, n = 2;
    while (1) {
        if (eh_primo(n)) {
            if (count == i) return n;
            count++;
        }
        n++;
    }
}

// Gera e retorna o valor de h_i(x) = (a_i * x + b_i) % K
// a e b são primos distintos, variando a cada i
int gerar_hash(int x, int i, int K) {
    int a = i_esimo_primo(i * 2);       // primo na posição par
    int b = i_esimo_primo(i * 2 + 1);   // primo na posição ímpar
    return (a * x + b) % K;
}

// Gera e exibe n funções hash para um dado x e tamanho K
void gerar_familia(int x, int n, int K) {
    printf("Família de %d funções hash para x=%d, K=%d:\n", n, x, K);
    for (int i = 0; i < n; i++) {
        int a = i_esimo_primo(i * 2);
        int b = i_esimo_primo(i * 2 + 1);
        int resultado = (a * x + b) % K;
        printf("  h%d(x) = (%d*x + %d) %% %d = %d\n", i, a, b, K, resultado);
    }
}

int main() {
    gerar_familia(42, 5, 100);
    return 0;
}
```

**Saída de exemplo:**
```
h0(x) = (2*x + 3) % 100 = 87
h1(x) = (5*x + 7) % 100 = 17
h2(x) = (11*x + 13) % 100 = 75
h3(x) = (17*x + 19) % 100 = 33
h4(x) = (23*x + 29) % 100 = 95
```

---

## Questão 12 — Verificar se as Funções Hash Alcançam Todos os K Elementos

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int eh_primo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

// Verifica se h(x) = (a*x + b) % K consegue alcançar TODOS os K valores
// Testa para x = 0, 1, 2, ..., K-1 (basta K tentativas para cobertura completa)
int verifica_cobertura(int a, int b, int K) {
    int *visitados = (int *)calloc(K, sizeof(int));
    int cobertos = 0;

    for (int x = 0; x < K; x++) {
        int pos = (a * x + b) % K;
        if (!visitados[pos]) {
            visitados[pos] = 1;
            cobertos++;
        }
    }

    free(visitados);
    return cobertos == K;
}

// Testa toda a família gerada na Q11
void testar_familia(int n_funcoes, int K) {
    printf("Verificação de cobertura total (K=%d):\n", K);
    int a = 2, b = 3;
    int primos_usados = 0;

    for (int i = 0; i < n_funcoes; i++) {
        // Pega o i-ésimo par de primos
        int count = 0, num = 2;
        while (count < i * 2) { num++; if (eh_primo(num)) count++; }
        a = num;
        count = 0; num = 2;
        while (count < i * 2 + 1) { num++; if (eh_primo(num)) count++; }
        b = num;

        int cobre_tudo = verifica_cobertura(a, b, K);
        printf("  h%d(x) = (%d*x + %d) %% %d → %s\n",
               i, a, b, K, cobre_tudo ? "✓ Cobre tudo" : "✗ Não cobre tudo");
    }
}

int main() {
    // Para K primo, h(x) = (a*x + b) % K cobre todos os K valores
    // se mdc(a, K) = 1, o que é garantido quando a é primo e K é primo diferente de a
    testar_familia(5, 101); // K=101 (primo)
    printf("\n");
    testar_familia(5, 100); // K=100 (não primo — alguns podem não cobrir tudo)
    return 0;
}
```

**Conceito chave:** Para que `h(x) = (ax + b) % K` percorra todos os K valores, é necessário que `mdc(a, K) = 1`. Isso é garantido quando K é primo e `a` não é múltiplo de K.

---

## Questão 13 — Tempo para Ocupar 50% da Tabela

```c
#include <stdio.h>
#include <stdlib.h>

// Retorna o número de inserções necessárias para ocupar 50% de K posições
// usando h(x) = (a*x + b) % K, testando x = 0, 1, 2, ...
int tempo_para_50_porcento(int a, int b, int K) {
    int *tabela = (int *)calloc(K, sizeof(int));
    int meta = K / 2;
    int ocupados = 0;
    int x = 0;

    while (ocupados < meta) {
        int pos = (a * x + b) % K;
        if (!tabela[pos]) {
            tabela[pos] = 1;
            ocupados++;
        }
        x++;
    }

    free(tabela);
    return x; // número de tentativas realizadas
}

int main() {
    int K = 101; // tamanho primo
    int a = 3, b = 7;

    printf("h(x) = (%d*x + %d) %% %d\n", a, b, K);
    printf("Meta: %d posições (50%%)\n", K / 2);

    int tentativas = tempo_para_50_porcento(a, b, K);
    printf("Inserções necessárias: %d\n", tentativas);
    printf("Eficiência: %.1f%% (sem colisões)\n",
           100.0 * (K / 2) / tentativas);

    return 0;
}
```

**Observação:** Se a função hash cobre uniformemente todas as posições (mdc(a, K) = 1), o número de tentativas para ocupar 50% será exatamente K/2, pois cada x produz um índice novo. Caso contrário, haverá colisões e o número de tentativas será maior.

---

## Questão 14 — Bit selecionado no Filtro de Bloom de 16 bytes com h(x) = 3x + 7

```
Filtro: 16 bytes = 128 bits
Bytes numerados: 0 a 15
Bits numerados: 0 (LSB) a 7 (MSB) dentro de cada byte
```

```c
#include <stdio.h>

#define NUM_BYTES 16
#define NUM_BITS  128  // 16 * 8

unsigned char filtro[NUM_BYTES];

// Determina qual bit marcar dado x e h(x) = 3x + 7
void determinar_bit(int x) {
    int h = 3 * x + 7;
    int pos      = h % NUM_BITS;  // posição no filtro [0, 127]
    int byte_num = pos / 8;       // qual byte [0, 15]
    int bit_num  = pos % 8;       // qual bit no byte [0=LSB, 7=MSB]

    printf("x = %d\n", x);
    printf("  h(x) = 3*%d + 7 = %d\n", x, h);
    printf("  pos no filtro = %d %% 128 = %d\n", h, pos);
    printf("  byte %d, bit %d (LSB=0)\n", byte_num, bit_num);
    printf("  Para marcar: filtro[%d] |= (1 << %d)\n\n", byte_num, bit_num);
}

void marcar_bit(int pos) {
    filtro[pos / 8] |= (1 << (pos % 8));
}

int verificar_bit(int pos) {
    return (filtro[pos / 8] >> (pos % 8)) & 1;
}

int main() {
    // Exemplos
    determinar_bit(0);   // h = 7  → pos 7  → byte 0, bit 7
    determinar_bit(1);   // h = 10 → pos 10 → byte 1, bit 2
    determinar_bit(10);  // h = 37 → pos 37 → byte 4, bit 5
    determinar_bit(100); // h = 307 → 307%128 = 51 → byte 6, bit 3

    // Marcação e verificação
    int x = 10;
    int pos = (3 * x + 7) % NUM_BITS;
    marcar_bit(pos);
    printf("Bit para x=10 marcado? %s\n", verificar_bit(pos) ? "Sim" : "Não");

    return 0;
}
```

**Exemplo manual:**
- x = 5 → h(5) = 3×5 + 7 = 22 → pos = 22%128 = 22 → byte 2, bit 6
- Para marcar: `filtro[2] |= (1 << 6)` → `filtro[2] |= 0b01000000`

---

## Questão 15 — Máximo de elementos com 95% de certeza (1024 bytes, bloom)

**Dados:**
- Filtro: 1024 bytes = **8192 bits** (m = 8192)
- Certeza de verdadeiros positivos: 95% → taxa de falsos positivos p = **5% = 0,05**

**Fórmula da taxa de falsos positivos:**

```
p ≈ (1 - e^(-k*n/m))^k
```

**Número ótimo de funções hash:**
```
k_ótimo = (m/n) × ln(2)
```

Para encontrar n_max dado p = 0,05:

Usando k_ótimo e substituindo, a fórmula simplifica para:
```
n_max = m × ln(2)² / (-ln(p))
      = 8192 × 0,4805 / (-ln(0,05))
      = 8192 × 0,4805 / 2,9957
      = 3936 / 2,9957
      ≈ 1314 elementos
```

```c
#include <stdio.h>
#include <math.h>

int main() {
    double m = 8192.0;  // 1024 bytes * 8
    double p = 0.05;    // 5% de falsos positivos

    // n_max = m * ln(2)^2 / (-ln(p))
    double n_max = m * log(2) * log(2) / (-log(p));

    printf("Filtro: %.0f bits\n", m);
    printf("Taxa FP desejada: %.0f%%\n", p * 100);
    printf("n_max ≈ %.0f elementos\n", n_max);

    // Número ótimo de funções hash para esse n
    double k_opt = (m / n_max) * log(2);
    printf("k ótimo ≈ %.1f funções hash\n", k_opt);

    return 0;
}
```

**Resposta:** É possível inserir até aproximadamente **1314 elementos** mantendo 95% de certeza nos verdadeiros positivos, usando o número ótimo de funções hash (~4 a 5 funções).

---

## Questão 16 — Projeto de Filtro: 128 dados, 3 funções hash, FP < 2%

**Dados:** n = 128, k = 3, p ≤ 0,02

**Cálculo do tamanho mínimo do filtro:**

```
p = (1 - e^(-k*n/m))^k ≤ 0,02

Isolando m:
1 - e^(-k*n/m) ≤ p^(1/k)
e^(-k*n/m) ≥ 1 - p^(1/k)
-k*n/m ≥ ln(1 - p^(1/k))
m ≥ -k*n / ln(1 - p^(1/k))

m ≥ -(3 × 128) / ln(1 - 0,02^(1/3))
m ≥ -384 / ln(1 - 0,2714)
m ≥ -384 / (-0,3175)
m ≥ 1209 bits ≈ 152 bytes
```

```c
#include <stdio.h>
#include <math.h>

#define K  3
#define N  128
#define M_BITS 1216   // arredondado para múltiplo de 8: 152 bytes
#define M_BYTES (M_BITS / 8)

unsigned char bloom[M_BYTES];

// 3 funções hash com a e b primos
int h0(int x) { return ((2 * x + 3) % M_BITS + M_BITS) % M_BITS; }
int h1(int x) { return ((5 * x + 7) % M_BITS + M_BITS) % M_BITS; }
int h2(int x) { return ((11 * x + 13) % M_BITS + M_BITS) % M_BITS; }

int hashes[3];

void calcular_hashes(int x) {
    hashes[0] = h0(x);
    hashes[1] = h1(x);
    hashes[2] = h2(x);
}

void inserir(int x) {
    calcular_hashes(x);
    for (int i = 0; i < K; i++)
        bloom[hashes[i] / 8] |= (1 << (hashes[i] % 8));
}

// Questão 17 — Função de busca para Q16
int buscar(int x) {
    calcular_hashes(x);
    for (int i = 0; i < K; i++)
        if (!((bloom[hashes[i] / 8] >> (hashes[i] % 8)) & 1))
            return 0; // definitivamente não está
    return 1; // provavelmente está
}

int main() {
    printf("=== Filtro de Bloom ===\n");
    printf("Bits: %d | Bytes: %d | k=%d | n=%d | FP<2%%\n\n",
           M_BITS, M_BYTES, K, N);

    // Inserindo 128 elementos
    for (int i = 1; i <= N; i++)
        inserir(i);

    // Testando
    printf("Busca 50 (inserido): %s\n", buscar(50) ? "Presente" : "Ausente");
    printf("Busca 200 (não inserido): %s\n", buscar(200) ? "Presente (FP!)" : "Ausente");
    printf("Busca 1 (inserido): %s\n", buscar(1) ? "Presente" : "Ausente");

    return 0;
}
```

---

## Questão 17 — Função de Busca para Q16

*A função `buscar()` já está implementada acima na Questão 16.*

**Funcionamento:**
1. Calcula as 3 posições de bit com h0, h1 e h2
2. Verifica se **todos** os bits estão marcados
3. Se qualquer bit for 0 → elemento **definitivamente não está** (retorna 0)
4. Se todos os bits forem 1 → elemento **provavelmente está** (retorna 1, pode ser falso positivo)

---

## Questão 18 — Filtro de Bloom para Primos com 5 Funções Hash e Tolerância de 1%

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define N_MAX    100000
#define K_FUNCS  5
#define FP_MAX   0.01   // 1% de falsos positivos

// Calcula o tamanho mínimo do filtro para n elementos, k funções, FP ≤ p
int calcular_m(int n, int k, double p) {
    double m = -(double)k * n / log(1.0 - pow(p, 1.0 / k));
    return (int)ceil(m / 8) * 8; // arredonda para múltiplo de 8
}

int M_BITS;
int M_BYTES;
unsigned char *bloom;

// Crivo de Eratóstenes
int *crivo(int N) {
    int *eh_primo = (int *)calloc(N + 1, sizeof(int));
    for (int i = 2; i <= N; i++) eh_primo[i] = 1;
    for (int i = 2; (long long)i * i <= N; i++)
        if (eh_primo[i])
            for (int j = i * i; j <= N; j += i)
                eh_primo[j] = 0;
    return eh_primo;
}

// Família de 5 funções hash com coeficientes primos
int hash_k(int x, int k) {
    int a[] = {2,  3,  5,  7,  11};
    int b[] = {3,  7, 11, 13,  17};
    return (int)(((long long)a[k] * x + b[k]) % M_BITS);
}

void marcar(int x) {
    for (int k = 0; k < K_FUNCS; k++) {
        int pos = hash_k(x, k);
        bloom[pos / 8] |= (1 << (pos % 8));
    }
}

int verificar(int x) {
    for (int k = 0; k < K_FUNCS; k++) {
        int pos = hash_k(x, k);
        if (!((bloom[pos / 8] >> (pos % 8)) & 1))
            return 0;
    }
    return 1;
}

// Conta a taxa de falsos positivos atual
double taxa_fp(int *eh_primo, int n_primos, int N) {
    int fp = 0, negativos = 0;
    for (int i = 2; i <= N; i++) {
        if (!eh_primo[i]) {
            negativos++;
            if (verificar(i)) fp++;
        }
    }
    return negativos > 0 ? (double)fp / negativos : 0.0;
}

int main() {
    int *primo = crivo(N_MAX);

    // Conta primos
    int n_primos = 0;
    for (int i = 2; i <= N_MAX; i++)
        if (primo[i]) n_primos++;

    // Dimensiona filtro
    M_BITS  = calcular_m(n_primos, K_FUNCS, FP_MAX);
    M_BYTES = M_BITS / 8;
    bloom   = (unsigned char *)calloc(M_BYTES, 1);

    printf("Primos até %d: %d\n", N_MAX, n_primos);
    printf("Filtro: %d bits (%d bytes), k=%d, FP alvo=%.1f%%\n\n",
           M_BITS, M_BYTES, K_FUNCS, FP_MAX * 100);

    // Insere primos no filtro
    for (int i = 2; i <= N_MAX; i++)
        if (primo[i]) marcar(i);

    printf("Taxa de FP após inserção: %.2f%%\n",
           taxa_fp(primo, n_primos, N_MAX) * 100);

    free(primo);
    free(bloom);
    return 0;
}
```

---

## Questão 19 — Busca Completa: Bloom + Verificação Real de Primalidade

```c
// (inclui as definições da Q18)

// Verificação real de primalidade (para confirmar positivos do bloom)
int eh_primo_real(int x) {
    if (x < 2) return 0;
    if (x == 2) return 1;
    if (x % 2 == 0) return 0;
    for (int i = 3; (long long)i * i <= x; i += 2)
        if (x % i == 0) return 0;
    return 1;
}

// Verificação completa: bloom + confirmação
// Retorna: 0 = definitivamente não primo
//          1 = primo confirmado
int verificar_primo_completo(int x) {
    if (!verificar(x))
        return 0;           // bloom diz "não" → definitivamente não é primo
    return eh_primo_real(x); // bloom diz "talvez" → verifica de fato
}

// Verifica todos os números de 1 até N
void verificar_todos(int N) {
    int falsos_positivos = 0;
    int verdadeiros_positivos = 0;
    int verdadeiros_negativos = 0;

    printf("\nVerificação de 1 a %d:\n", N);
    for (int i = 1; i <= N; i++) {
        int bloom_diz = verificar(i);
        int real       = eh_primo_real(i);

        if (!bloom_diz) {
            verdadeiros_negativos++; // bloom disse não → correto
        } else if (real) {
            verdadeiros_positivos++; // bloom disse sim e é primo
        } else {
            falsos_positivos++;      // bloom disse sim mas não é primo
        }
    }

    printf("Verdadeiros positivos: %d\n", verdadeiros_positivos);
    printf("Verdadeiros negativos: %d\n", verdadeiros_negativos);
    printf("Falsos positivos: %d\n", falsos_positivos);
    printf("Taxa FP real: %.2f%%\n",
           100.0 * falsos_positivos / (N - verdadeiros_positivos - falsos_positivos + falsos_positivos));
}
```

---

## Questão 20 — Análise: Crivo Tradicional vs Crivo + Bloom

### Para Números Primos

| Critério | Crivo Tradicional | Crivo + Bloom |
|---|---|---|
| Verificar se é primo | O(1) — acesso direto ao array | O(k) — k funções hash |
| Falsos positivos | Nenhum | Possível (≤ 1% neste caso) |
| Memória | 1 byte por número (ou 1 bit com otimização) | Muito menos bits |
| Precisão | 100% | 99% (com 1% FP) |

**Para primos: o crivo tradicional é mais eficiente.** O acesso ao array booleano é O(1) e sem falsos positivos.

### Para Números Não Primos

| Critério | Crivo Tradicional | Crivo + Bloom |
|---|---|---|
| Verificar se não é primo | O(1) | O(k), mas pode ter FP |
| Falso positivo (diz que é primo sendo composto) | Impossível | Ocorre em ~1% |
| Memória para N grande | Cresce linearmente | Cresce muito mais lentamente |

### Conclusão Geral

O **crivo de Eratóstenes tradicional** é superior em velocidade e precisão quando há memória suficiente. O **filtro de Bloom** é vantajoso apenas em cenários de memória extremamente restrita e quando falsos positivos são toleráveis (com um mecanismo de verificação secundária, como na Q19).

**Fórmula de custo comparativo:**
- Crivo: O(N log log N) para construção + O(1) por consulta
- Bloom: O(N_primos × k) para construção + O(k) por consulta + O(√x) para confirmação de positivos

---

## Questão 21 — Bloom com vetor de `unsigned int` + Análise de Little-Endian

### Inserção e Consulta

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N_MAX    2000000
#define K_FUNCS  5

// Tamanho do filtro: calculado para FP razoável
// Para ~148933 primos até 2.000.000 com k=5, FP≈1%:
// m ≈ 2.142.000 bits → 66.938 unsigned ints
#define M_BITS  2142976           // múltiplo de 32
#define VEC_SIZE (M_BITS / 32)    // 66.968 posições

unsigned int bloom[VEC_SIZE];

// Família de 5 funções hash
int hash_k(int x, int k) {
    int a[] = {2,  3,  5,  7,  11};
    int b[] = {3,  7, 11, 13,  17};
    long long val = (long long)a[k] * x + b[k];
    return (int)(val % M_BITS);
}

// ====== Inserção usando operações bit a bit ======
// Dado índice i produzido pela função hash:
// - Posição no vetor: i / 32  (ou i >> 5)
// - Deslocamento do bit: i % 32  (ou i & 31)
void bloom_inserir(int x) {
    for (int k = 0; k < K_FUNCS; k++) {
        int i         = hash_k(x, k);
        int vec_pos   = i / 32;      // qual unsigned int
        int bit_shift = i % 32;      // qual bit dentro dele
        bloom[vec_pos] |= (1u << bit_shift);
    }
}

// ====== Consulta usando operações bit a bit ======
int bloom_buscar(int x) {
    for (int k = 0; k < K_FUNCS; k++) {
        int i         = hash_k(x, k);
        int vec_pos   = i / 32;
        int bit_shift = i % 32;
        if (!((bloom[vec_pos] >> bit_shift) & 1u))
            return 0; // bit 0 → definitivamente ausente
    }
    return 1; // todos os bits 1 → provavelmente presente
}

// Crivo de Eratóstenes
void crivo(int N, char *eh_primo) {
    for (int i = 2; i <= N; i++) eh_primo[i] = 1;
    for (int i = 2; (long long)i * i <= N; i++)
        if (eh_primo[i])
            for (int j = i * i; j <= N; j += i)
                eh_primo[j] = 0;
}

int main() {
    char *primo = (char *)calloc(N_MAX + 1, 1);
    crivo(N_MAX, primo);

    memset(bloom, 0, sizeof(bloom));

    // Insere todos os primos no filtro
    int n_primos = 0;
    for (int i = 2; i <= N_MAX; i++) {
        if (primo[i]) {
            bloom_inserir(i);
            n_primos++;
        }
    }

    printf("Primos inseridos: %d\n", n_primos);
    printf("Tamanho do vetor: %d unsigned ints (%d bytes)\n",
           VEC_SIZE, VEC_SIZE * 4);

    // Testa alguns valores
    printf("\nTestes:\n");
    int testes[] = {2, 3, 7, 11, 13, 999983, 1000003, 4, 6, 100};
    for (int i = 0; i < 10; i++) {
        int x = testes[i];
        printf("  %d → bloom=%s, real=%s%s\n",
               x,
               bloom_buscar(x) ? "sim" : "não",
               primo[x] ? "primo" : "não primo",
               (bloom_buscar(x) && !primo[x]) ? " ← FALSO POSITIVO" : "");
    }

    free(primo);
    return 0;
}
```

### Análise: Little-Endian influencia o Filtro de Bloom?

**Resposta: NÃO influencia o funcionamento correto do filtro.**

**Justificativa detalhada:**

Em arquiteturas little-endian, o byte menos significativo de um `unsigned int` é armazenado no menor endereço de memória. Por exemplo, o valor `0x01020304` é armazenado como:

```
Endereço: [base+0] [base+1] [base+2] [base+3]
Valor:       0x04    0x03    0x02    0x01
```

Porém, quando usamos operações bit a bit em C (`>>`, `<<`, `&`, `|`), o compilador trata o `unsigned int` como um valor inteiro de 32 bits, e as operações se referem à **representação lógica** do número, não ao layout físico na memória.

Portanto:
- `bloom[i/32] |= (1u << (i%32))` sempre marca o mesmo bit lógico para um dado índice `i`
- `(bloom[i/32] >> (i%32)) & 1u` sempre lê o mesmo bit lógico

Como **marcamos e lemos com as mesmas operações**, a consistência é mantida independente da arquitetura. O little-endian só seria um problema se:
- Serializássemos o filtro para arquivo e o lêssemos em uma arquitetura big-endian
- Tentássemos acessar os bits através de ponteiros `char *` para interpretar a memória física diretamente

**Conclusão:** Para um filtro de Bloom puramente em memória com operações bit a bit em C, o little-endian **não afeta a correção** da implementação.

---

# Gabarito — Códigos para a Prova
> Tente escrever cada código sem olhar. Se travar, aí consulta.

---

## Q1 — Vantagens da Tabela Hash em relação às Árvores

* **Complexidade de Tempo**: As tabelas hash oferecem busca, inserção e remoção em tempo constante médio, isto é, $O(1)$, enquanto as árvores de busca balanceadas (como AVL ou Rubro-Negra) demandam tempo logarítmico, $O(\log n)$.
* **Simplicidade de Implementação**: O acesso direto via índices calculados por uma função de dispersão dispensa o manejo complexo de ponteiros e rebalanceamentos estruturais frequentes exigidos pelas árvores estruturadas.
* **Eficiência para Grandes Volumes**: Quando o fator de carga é controlado e as chaves não exigem ordenação, as tabelas tratam volumetrias massivas de dados com menor custo computacional por operação.

---

## Q2 — Complexidades Esperadas para uma Tabela Hash

As complexidades dependem diretamente da qualidade da função hash e do fator de carga da tabela:

* **Caso Médio (Esperado)**:
  * **Inserção**: $O(1)$
  * **Busca**: $O(1)$
  * **Remoção**: $O(1)$
* **Pior Caso** (quando todas as chaves colidem no mesmo índice):
  * **Inserção / Busca / Remoção**: $O(n)$ se for usado encadeamento ou se a tabela estiver cheia em endereçamento aberto.

---

## Q3 — Resolução Analítica de Inserções (M = 13)

Chaves a inserir: `18, 41, 22, 44, 59, 32, 31, 73, 85`

### a) Função $h(X) = X \pmod{13}$
* $18 \pmod{13} = 5$
* $41 \pmod{13} = 2$
* $22 \pmod{13} = 9$
* $44 \pmod{13} = 5$ → *Colisão!* (Sondagem linear resolve na próx. posição vaga)
* $59 \pmod{13} = 7$
* $32 \pmod{13} = 6$
* $31 \pmod{13} = 5$ → *Colisão!*
* $73 \pmod{13} = 8$
* $85 \pmod{13} = 7$ → *Colisão!*

**Tabela Resultante (Sondagem Linear):**
| Índice | Elemento | Justificativa / Resolução de Colisão |
| :---: | :---: | :--- |
| **0** | — | Vazio |
| **1** | — | Vazio |
| **2** | **41** | Direto ($41 \pmod{13} = 2$) |
| **3** | — | Vazio |
| **4** | — | Vazio |
| **5** | **18** | Direto ($18 \pmod{13} = 5$) |
| **6** | **44** | Colide no 5, ocupa o próximo livre (6). $32 \pmod{13} = 6$ colide aqui e vai para o 10. |
| **7** | **59** | Direto ($59 \pmod{13} = 7$) |
| **8** | **73** | Direto ($73 \pmod{13} = 8$) |
| **9** | **22** | Direto ($22 \pmod{13} = 9$) |
| **10** | **32** | Colide no 6, pula sequencialmente até achar vaga no 10. |
| **11** | **31** | Colide no 5, pula sequencialmente até achar vaga no 11. |
| **12** | **85** | Colide no 7, pula sequencialmente até achar vaga no 12. |

### b) e c) Função $h(X) = (3X + 11) \pmod{13}$
* **18**: $(3 \times 18 + 11) \pmod{13} = (54 + 11) \pmod{13} = 65 \pmod{13} = 0$
* **41**: $(3 \times 41 + 11) \pmod{13} = (123 + 11) \pmod{13} = 134 \pmod{13} = 4$
* **22**: $(3 \times 22 + 11) \pmod{13} = (66 + 11) \pmod{13} = 77 \pmod{13} = 12$
* **44**: $(3 \times 44 + 11) \pmod{13} = (132 + 11) \pmod{13} = 143 \pmod{13} = 0$ → *Colisão!* (Ocupa o índice 1)
* **59**: $(3 \times 59 + 11) \pmod{13} = (177 + 11) \pmod{13} = 188 \pmod{13} = 6$
* **32**: $(3 \times 32 + 11) \pmod{13} = (96 + 11) \pmod{13} = 107 \pmod{13} = 3$
* **31**: $(3 \times 31 + 11) \pmod{13} = (93 + 11) \pmod{13} = 104 \pmod{13} = 0$ → *Colisão!* (Ocupa o índice 2)
* **73**: $(3 \times 73 + 11) \pmod{13} = (219 + 11) \pmod{13} = 230 \pmod{13} = 9$
* **85**: $(3 \times 85 + 11) \pmod{13} = (255 + 11) \pmod{13} = 266 \pmod{13} = 6$ → *Colisão!* (Ocupa o índice 7)

**Tabela Resultante (Sondagem Linear):**
| Índice | Elemento | Justificativa / Resolução de Colisão |
| :---: | :---: | :--- |
| **0** | **18** | Direto |
| **1** | **44** | Colide no 0, pega o próximo livre (1) |
| **2** | **31** | Colide no 0, pula 1 (ocupado), pega o 2 |
| **3** | **32** | Direto |
| **4** | **41** | Direto |
| **5** | — | Vazio |
| **6** | **59** | Direto |
| **7** | **85** | Colide no 6, pega o próximo livre (7) |
| **8** | — | Vazio |
| **9** | **73** | Direto |
| **10** | — | Vazio |
| **11** | — | Vazio |
| **12** | **22** | Direto |

---

## Q4 — Conceitos de Tratamento de Colisões

* **a) Sondagem Linear**: Método de endereçamento aberto onde, ocorrendo colisão no índice $pos$, procura-se sequencialmente nas posições imediatamente seguintes: $(pos + i) \pmod M$ para $i = 1, 2, 3...$
* **b) Sondagem Quadrática**: Para evitar o agrupamento primário da sondagem linear, o incremento avança de forma quadrática: $(pos + c_1 \cdot i + c_2 \cdot i^2) \pmod M$. Isso espalha as chaves colisoras de forma mais ampla pela tabela.
* **c) Duplo Hash**: Utiliza uma segunda função hash indestrutível ($h_2(X)$) para computar o intervalo de salto. A posição candidata torna-se $(h_1(X) + i \cdot h_2(X)) \pmod M$. Cada chave gera sua própria sequência de saltos, minimizando agrupamentos.

---

## Q5 — Hash de Placas

```c
#include <stdio.h>

/* Placa nova: ABC1D23
   Raciocínio: trate como número em base mista
   letra=26 possibilidades, dígito=10 possibilidades */

long long placaParaNumero(char p[8]) {
    long long n = 0;
    n = n * 26 + (p[0]-'A');  // letra
    n = n * 26 + (p[1]-'A');  // letra
    n = n * 26 + (p[2]-'A');  // letra
    n = n * 10 + (p[3]-'0');  // dígito
    n = n * 26 + (p[4]-'A');  // letra
    n = n * 10 + (p[5]-'0');  // dígito
    n = n * 10 + (p[6]-'0');  // dígito
    return n + 1; // começa em 1
}

// 25% de 456.976.000 = 114.244.000
int hash25(char p[8]) { return (int)(placaParaNumero(p) % 114244000); }

/* Placa antiga: ABC1234
   Total = 26^3 * 10^4 = 175.760.000
   12,5% = 21.970.000 */

long long placaAntigaParaNumero(char p[8]) {
    long long n = 0;
    n = n * 26 + (p[0]-'A');
    n = n * 26 + (p[1]-'A');
    n = n * 26 + (p[2]-'A');
    n = n * 10 + (p[3]-'0');
    n = n * 10 + (p[4]-'0');
    n = n * 10 + (p[5]-'0');
    n = n * 10 + (p[6]-'0');
    return n + 1;
}

int hash125(char p[8]) { return (int)(placaAntigaParaNumero(p) % 21970000); }
```
---

## Q6 — Simulação de Colisões

```c
#include <stdio.h>
#include <stdlib.h>

void simular(int m) {
    int *tab = calloc(m, sizeof(int));
    srand(42);

    // Preenche 30% da tabela
    int ocup = (int)(0.3 * m), ins = 0;
    while (ins < ocup) {
        int p = rand() % m;
        if (!tab[p]) { tab[p] = 1; ins++; }
    }

    // Tenta inserir 5% a mais — se colidir, não insere
    int tentativas = (int)(0.05 * m), col = 0, novos = 0;
    for (int i = 0; i < tentativas; i++) {
        int p = rand() % m;
        if (tab[p]) col++;
        else { tab[p] = 1; novos++; }
    }

    printf("Colisoes: %.1f%% | Fator final: %.1f%%\n",
           (double)col / tentativas * 100,
           (double)(ocup + novos) / m * 100);
    free(tab);
}

int main() { simular(10000); return 0; }
// Resultado esperado: ~30% de colisões, fator final ~33-34%
```
---

## Q7 — Vantagens e desvantagens dos tratamentos

| Técnica | Vantagem | Desvantagem |
|---|---|---|
| Sondagem linear | Simples e rápida | Agrupamento primário |
| Sondagem quadrática | Menos agrupamento | Pode não percorrer toda tabela |
| Duplo Hash | Boa distribuição | Mais cálculos |
| Encadeamento | Não limita muito a tabela | Usa memória extra |

---

---

## Q8 — Sondagem Linear (100 posições)

```c
#include <stdio.h>
#define TAM      100
#define VAZIO    -1
#define DELETADO -2

int tabela[TAM];

void init() {
    for (int i = 0; i < TAM; i++) tabela[i] = VAZIO;
}

int hash(int x) { return x % TAM; }

/* ---------- sA: sem circular ---------- */

int inserirSA(int val) {
    int pos = hash(val);
    for (int i = pos; i < TAM; i++) {
        if (tabela[i] == VAZIO || tabela[i] == DELETADO) {
            tabela[i] = val; return i;
        }
    }
    return -1; // sem vaga
}

int buscarSA(int val) {
    int pos = hash(val);
    for (int i = pos; i < TAM; i++) {
        if (tabela[i] == val)    return i;
        if (tabela[i] == VAZIO) return -1; // não há mais candidatos
    }
    return -1;
}

int removerSA(int val) {
    int pos = buscarSA(val);
    if (pos != -1) tabela[pos] = DELETADO; // tombstone — nunca apague diretamente
    return pos;
}

/* ---------- sB: com circular ---------- */

int inserirSB(int val) {
    int pos = hash(val), i = pos;
    do {
        if (tabela[i] == VAZIO || tabela[i] == DELETADO) {
            tabela[i] = val; return i;
        }
        i = (i + 1) % TAM;
    } while (i != pos); // parou quando voltou à origem
    return -1; // tabela cheia
}

int buscarSB(int val) {
    int pos = hash(val), i = pos;
    do {
        if (tabela[i] == val)    return i;
        if (tabela[i] == VAZIO) return -1;
        i = (i + 1) % TAM;
    } while (i != pos);
    return -1;
}

int removerSB(int val) {
    int pos = buscarSB(val);
    if (pos != -1) tabela[pos] = DELETADO;
    return pos;
}
```

---

## Q9 — Sondagem Quadrática (100 posições)

Estrutura idêntica ao Q8. **Só muda o incremento:** usa `i*i` em vez de `i`.

```c
#include <stdio.h>
#define TAM      100
#define VAZIO    -1
#define DELETADO -2

int tabela[TAM];

void init() {
    for (int i = 0; i < TAM; i++) tabela[i] = VAZIO;
}

int hash(int x) { return x % TAM; }

/* ---------- sA: quadrática sem circular ---------- */

int inserirQuadSA(int val) {
    int pos = hash(val);
    for (int i = 0; i < TAM; i++) {
        int t = pos + i * i;
        if (t >= TAM) break;           // sA para no final, sem reiniciar
        if (tabela[t] == VAZIO || tabela[t] == DELETADO) {
            tabela[t] = val; return t;
        }
    }
    return -1;
}

int buscarQuadSA(int val) {
    int pos = hash(val);
    for (int i = 0; i < TAM; i++) {
        int t = pos + i * i;
        if (t >= TAM) break;
        if (tabela[t] == val)    return t;
        if (tabela[t] == VAZIO) return -1;
    }
    return -1;
}

/* ---------- sB: quadrática com circular ---------- */

int inserirQuadSB(int val) {
    int pos = hash(val);
    for (int i = 0; i < TAM; i++) {
        int t = (pos + i * i) % TAM;   // % TAM garante circular
        if (tabela[t] == VAZIO || tabela[t] == DELETADO) {
            tabela[t] = val; return t;
        }
    }
    return -1;
}

int buscarQuadSB(int val) {
    int pos = hash(val);
    for (int i = 0; i < TAM; i++) {
        int t = (pos + i * i) % TAM;
        if (tabela[t] == val)    return t;
        if (tabela[t] == VAZIO) return -1;
    }
    return -1;
}

int removerQuad(int val) {          // igual para sA e sB, só chama o buscar certo
    int pos = buscarQuadSB(val);
    if (pos != -1) tabela[pos] = DELETADO;
    return pos;
}
```

---

## Q10 — Encadeamento com Lista Ligada

```c
#include <stdio.h>
#include <stdlib.h>
#define TAM 100

typedef struct No {
    int val;
    struct No *prox;
} No;

No *tabela[TAM];

void init() {
    for (int i = 0; i < TAM; i++) tabela[i] = NULL;
}

int hash(int x) { return x % TAM; }

void inserir(int val) {
    int idx = hash(val);
    No *novo = malloc(sizeof(No));
    novo->val  = val;
    novo->prox = tabela[idx]; // insere no início da lista
    tabela[idx] = novo;
}

No *buscar(int val) {
    No *p = tabela[hash(val)];
    while (p) {
        if (p->val == val) return p;
        p = p->prox;
    }
    return NULL;
}
```

---

## Q11 — Gerar funções h(x) = (ax+b) % K com a, b primos

```c
#include <stdio.h>
#include <math.h>

int ehPrimo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= (int)sqrt(n); i++)
        if (n % i == 0) return 0;
    return 1;
}

void gerarHashes(int K, int qtd) {
    int primos[200], np = 0, num = 2;
    while (np < qtd * 2)
        if (ehPrimo(num++)) primos[np++] = num - 1;

    for (int i = 0; i < qtd; i++)
        printf("h%d(x) = (%d*x + %d) %% %d\n",
               i+1, primos[i], primos[qtd+i], K);
}

int main() { gerarHashes(128, 5); return 0; }
```

---

## Q12 — Verificar se hash cobre todas as K posições

```c
// h(x) = (ax+b) % K cobre TODAS as posições se e somente se mdc(a, K) == 1

int mdc(int a, int b) {
    while (b) { int t = b; b = a % b; a = t; }
    return a;
}

void verificarCobertura(int K, int qtd, int a[]) {
    for (int i = 0; i < qtd; i++) {
        if (mdc(a[i], K) == 1)
            printf("h%d (a=%d): cobre tudo ✓\n", i+1, a[i]);
        else
            printf("h%d (a=%d): NAO cobre tudo (mdc=%d) ✗\n", i+1, a[i], mdc(a[i],K));
    }
}
```

---

## Q13 — Tempo para ocupar 50% dos bits

```c
#include <stdlib.h>
#include <stdio.h>

int tempoPara50pct(int K, int qtd, int a[], int b[]) {
    int *f = calloc(K, sizeof(int));
    int setados = 0, meta = K / 2, elem = 0;
    while (setados < meta) {
        for (int i = 0; i < qtd; i++) {
            int pos = (a[i] * elem + b[i]) % K;
            if (!f[pos]) { f[pos] = 1; setados++; }
        }
        elem++;
    }
    free(f);
    return elem;
}

int main() {
    int a[] = {3, 5, 7, 11, 13};
    int b[] = {17, 19, 23, 29, 31};
    printf("Elementos para 50%%: %d\n", tempoPara50pct(128, 5, a, b));
    return 0;
}
```

---

## Q14 — Selecionar bit no filtro de 16 bytes

```c
#include <stdio.h>

// h(x) = (3x + 7), filtro: unsigned char[16] = 128 bits

void setBit(unsigned char filtro[16], int x) {
    int idx  = (3 * x + 7) % 128;
    filtro[idx/8] |= (1 << (idx%8));
}

int getBit(unsigned char filtro[16], int x) {
    int idx = (3 * x + 7) % 128;
    return (filtro[idx/8] >> (idx%8)) & 1;
}

int main() {
    unsigned char filtro[16] = {0};
    setBit(filtro, 10); // índice=37, byte=4, bit=5
    printf("x=10 presente: %d\n", getBit(filtro, 10)); // 1
    printf("x=5  presente: %d\n", getBit(filtro, 5));  // 0
    return 0;
}
```

---

## Q15 — Filtro Bloom com 1024 bytes

Dados:

- Tamanho do filtro: 1024 bytes
- 1 byte possui 8 bits

Então:

```
1024 × 8 = 8192 bits
```

A taxa de falso positivo de um filtro Bloom é:

$$
p \approx \left(1 - e^{-\frac{kn}{m}}\right)^k
$$

Onde:

- `p` = taxa de falso positivo;
- `k` = quantidade de funções hash;
- `n` = quantidade de elementos inseridos;
- `m` = quantidade de bits do filtro.

O número ótimo de funções hash é:

$$
k = \frac{m}{n}\ln(2)
$$

Desejamos aproximadamente 95% de certeza dos verdadeiros positivos, então:

```
taxa de falso positivo = 5%
```

Com:

```
m = 8192 bits
```

A quantidade aproximada de elementos suportados é:

```
n ≈ 570 elementos
```

Portanto:

Um filtro Bloom com **1024 bytes consegue armazenar aproximadamente 570 elementos** mantendo uma taxa de falso positivo próxima de 5%.

Isso significa que ele possui aproximadamente **95% de confiabilidade nas consultas**.







---

## Q16/Q17 — Filtro de Bloom completo

```c
#include <stdio.h>
#include <string.h>

#define M_BITS  1300        // calculado no README para Pfp < 2%, n=128, k=3
#define M_BYTES ((M_BITS+7)/8)
#define K       3

unsigned char filtro[M_BYTES];

int ha[] = {3, 5, 7};
int hb[] = {11, 13, 17};

int aplicarHash(int i, int x) { return (ha[i]*x + hb[i]) % M_BITS; }

void setBit(int pos) { filtro[pos/8] |=  (1 << (pos%8)); }
int  getBit(int pos) { return (filtro[pos/8] >> (pos%8)) & 1; }

void inserir(int x) {
    for (int i = 0; i < K; i++) setBit(aplicarHash(i, x));
}

// Q17 — busca: retorna 1=provavelmente presente, 0=certamente ausente
int buscar(int x) {
    for (int i = 0; i < K; i++)
        if (!getBit(aplicarHash(i, x))) return 0;
    return 1;
}

int main() {
    memset(filtro, 0, sizeof(filtro));
    inserir(42); inserir(7); inserir(100);
    printf("42: %s\n", buscar(42) ? "presente" : "ausente"); // presente
    printf("99: %s\n", buscar(99) ? "presente" : "ausente"); // ausente
    return 0;
}
```

---

## Q18/Q19 — Filtro com primos (Crivo + Bloom, 5 hashes, Pfp < 1%)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N      10000
// ~1229 primos até 10000. m = -(1229*ln(0.01))/0.4805 ≈ 11777 bits
#define M_BITS 12000
#define M_BYTES ((M_BITS+7)/8)
#define K      5

int ha[] = {3,  5,  7, 11, 13};
int hb[] = {17, 19, 23, 29, 31};
unsigned char filtro[M_BYTES];

int aplicarHash(int i, int x) { return (ha[i]*x + hb[i]) % M_BITS; }
void setBit(int p) { filtro[p/8] |=  (1 << (p%8)); }
int  getBit(int p) { return (filtro[p/8] >> (p%8)) & 1; }

void inserir(int x) {
    for (int i = 0; i < K; i++) setBit(aplicarHash(i, x));
}

int consultarFiltro(int x) {
    for (int i = 0; i < K; i++)
        if (!getBit(aplicarHash(i, x))) return 0;
    return 1;
}

// Q19: verificação real para confirmar o que o filtro diz
int ehPrimoReal(int x) {
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return 0;
    return 1;
}

int main() {
    memset(filtro, 0, sizeof(filtro));

    // Crivo de Eratóstenes — gera os primos
    char *crivo = calloc(N+1, 1);
    memset(crivo, 1, N+1);
    crivo[0] = crivo[1] = 0;
    for (int i = 2; i*i <= N; i++)
        if (crivo[i])
            for (int j = i*i; j <= N; j += i)
                crivo[j] = 0;

    // Q18 — insere primos no filtro
    for (int i = 2; i <= N; i++)
        if (crivo[i]) inserir(i);

    // Q19 — busca com confirmação para números de 1 a 30
    for (int x = 1; x <= 30; x++) {
        if (!consultarFiltro(x))
            printf("%2d: certamente NAO e primo\n", x);
        else if (ehPrimoReal(x))
            printf("%2d: e primo ✓\n", x);
        else
            printf("%2d: falso positivo do filtro\n", x);
    }

    free(crivo);
    return 0;
}
```

---

## Q20 — Análise de Eficiência: Crivo Tradicional vs Filtro de Bloom:
- **Elementos Não-Primos:** O filtro de Bloom é extremamente eficiente aqui. Como ele dá certezas absolutas para ausências ($0$ na busca), qualquer número composto que retornar $0$ é descartado instantaneamente, sem a necessidade de acessar posições aleatórias de memória de tabelas grandes ou de executar divisões custosas.
- **Elementos Primos:** O Crivo tradicional é mais rápido no acesso direto após construído ($O(1)$ por flag booleana direta), enquanto o filtro de Bloom exige computar $k$ funções hash para confirmar a provável primalidade e, caso o faça, realizar um teste determinístico adicional de primalidade para descartar eventuais falsos positivos.
- **Conclusão de Espaço:** O filtro de Bloom brilha ao salvar espaço em memória volátil/disco para conjuntos massivos de dados, porém adiciona sobrecarga computacional de hashing nas consultas positivas.


---

## Q21 — Bloom com `unsigned int` (32 bits por posição) + Crivo até 2.000.000

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N      2000000
// ~148933 primos até 2M. m = -(148933*ln(0.01))/0.4805 ≈ 1.43M bits
#define M_BITS 1430000
#define M_UINT ((M_BITS + 31) / 32)  // quantos unsigned ints precisamos
#define K      5

int ha[] = {3,  5,  7, 11, 13};
int hb[] = {17, 19, 23, 29, 31};
unsigned int filtro[M_UINT];

int aplicarHash(int i, int x) { return (ha[i]*x + hb[i]) % M_BITS; }

// posição no vetor = índice / 32
// bit dentro do elemento = índice % 32
void setBit(int idx) {
    filtro[idx / 32] |=  (1u << (idx % 32));
}

int getBit(int idx) {
    return (filtro[idx / 32] >> (idx % 32)) & 1u;
}

void inserir(int x) {
    for (int i = 0; i < K; i++) setBit(aplicarHash(i, x));
}

int consultar(int x) {
    for (int i = 0; i < K; i++)
        if (!getBit(aplicarHash(i, x))) return 0;
    return 1;
}

int main() {
    memset(filtro, 0, sizeof(filtro));

    // Crivo de Eratóstenes
    char *crivo = calloc(N+1, 1);
    memset(crivo, 1, N+1);
    crivo[0] = crivo[1] = 0;
    for (int i = 2; (long long)i*i <= N; i++)
        if (crivo[i])
            for (int j = i*i; j <= N; j += i)
                crivo[j] = 0;

    // Insere primos no filtro
    for (int i = 2; i <= N; i++)
        if (crivo[i]) inserir(i);

    printf("2 primo? %s\n", consultar(2) ? "sim" : "nao");
    printf("4 primo? %s\n", consultar(4) ? "sim (FP?)" : "nao");

    free(crivo);
    return 0;
}

/*
LITTLE-ENDIAN:
Não influencia. >> << | & operam na representação lógica do inteiro,
igual em qualquer arquitetura. Só seria problema ao salvar o filtro
em arquivo e ler em máquina com endianness diferente.
*/
```
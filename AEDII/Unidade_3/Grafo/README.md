# GRAFOS

Um **grafo** G é formado por:

- um conjunto **não vazio** V de vértices (ou nós)
- um conjunto A de pares **não ordenados** de elementos de V, chamados de arestas

Ou seja:

G = (V, A)

---

## Exemplos

### A)
V = {v1, v2, v3, v4, v5}
A = {(v1, v2), (v1, v3), (v2, v4), (v3, v5)}

---

### B)
V = {1, 2, 3, 4, 5}
A = {(i, j) | i = j + 2}

Ou seja:
A = {(1,3), (2,4), (3,5)}

---

### C)
V = {1, 2, 3, 4}
A = {(1,2), (1,3), (2,3), (2,2), (4,4)}

Observação:
- (2,2) e (4,4) são loops

---

### D)
V = {1, 2, 3, 4, 5}
A = {} (grafo sem arestas)

---

## Definição 01: Ordem e tamanho

- Número de vértices: |V|
- Número de arestas: |A|

### Exemplo (A)

|V| = 5
|A| = 4

---

## Aplicação: Copa do Mundo

Cada grupo tem 4 seleções, e todas jogam entre si.

Número de jogos em um grupo:
6 jogos

Como são 16 grupos:

16 × 6 = 96 jogos

---

## Definição 02: Conceitos básicos

- Se (x, y) é uma aresta:
  - x e y são **extremidades**

- Se um vértice está ligado a uma aresta:
  - ele é **incidente**

- Se dois vértices compartilham uma aresta:
  - são **adjacentes**

- Se são adjacentes:
  - são **vizinhos**

- Conjunto dos vizinhos de x:
  - N(x)

- Se não são adjacentes:
  - são **independentes**

- Se um vértice não possui arestas:
  - é **isolado**

- Se uma aresta liga um vértice a ele mesmo:
  - é um **loop**

- Se existem várias arestas entre dois vértices:
  - são **multi-arestas**

---

## Definição 03: Grafo simples

Um grafo é **simples** quando:

- não possui loops
- não possui multi-arestas

---

## Definição 04: Grau de um vértice

O grau de um vértice v, denotado por d(v), é o número de arestas incidentes a ele.

IMPORTANTE:
- um loop conta como 2 no grau

---

### Exemplo

V = {a, b, c, d, e, f}
A = {(a,d), (a,c), (b,f), (c,d), (c,e), (c,f)}

#### b) O grafo é simples?
Sim, pois não possui loops nem multi-arestas.

#### c) Grau dos vértices

d(a) = 2
d(b) = 1
d(c) = 4
d(d) = 2
d(e) = 1
d(f) = 2

---

## Teorema

A soma dos graus de todos os vértices é sempre par.

---

## Corolário

O número de vértices de grau ímpar é sempre par.

---

## Definição 05: Subgrafo

Um subgrafo H de G é tal que:

- V(H) ⊆ V(G)
- A(H) ⊆ A(G)

E:
se (x, y) ∈ A(H), então x e y pertencem a V(H)

---

## Definição 06: Grafo k-regular

Um grafo é k-regular quando:

- todos os vértices têm o mesmo grau k

Ou seja:

d(v) = k para todo v em V

---

# Resumo rápido

- G = (V, A)
- Simples: sem loops e sem multi-arestas
- Grau: número de arestas incidentes
- Soma dos graus: sempre par
- Subgrafo: parte de outro grafo
- k-regular: todos os vértices com mesmo grau
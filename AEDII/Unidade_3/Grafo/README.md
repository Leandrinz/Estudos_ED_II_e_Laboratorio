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

## Definição 07:
Um grafo simples G é dito **completo** se para cada par de vértice de G, existe uma aresta que os conectam. Denomina-se Kn.

![alt text](image.png)

### Propriedades de um Kn:
  - Todos os vértices de um Kn tem grau (n-1)
  - Kn tem a maior quantidade de arestas de um grafo simples com n vértices.
  - Kn possui exatamente:
    - ||Kn|| = N(N - 1) / 2 Arestas
  - Propriedade de Grafos:

## Representação de Grafos

## Definição 8:
A **Matriz de Adjacência** M(G) é uma matriz n x n na qual o vértice Vj, é representado pela coluna j, e os elementos Mij representam a quantidade de arestas que conectam o vértice Vi ao Vj.

### Exemplo:

![alt text](image-1.png)

### Percusos Distintos (Aplicação Direta):
Considere M a matriz de adjacência de um grafo G. Então M², M³, M^4 ... M^k representam, em seus elementos, a quantidade distinta de percursos entre quaisquer dois vértices com 2, 3, 4, ... k passos.

Exemplo:

![alt text](image-2.png)

## Definição 09:
**Dígrafo**:
  Um Grafo orientado, ou **dígrafo**, representado por G = (V, A) com V sendo um conjunto não vazio de vértices e A um conjunto de Arestas orientadas.

Exemplo:

![alt text](image-3.png)

## Definição 10:
a) O grau de emissão de vi é a quantidade de Arestas que **saem** de vi

b) O grau de recepção Dr(vi) é a quantidade de arestas que **chegam** de vi

c) Um vértice **sumidouro** vi é um vértice com de(vi) = ∅

d) Um vértice **fonte** vi é um vértice com dr(vi) = ∅

Exemplo:

![alt text](image-4.png)

### Representação:
Representado por M(c) como sendo a matriz de elementos Aij que associa a cada vértice i (emissos) com o vértice j (receptor) com o incremento (Aij). O elemento Aij recebe o valor de ∅

![alt text](image-5.png)

## Definição 11:
  Um **grafo valorado** G(V,A,w) é um grafo no qual cada aresta tem um número associado. Estes números são representados por w(vi, vj)

Exemplo:
Desenhe um grafo que representa as possibilidades de resultados em três lançamentos de uma moeda:

![alt text](image-6.png)

## Definição 12:
Dado um grafo simples G = (V,A) Um grafo complementar de G é dado como Ḡ = (V,Ã), no qual se (x,y) pertence a A, (x,y) não pertencem a Ã e vice versa

Exemplo:
![alt text](image-7.png)

Consequência:
> Dado G = (V,A), Ḡ = (V,Ã) com |V| = N, H = (V, A U Ã) = Kn

## Definição 13:
Um grafo G é **bipartido** se, e somente se, o conjunto dos vértices V podem ser separados em dois conjuntos disjuntos V1 e V2 de tal forma que todas as Arestas tenham uma terminação em V1 e a outra em V2

Exemplos:

![alt text](image-10.png)

# Isomorfismo

## Definição 14:
Dizemos que dois grafos G e H são isomorfos entre si se existem uma correspondência BIUNÍVOCA entre os vértices de G e H no qual sejam preservadas as relações de adjacência entre os vértices e arestas

Exemplo:

![alt text](image-9.png)

## Definição 14 (alternativa):
Dois grafos G e H são exemplos, denotados por G ≡ H, se existir uma função bijetora f:V(G) -> V(H) de tal forma que (x,y) ∈ A(G) se, e somente se:

`(f(x), f(y)) ∈ A(H)`

### Condições para que dois grafos sejam isomorfos

Dois grafos são isomorfos quando possuem a mesma estrutura de conexões, mesmo que seus vértices tenham nomes ou posições diferentes.

Para isso, devem ter:

- O mesmo número de vértices;
- O mesmo número de arestas;
- A mesma sequência de graus dos vértices;
- Uma correspondência entre os vértices que preserve as arestas.

### Exemplo

Grafo A:
- Vértices: {1, 2, 3}
- Arestas: {1-2, 2-3}

Grafo B:
- Vértices: {A, B, C}
- Arestas: {A-B, B-C}

São isomorfos pois 1→A, 2→B e 3→C mantém as mesmas ligações.

# Algumas definições

## K-Coloração:
Uma k-coloração de vértices é uma associação f: Vg -> C do conjunto de vértices do grafo G a um conjunto C = {1,2,...,k} tal que seus elementos são chamados de cores

## Grafo K-Colorido:
Um Grafo é dito K-colorido se os nós associados às extremidades de cada arestas possuem cores diferentes

## Número cromático:
Representado por X(G), corresponde ao menor número de cores necessária à coloração do grafo

#### Exemplo:

![alt text](image-11.png)

## Coloração de mapas:

![alt text](image-12.png)

### Problemas de coloração de mapas:

![alt text](image-13.png)

## Árvore de Extensão mínima:
**Problema**: A partir de um grafo não orientado, gerar um subgrafo que conecta todos os vértices
**Subproblema**: Determinar, em um grafo com pesos nas arestas, a menor árvore de extensão mínima

![alt text](image-14.png)

## Problema do fluxo máximo:
- Rede elétrica
- Transporte de fluidos
- Distribuição de produtos

![alt text](image-15.png)
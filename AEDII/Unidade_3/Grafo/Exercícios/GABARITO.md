#  Gabarito — Lista de Exercícios: Teoria dos Grafos
> **Algoritmos e Estruturas de Dados II**
> Use este gabarito APÓS tentar resolver cada questão.

---

## Bloco 1 — Conceitos Fundamentais e Representação

### Q1 — Grafos válidos

**a)** ✅ **Válido.** V não vazio, e todas as arestas conectam vértices existentes em V.

**b)** ❌ **Inválido.** V deve ser **não vazio** por definição.

**c)** ✅ **Válido.** V = {a} é não vazio. `(a,a)` é um loop — permitido (o grafo não é simples, mas ainda é um grafo).

**d)** ❌ **Inválido.** A aresta `(1,3)` referencia o vértice `3`, que não pertence a `V = {1,2}`.

---

### Q2 — Aplicações da Teoria dos Grafos

Exemplos esperados (qualquer 5 com vértices/arestas bem definidos):

| Situação | Vértices | Arestas |
|----------|----------|---------|
| Redes sociais | Pessoas | Amizades |
| Roteamento na internet | Roteadores/servidores | Cabos/conexões |
| Mapas e GPS | Cidades/cruzamentos | Estradas |
| Circuitos elétricos | Componentes | Fios |
| Dependências de tarefas | Tarefas | "A depende de B" |
| Copa do Mundo | Seleções | Jogos entre si |
| Distribuição de produtos | Depósitos/lojas | Rotas |

---

### Q3 — Grafo com loops e multi-arestas

**A(G) = {(a,b), (a,e), (b,c), (c,c), (d,e), (e,d)}**

**b)** ❌ **Não é simples.** Possui:
- `(c,c)` → loop em c
- `(d,e)` e `(e,d)` → multi-aresta entre d e e (pares não ordenados são o mesmo)

**c) Graus:**

| Vértice | Cálculo | Grau |
|---------|---------|------|
| a | arestas (a,b) e (a,e) | 2 |
| b | arestas (a,b) e (b,c) | 2 |
| c | aresta (b,c) + loop (c,c) conta 2 | 3 |
| d | multi-aresta (d,e) conta 2 vezes | 2 |
| e | (a,e) + multi-aresta (d,e) conta 2 | 3 |
| f | nenhuma aresta | 0 |

> ⚠️ Loop conta como 2. Multi-aresta (d,e)/(e,d) = 1 aresta, mas contribui 1 para cada extremidade.

**d)** Arestas incidentes a `b`: `(a,b)` e `(b,c)`

**e)** Vizinhos de `a`: `{b, e}`

**f) Matriz de Adjacência** (vértices: a, b, c, d, e, f):

```
  a  b  c  d  e  f
a[0, 1, 0, 0, 1, 0]
b[1, 0, 1, 0, 0, 0]
c[0, 1, 2, 0, 0, 0]   ← diagonal 2 por causa do loop
d[0, 0, 0, 0, 2, 0]   ← 2 por causa da multi-aresta (d,e)/(e,d)
e[1, 0, 0, 2, 0, 0]
f[0, 0, 0, 0, 0, 0]
```

---

### Q4 — Grafos das matrizes

**M₁** — 4 vértices {1,2,3,4}:
- Multi-aresta entre 1-2 (valor 2), aresta 1-4, aresta 2-3, loop em 3 (diagonal=1), arestas 3-4

**M₂** — 4 vértices {1,2,3,4}:
- Multi-aresta 1-3 (valor 2), arestas 1-2, 1-4, 2-3, loop em 2 (diagonal=2)

**M₄** — 5 vértices {1,2,3,4,5}:
- Ciclo: 1-2, 2-3, 3-4, 4-5, 5-1 → **C₅** (pentágono/ciclo de 5 vértices)

> M₄ é grafo 2-regular (todo vértice tem grau 2), o que confirma o ciclo C₅.

---

### Q5 — Verdadeiro ou Falso

**a)** ✅ **Verdadeiro.** Teorema (Lema do Aperto de Mão): cada aresta contribui 2 para a soma total de graus.

**b)** ✅ **Verdadeiro.** Soma dos graus = 3+3+3+2+2 = 13 — **FALSO**, isso seria ímpar! Lema do Aperto de Mão exige soma par. Portanto este grafo **não pode existir** → resposta: **Falso**, esse grafo é impossível.

**c)** ❌ **Falso.** Se todos os vértices têm grau zero, não há arestas. O grau zero significa ausência de incidência.

**d)** ✅ **Verdadeiro.** Um loop `(v,v)` é contado como entrando e saindo do mesmo vértice, somando 2 ao grau de `v`.

**e)** ✅ **Verdadeiro.** Soma dos graus = `k × |V|`. Como cada aresta é contada duas vezes, `|A| = k × |V| / 2`.

---

## Bloco 2 — Grafos Especiais

### Q6 — Grafos Completos

**a) K₃ (triângulo):**
- Grau de cada vértice: 2
- Total de arestas: `3×2/2 = 3`
- Matriz:
```
[0,1,1]
[1,0,1]
[1,1,0]
```

**b) K₄:**
- Grau de cada vértice: 3
- Total de arestas: `4×3/2 = 6`
- Matriz:
```
[0,1,1,1]
[1,0,1,1]
[1,1,0,1]
[1,1,1,0]
```

**c) K₅:**
- Grau de cada vértice: 4
- Total de arestas: `5×4/2 = 10`
- Matriz 5×5 com 0 na diagonal e 1 em todo o resto.

---

### Q7 — Bipartição

**a) Matriz de adjacência** (ordem: a,b,c,d,e,f):
```
  a  b  c  d  e  f
a[0, 0, 0, 1, 1, 0]
b[0, 0, 0, 1, 0, 1]
c[0, 0, 0, 1, 1, 1]
d[1, 1, 1, 0, 0, 0]
e[1, 0, 1, 0, 0, 0]
f[0, 1, 1, 0, 0, 0]
```

**b)** ✅ **Sim, é bipartido.**

- **V₁ = {a, b, c}**
- **V₂ = {d, e, f}**

Todas as arestas têm uma extremidade em V₁ e outra em V₂:
- (a,d) ✅, (a,e) ✅, (b,d) ✅, (b,f) ✅, (c,d) ✅, (c,e) ✅, (c,f) ✅

Nenhuma aresta entre dois vértices do mesmo grupo. ✅

---

### Q8 — Grafos Bipartidos Completos

| Grafo | V₁ | V₂ | Arestas | Grau em V₁ | Grau em V₂ |
|-------|----|----|---------|-----------|-----------|
| K₁,₃ | {a} | {b,c,d} | 3 | 3 | 1 |
| K₃,₂ | {a,b,c} | {d,e} | 6 | 2 | 3 |
| K₃,₃ | {a,b,c} | {d,e,f} | 9 | 3 | 3 |
| K₄,₃ | {a,b,c,d} | {e,f,g} | 12 | 3 | 4 |

**Fórmula geral:** Kₘ,ₙ tem `m×n` arestas.

---

### Q9 — Grafo 3-Regular com 6 Vértices

**a)** Soma dos graus = `6 × 3 = 18`. Como cada aresta contribui 2: `|A| = 18/2 = 9` arestas.

**b)** Sim, é **3-regular** (k = 3).

**c)** Sim, é possível. Exemplo: K₃,₃ é 3-regular com 6 vértices. Outro exemplo: o prisma triangular (dois triângulos conectados).

---

### Q10 — Grafo Complementar

**a)** Se `G = K₄`, todo par já está conectado, portanto `Ḡ` tem os mesmos 4 vértices e **nenhuma aresta** (grafo vazio).

**b)** K₄ tem `4×3/2 = 6` arestas. G tem 3 arestas. Portanto `Ḡ` tem `6 - 3 = 3` arestas.

**c) Prova:**
- Por definição, `(x,y) ∈ A(G)` ⟺ `(x,y) ∉ A(Ḡ)`
- Portanto `A(G) ∩ A(Ḡ) = ∅` e `A(G) ∪ A(Ḡ)` contém todos os pares possíveis de vértices distintos
- O conjunto de todos os pares possíveis de n vértices é exatamente `A(Kₙ)`
- Logo `G ∪ Ḡ = Kₙ` ✅

---

## Bloco 3 — Isomorfismo

### Q11 — G e H são isomorfos?

**Checklist:**
- |V(G)| = |V(H)| = 5 ✅
- |A(G)| = |A(H)| = 5 ✅

Sequência de graus de G: d(v1)=2, d(v2)=2, d(v3)=2, d(v4)=3, d(v5)=1 → `[3,2,2,2,1]`
Sequência de graus de H: d(u)=2, d(v)=2, d(x)=2, d(y)=3, d(w)=1 → `[3,2,2,2,1]` ✅

**Correspondência:**
- `v4 → y` (grau 3)
- `v5 → w` (grau 1)
- `v1 → u`, `v2 → v`, `v3 → x`

Verificação das arestas:
- (v1,v2) → (u,v) ✅
- (v1,v3) → (u,x) ✅
- (v2,v4) → (v,y) ✅
- (v3,v4) → (x,y) ✅
- (v4,v5) → (y,w) ✅

✅ **São isomorfos.**

---

### Q12 — Verdadeiro ou Falso

**a)** ✅ **Verdadeiro.** A função bijetora preserva adjacências, logo preserva graus. Se f(v) tem grau k em H, então v tem grau k em G.

**b)** ❌ **Falso.** A mesma sequência de graus é condição **necessária** mas não **suficiente**. Contraexemplo clássico: dois grafos com 4 vértices e sequência `[2,2,2,2]` — um pode ser o ciclo C₄ (quadrado) e o outro dois triângulos disjuntos com um vértice a mais — na verdade com 4 vértices: um pode ser ciclo e outro não ter a mesma estrutura de adjacência.

---

### Q13 — Condições de Isomorfismo

**Par A:**
- G₁: sequência `[3,2,2,1]`; G₂: sequência `[2,2,2,2]`
- Sequências diferentes → ❌ **Não são isomorfos.** (Falha na condição da sequência de graus)

**Par B:**
- Mesmos |V|=5, |A|=6, mesma sequência `[3,3,2,2,2]`
- Condições necessárias satisfeitas ✅
- Uma análise detalhada das adjacências seria necessária para confirmar isomorfismo.

---

### Q14 — Grafo com 11 vértices

**a) Matriz de adjacência** (11×11): A aresta `(X,Y)` coloca 1 nas posições correspondentes. A descrição é uma árvore binária completa de 3 níveis.

**b) Grafo complementar:** Tem os mesmos 11 vértices e todas as arestas que **não** estão no grafo original. Como o original tem 10 arestas e K₁₁ teria `11×10/2 = 55` arestas, o complementar tem `55 - 10 = 45` arestas.

**c) Subgrafo induzido por {A, B, C, D}:**
- Arestas entre esses vértices no grafo original: A-B, A-C, B-D
- V(H) = {A,B,C,D}, A(H) = {(A,B),(A,C),(B,D)}

**d) Bipartição:**
- V₁ = {A, D, E, F, G} (nível par da árvore: raiz e nível 2)
- V₂ = {B, C, H, I, J, K} (nível ímpar: nível 1 e 3)
- Toda aresta vai de um nível para outro ✅ → **É bipartido.**

---

## Bloco 4 — Percursos, Trilhas, Caminhos e Ciclos

### Q15 — Classificação de Sequências

**a)** `1→2→3→1`:
- Fechado ✅, sem arestas repetidas ✅, vértice 1 repetido (início=fim, permitido em ciclo)
- É um **Ciclo** (e também Circuito e Trilha fechada)

**b)** `1→2→5→4→3→1`:
- Fechado ✅, sem arestas repetidas ✅, sem vértices intermediários repetidos ✅
- É um **Ciclo Hamiltoniano** (passa por todos os 5 vértices) e também um Circuito.

**c)** `1→3→2→1→3`:
- Aresta (1,3) aparece duas vezes → **não é trilha**
- É um **Percurso** (apenas percurso, a classificação mais fraca)

**d)** `1→2→3→4→5`:
- Sem repetições, não fechado
- É um **Caminho** (e portanto também uma Trilha e um Percurso)

---

### Q16 — Diferenças

**a) Trilha vs Caminho:**
- Trilha: percurso **sem arestas repetidas** (mas pode repetir vértices)
- Caminho: trilha **sem vértices repetidos** (restrição mais forte)
- Todo caminho é uma trilha, mas nem toda trilha é um caminho.

**b) Circuito vs Ciclo:**
- Circuito: trilha **fechada** (inicia e termina no mesmo vértice, sem arestas repetidas)
- Ciclo: caminho **fechado** (sem vértices repetidos, exceto o inicial=final)
- Todo ciclo é um circuito, mas nem todo circuito é um ciclo.

**c) Percurso fechado vs Circuito:**
- Percurso fechado: apenas começa e termina no mesmo vértice (pode repetir arestas)
- Circuito: percurso fechado **sem arestas repetidas**
- Todo circuito é percurso fechado, mas não vice-versa.

---

### Q17 — Grau ≥ 2 e Ciclos

**a)** ❌ **Não necessariamente.** Dois ciclos disjuntos (ex: dois triângulos sem conexão entre si) têm todos os vértices com grau 2, mas o grafo é desconectado.

**b)** ✅ **Sim.** **Teorema:** Se todo vértice de G tem grau ≥ 2, então G possui um ciclo.

**Lógica da prova:** Parta de qualquer vértice e siga um caminho. Como todo vértice tem ao menos 2 vizinhos, ao chegar em qualquer vértice sempre existe outra aresta para seguir. Como G é finito, em algum momento você chegará a um vértice já visitado — isso cria um ciclo.

---

## Bloco 5 — Circuito Euleriano e Ciclo Hamiltoniano

### Q18 — Circuito Euleriano

**Teorema:** G é Euleriano ⟺ G é conectado E todos os vértices têm grau par.

**a)** Arestas: (1,2),(2,3),(3,4),(4,1),(1,3):
- Graus: d(1)=3, d(2)=2, d(3)=3, d(4)=2
- Vértices 1 e 3 têm grau ímpar → ❌ **Não é Euleriano**

**b) K₄:**
- Todos os vértices têm grau 3 (ímpar) → ❌ **Não é Euleriano**

**c) K₅:**
- Todos os vértices têm grau 4 (par), e K₅ é conectado → ✅ **É Euleriano**

**d)** Sequência `[2,2,2,2,4]`: todos pares. Se conectado → ✅ **É Euleriano**

---

### Q19 — Pontes de Königsberg

Modelagem: 4 regiões = 4 vértices. 7 pontes = 7 arestas.
Graus das 4 regiões: 3, 3, 3, 5 (todos ímpares!).

Para existir um circuito Euleriano, **todos** os vértices precisam ter grau par. Aqui todos têm grau ímpar — logo, é **impossível** percorrer todas as pontes exatamente uma vez retornando ao ponto de partida.

*(Euler provou isso em 1736, fundando a Teoria dos Grafos.)*

---

### Q20 — Ciclo Hamiltoniano

**a) K₃:** ✅ O próprio K₃ é um ciclo que passa pelos 3 vértices: 1→2→3→1.

**b) K₄:** ✅ Exemplo: 1→2→3→4→1.

**c) Caminho 1-2-3-4-5:** ❌ Um caminho simples não tem aresta de volta do último ao primeiro vértice, então não fecha o ciclo.

**d) C₅:** ✅ O próprio ciclo C₅ já é um ciclo Hamiltoniano (passa por todos os 5 vértices uma vez e fecha).

---

### Q21 — Euleriano vs Hamiltoniano

| | Euleriano | Hamiltoniano |
|--|-----------|--------------|
| Objetivo | Percorrer todas as **arestas** | Visitar todos os **vértices** |
| Condição | Conectado + todos os graus pares | Não há condição simples e geral |
| Tipo | Circuito (trilha fechada) | Ciclo (caminho fechado) |

**Exemplo com ambos:** K₅ — é Euleriano (graus todos 4, par) e possui Ciclo Hamiltoniano (qualquer ciclo passando pelos 5 vértices).

---

## Bloco 6 — Coloração de Grafos

### Q22 — Número Cromático

| Grafo | X(G) | Justificativa |
|-------|------|---------------|
| K₃ | 3 | Triângulo: cada vértice é adjacente aos outros dois |
| K₄ | 4 | Todo vértice adjacente a todos: precisa de n cores |
| K₅ | 5 | Idem |
| P₅ (caminho) | 2 | Bipartido: alterna 2 cores ao longo do caminho |
| C₄ (ciclo par) | 2 | Ciclo de comprimento par é bipartido |
| C₅ (ciclo ímpar) | 3 | Ciclo ímpar nunca é bipartido; precisa de 3 cores |

> **Regra geral:** Kₙ precisa de n cores. Ciclos pares: 2 cores. Ciclos ímpares: 3 cores.

---

### Q23 — Coloração de Mapa

**a)** Grafo: V = {A,B,C,D,E}, A = {A-B, A-C, B-C, B-D, C-D, D-E}

**b)** Verificando: A,B,C formam um triângulo (K₃) → precisam de 3 cores. D é adjacente a B e C (cores diferentes) → pode usar a cor de A. E é adjacente só a D → pode usar qualquer cor de D.

**X(G) = 3**

**c) Coloração válida:**
- A = cor 1 (Vermelho)
- B = cor 2 (Azul)
- C = cor 3 (Verde)
- D = cor 1 (Vermelho) — não adjacente a A
- E = cor 2 (Azul) — não adjacente a B

---

### Q24 — Grafo Bipartido tem X(G) ≤ 2

**Prova:**
- Seja G bipartido com bipartição V₁ e V₂.
- Atribua cor 1 a todos os vértices de V₁ e cor 2 a todos de V₂.
- Por definição de bipartido, toda aresta tem uma extremidade em V₁ e outra em V₂.
- Portanto, extremidades de qualquer aresta têm cores diferentes. ✅
- Logo G é 2-colorível, e X(G) ≤ 2. ■

*(Se G não tem arestas, X(G)=1. Se tem pelo menos uma aresta, X(G)=2.)*

---

## Bloco 7 — Dígrafos

### Q25 — Dígrafo

**Arestas: A→B, A→C, B→D, C→B, C→D**

**a) Matriz de adjacência** (linhas=emissor, colunas=receptor):
```
     A  B  C  D
A  [ 0, 1, 1, 0 ]
B  [ 0, 0, 0, 1 ]
C  [ 0, 1, 0, 1 ]
D  [ 0, 0, 0, 0 ]
```

**b) Graus:**

| Vértice | de(v) emissão | dr(v) recepção |
|---------|--------------|----------------|
| A | 2 (→B, →C) | 0 |
| B | 1 (→D) | 2 (A→B, C→B) |
| C | 2 (→B, →D) | 1 (A→C) |
| D | 0 | 2 (B→D, C→D) |

**c)**
- **Fonte:** A (dr(A) = 0, ninguém chega em A) ✅
- **Sumidouro:** D (de(D) = 0, D não emite) ✅

---

### Q26 — Percursos no Dígrafo

**a)** Percursos de A até D:
- A→B→D ✅
- A→C→D ✅
- A→C→B→D ✅

**b)** ❌ Não existe percurso de D até A. D tem grau de emissão 0 (sumidouro) — não há aresta saindo de D.

---

## Bloco 8 — Grafo Valorado e Fluxo Máximo

### Q27
*(Resposta aberta — qualquer grafo com pesos e um vértice fonte + sumidouro identificados está correto.)*

---

### Q28 — Fluxo Máximo

**Capacidades:**
```
s→B: 20,  s→F: 20
B→C: 30,  B→G: 5
F→C: 25,  F→G: 5
C→t: 25,  G→t: 15,  G→C: 10
```

**b) Fluxo máximo:**

Corte mínimo: separar `{s}` de `{B, C, D, F, G, t}`.
- Capacidade do corte = cap(s→B) + cap(s→F) = 20 + 20 = **40**

Porém o sumidouro só pode receber pelo que chega: C→t (25) + G→t (15) = 40.

Analisando os caminhos:
- Caminho s→B→C→t: fluxo máximo 20 (limitado por s→B)
- Caminho s→F→C→t: só 5 restam em C→t (25-20=5), limitado por C→t
- Caminho s→F→G→t: fluxo 15 (limitado por G→t)

**Fluxo máximo = 40** (saturando ambas as saídas de s).

---

## Bloco 9 — Planaridade e Fórmula de Euler

### Q29 — Verificação de Euler (V - E + F = 2)

**a) K₃:** V=3, E=3, F=2 (1 interna + 1 externa) → 3 - 3 + 2 = **2** ✅

**b) K₄:** V=4, E=6, F=4 (3 internas + 1 externa) → 4 - 6 + 4 = **2** ✅

**c) Cubo:** V=8, E=12, F=6 (faces do cubo, todas planares) → 8 - 12 + 6 = **2** ✅

---

### Q30 — Planaridade

**a) K₄:** ✅ **Planar.** Pode ser desenhado no plano sem cruzamentos.

**b) K₅:** ❌ **Não planar.** Pelo teorema de Kuratowski, K₅ é não-planar. Verificação pela fórmula: se fosse planar, E ≤ 3V-6 → 10 ≤ 3(5)-6 = 9. Contradição (10 > 9).

**c) K₃,₃:** ❌ **Não planar.** Para grafos bipartidos planares: E ≤ 2V-4 → 9 ≤ 2(6)-4 = 8. Contradição (9 > 8).

**d) C₆:** ✅ **Planar.** Um hexágono é facilmente desenhado sem cruzamentos.

---

### Q31 — Faces de um grafo planar

Pela fórmula de Euler: `V - E + F = 2`
- V = 10, E = 15
- `10 - 15 + F = 2`
- `F = 2 - 10 + 15 = 7`

O grafo possui **7 faces** (incluindo a face externa).

---

## Bloco 10 — Vértice de Corte e Conectividade

### Q32 — Vértice de Corte

**V = {1,2,3,4,5,6}, A = {(1,2),(2,3),(3,4),(4,5),(5,6),(3,6)}**

**a)** ✅ **Conectado.** Existe caminho entre qualquer par de vértices (verifique: todos alcançam todos passando pelo "backbone" 1-2-3-...).

**b)** Sim. Vértice **3** é de corte.
- Ao remover 3 (e suas arestas (2,3),(3,4),(3,6)): fica o componente {1,2} e o componente {4,5,6}.
- O grafo passa de 1 componente para 2 → 3 é vértice de corte. ✅

*(O vértice 2 também pode ser analisado: remover 2 deixa {1} isolado e {3,4,5,6} — também é vértice de corte.)*

---

### Q33

Se todo vértice tem grau ≥ 2, pelo teorema, G possui um ciclo. Em um ciclo, qualquer vértice tem pelo menos 2 caminhos alternativos para chegar a seus vizinhos (pelos dois lados do ciclo). Portanto, remover um único vértice do ciclo ainda deixa os outros conectados pelo caminho restante — impossível isolar um único vértice.

---

## Bloco 11 — Questões Desafio

### Q34 — Grafo com todos os vértices de grau n-1

Um grafo simples em que todo vértice tem grau `n-1` significa que todo vértice é adjacente a todos os outros. Isso é a definição de **grafo completo Kₙ**.

Número de arestas: `n(n-1)/2`.

---

### Q35 — Dois vértices com o mesmo grau (Princípio da Casa dos Pombos)

**Prova:**
- Em um grafo simples com `n ≥ 2` vértices, o grau de cada vértice pode ser 0, 1, 2, ..., ou n-1.
- São `n` possíveis valores de grau, mas **não podem ocorrer simultaneamente** grau 0 (vértice isolado) e grau n-1 (conectado a todos): se existe vértice isolado, nenhum tem grau n-1, e vice-versa.
- Portanto há no máximo `n-1` valores distintos possíveis de grau para `n` vértices.
- Pelo **Princípio da Casa dos Pombos**: `n` vértices em `n-1` "casas" → pelo menos dois vértices têm o mesmo grau. ■

---

### Q36 — Percursos via Potências da Matriz

**Matriz M** (4 vértices):

**a) Calculando M²:**

```
M² = M × M

Linha 1 × Colunas:
(1,1): 0·0+1·1+1·1+0·0 = 2
(1,2): 0·1+1·0+1·1+0·1 = 1
(1,3): 0·1+1·1+1·0+0·1 = 1
(1,4): 0·0+1·1+1·1+0·0 = 2

Linha 2 × Colunas:
(2,1): 1·0+0·1+1·1+1·0 = 1
(2,2): 1·1+0·0+1·1+1·1 = 3
(2,3): 1·1+0·1+1·0+1·1 = 2
(2,4): 1·0+0·1+1·1+1·0 = 1

Linha 3 × Colunas:
(3,1): 1·0+1·1+0·1+1·0 = 1
(3,2): 1·1+1·0+0·1+1·1 = 2
(3,3): 1·1+1·1+0·0+1·1 = 3
(3,4): 1·0+1·1+0·1+1·0 = 1

Linha 4 × Colunas:
(4,1): 0·0+1·1+1·1+0·0 = 2
(4,2): 0·1+1·0+1·1+0·1 = 1
(4,3): 0·1+1·1+1·0+0·1 = 1
(4,4): 0·0+1·1+1·1+0·0 = 2
```

$$M^2 = \begin{pmatrix} 2 & 1 & 1 & 2 \\ 1 & 3 & 2 & 1 \\ 1 & 2 & 3 & 1 \\ 2 & 1 & 1 & 2 \end{pmatrix}$$

**b)** Percursos de comprimento 2 entre vértice 1 e vértice 4: `(M²)₁₄ = 2`

**c)** Percursos de comprimento 2 de vértice 2 para ele mesmo: `(M²)₂₂ = 3`
*(Isso corresponde a: 2→1→2, 2→3→2, 2→4→2 — três "laços" de ida e volta)*

---

### Q37 — Grafo com 7 vértices

**Sequência de graus: `[1, 2, 2, 3, 3, 4, 4]`**

**a)** Soma dos graus = `1+2+2+3+3+4+4 = 19`. Mas 19 é **ímpar** — isso viola o Lema do Aperto de Mão!

> ⚠️ **Este grafo é impossível.** Um grafo com essa sequência de graus não pode existir, pois a soma dos graus deve ser sempre par.

*(Se a questão aparecer na prova com uma sequência válida, o cálculo seria: soma/2 = número de arestas.)*

**b)** Além de impossível, mesmo que a sequência fosse válida: vértice de grau 1 tem grau ímpar → não seria Euleriano.

**c)** Não necessariamente — a sequência de graus não garante conectividade.

---

### Q38 — Subgrafo vs Subgrafo Induzido vs Complementar

**Subgrafo H de G:**
- `V(H) ⊆ V(G)` e `A(H) ⊆ A(G)`
- Pode-se escolher qualquer subconjunto de vértices E qualquer subconjunto de arestas (respeitando que toda aresta de H tenha extremidades em V(H))
- Mais flexível: posso "apagar" arestas à vontade

**Subgrafo Induzido por S ⊆ V(G):**
- V(H) = S (fixo, todos os vértices de S)
- A(H) = **todas** as arestas de G que têm **ambas** as extremidades em S (não posso escolher quais arestas incluir — elas são determinadas pelos vértices)
- É o "pedaço" do grafo que surge naturalmente ao selecionar um subconjunto de vértices

**Grafo Complementar Ḡ:**
- V(Ḡ) = V(G) (mesmos vértices)
- A(Ḡ) = todas as arestas que **não existem** em G (inverso das arestas)
- `G ∪ Ḡ = Kₙ`

**Resumindo com analogia:**
- Subgrafo = você escolhe vértices E arestas livremente
- Subgrafo induzido = você escolhe os vértices, as arestas vêm automaticamente
- Complementar = mantém os vértices, inverte as arestas

---


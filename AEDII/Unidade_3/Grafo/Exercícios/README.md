#  Lista de Exercícios — Teoria dos Grafos
> **Algoritmos e Estruturas de Dados II**


---

## 📌 Bloco 1 — Conceitos Fundamentais e Representação

**Q1.** Dada a definição formal de grafo `G = (V, A)`, identifique quais dos conjuntos abaixo formam grafos válidos. Justifique cada caso:

a) `V = {1, 2, 3}`, `A = {(1,2), (2,3), (1,3)}`

b) `V = {}`, `A = {}`

c) `V = {a}`, `A = {(a,a)}`

d) `V = {1, 2}`, `A = {(1,3)}`

---

**Q2.** Liste cinco situações do mundo real onde a Teoria dos Grafos pode ser aplicada naturalmente. Para cada uma, indique quem seriam os vértices e o que representariam as arestas.

---

**Q3.** Seja o grafo `G` com:

```
V(G) = {a, b, c, d, e, f}
A(G) = {(a,b), (a,e), (b,c), (c,c), (d,e), (e,d)}
```

a) Desenhe G.

b) G é simples? Por quê?

c) Liste o grau de cada vértice.

d) Quais são as arestas incidentes a `b`?

e) Quais são os vizinhos de `a`?

f) Escreva a matriz de adjacência de G.

---

**Q4.** Desenhe os grafos correspondentes às matrizes de adjacência abaixo:

$$M_1 = \begin{pmatrix} 0 & 2 & 0 & 1 \\ 2 & 0 & 1 & 0 \\ 0 & 1 & 1 & 1 \\ 1 & 0 & 1 & 0 \end{pmatrix}$$

$$M_2 = \begin{pmatrix} 0 & 1 & 2 & 1 \\ 1 & 2 & 1 & 0 \\ 2 & 1 & 0 & 0 \\ 1 & 0 & 0 & 0 \end{pmatrix}$$

$$M_4 = \begin{pmatrix} 0 & 1 & 0 & 0 & 1 \\ 1 & 0 & 1 & 0 & 0 \\ 0 & 1 & 0 & 1 & 0 \\ 0 & 0 & 1 & 0 & 1 \\ 1 & 0 & 0 & 1 & 0 \end{pmatrix}$$

---

**Q5.** Classifique como **Verdadeiro** ou **Falso** e justifique:

a) A soma dos graus de todos os vértices de um grafo é sempre par.

b) É possível ter um grafo simples com 5 vértices, onde três têm grau 3 e dois têm grau 2.

c) Um grafo com todos os vértices de grau zero pode ter arestas.

d) Um loop contribui com 2 para o grau do vértice.

e) Todo grafo k-regular tem número de arestas igual a `k × |V| / 2`.

---

## 📌 Bloco 2 — Grafos Especiais

**Q6.** Para cada grafo completo abaixo, informe: o grau de cada vértice, o número total de arestas e a matriz de adjacência.

a) K₃
b) K₄
c) K₅

---

**Q7.** Considere o grafo `G` com vértices `V = {a, b, c, d, e, f}` e arestas `A = {(a,d), (a,e), (b,d), (b,f), (c,d), (c,e), (c,f)}`.

a) Escreva a matriz de adjacência.

b) Este grafo é bipartido? Se sim, encontre a bipartição `V₁` e `V₂` e prove. Se não, justifique.

---

**Q8.** Descreva os grafos bipartidos completos abaixo em notação matricial e verifique a bipartição:

a) K₁,₃
b) K₃,₂
c) K₃,₃
d) K₄,₃

---

**Q9.** Um grafo simples `G` tem 6 vértices todos com grau 3.

a) Quantas arestas G possui?

b) G é k-regular? Para qual valor de k?

c) É possível desenhar tal grafo? Desenhe um exemplo.

---

**Q10.** Dado um grafo `G`, seu complementar `Ḡ` tem os mesmos vértices, mas apenas as arestas que **não** estavam em `G`.

a) Se `G = K₄`, qual é `Ḡ`?

b) Se `G` tem 4 vértices e 3 arestas (caminho simples `1-2-3-4`), quantas arestas tem `Ḡ`?

c) Prove que `G ∪ Ḡ = Kₙ`, onde `n = |V|`.

---

## 📌 Bloco 3 — Isomorfismo

**Q11.** Avalie se os grafos `G` e `H` são isomorfos. Se verdadeiro, indique a correspondência entre os vértices que prova a isomorfia.

**Grafo G:**
```
V = {v1, v2, v3, v4, v5}
A = {(v1,v2), (v1,v3), (v2,v4), (v3,v4), (v4,v5)}
```

**Grafo H:**
```
V = {u, v, x, y, w}
A = {(u,v), (u,x), (v,y), (x,y), (y,w)}
```

---

**Q12.** Classifique como **Verdadeiro** ou **Falso**:

a) Quaisquer dois grafos isomórficos têm a mesma sequência de graus.

b) Quaisquer dois grafos com a mesma sequência de graus são isomórficos.

---

**Q13.** Para cada par de grafos abaixo, verifique as **condições necessárias** de isomorfismo e determine se os grafos são isomorfos (justifique):

**Par A:**
- G₁: 4 vértices, sequência de graus `[3, 2, 2, 1]`
- G₂: 4 vértices, sequência de graus `[2, 2, 2, 2]`

**Par B:**
- G₁: 5 vértices, 6 arestas, sequência de graus `[3, 3, 2, 2, 2]`
- G₂: 5 vértices, 6 arestas, sequência de graus `[3, 3, 2, 2, 2]`

*(Para o Par B: se as condições necessárias forem satisfeitas, basta afirmar isso e que uma verificação detalhada seria necessária.)*

---

**Q14.** Considere o grafo G abaixo:

```
V = {A, B, C, D, E, F, G, H, I, J, K}
Arestas: A-B, A-C, B-D, B-E, C-F, C-G, D-H, E-I, F-J, G-K
```

a) Escreva a matriz de adjacência.

b) Desenhe o grafo complementar.

c) Identifique o subgrafo induzido pelos vértices `{A, B, C, D}`.

d) É possível fazer uma bipartição desse grafo? Se sim, apresente-a.

---

## 📌 Bloco 4 — Percursos, Trilhas, Caminhos e Ciclos

**Q15.** Dado o grafo com vértices `{1, 2, 3, 4, 5}` e arestas `{(1,2), (1,3), (2,3), (3,4), (4,5), (2,5)}`, classifique cada sequência abaixo:

a) `1 → 2 → 3 → 1` — Percurso, Trilha, Caminho, Circuito ou Ciclo?

b) `1 → 2 → 5 → 4 → 3 → 1` — Classifique.

c) `1 → 3 → 2 → 1 → 3` — Classifique.

d) `1 → 2 → 3 → 4 → 5` — Classifique.

---

**Q16.** Explique a diferença entre:

a) Trilha e Caminho

b) Circuito e Ciclo

c) Percurso fechado e Circuito

---

**Q17.** Considere que um grafo tem todos os vértices com grau ≥ 2.

a) Esse grafo é necessariamente conectado? Justifique ou dê um contraexemplo.

b) Esse grafo necessariamente possui um ciclo? Enuncie o teorema e explique a lógica.

---

## 📌 Bloco 5 — Circuito Euleriano e Ciclo Hamiltoniano

**Q18.** Para cada grafo abaixo, diga se possui **Circuito Euleriano**. Justifique usando o teorema de Euler.

a) Grafo com 4 vértices e arestas `{(1,2),(2,3),(3,4),(4,1),(1,3)}`

b) K₄

c) K₅

d) Grafo com sequência de graus `[2, 2, 2, 2, 4]`

---

**Q19.** O famoso problema das **Pontes de Königsberg** possui 4 regiões e 7 pontes. Modele o problema como grafo e explique por que não é possível percorrer todas as pontes exatamente uma vez.

---

**Q20.** Para cada grafo, diga se possui **Ciclo Hamiltoniano** (que passa por todos os vértices exatamente uma vez). Justifique:

a) K₃

b) K₄

c) Caminho simples `1-2-3-4-5` (sem mais arestas)

d) Ciclo `C₅` (pentágono: 5 vértices em ciclo)

---

**Q21.** Qual a diferença fundamental entre Circuito Euleriano e Ciclo Hamiltoniano? É possível um grafo ter ambos? Dê um exemplo.

---

## 📌 Bloco 6 — Coloração de Grafos

**Q22.** Encontre o número cromático `X(G)` para cada grafo:

a) K₃ (triângulo)

b) K₄

c) K₅

d) Caminho simples com 5 vértices (`P₅`)

e) Ciclo com 4 vértices (`C₄`)

f) Ciclo com 5 vértices (`C₅`)

---

**Q23.** Um mapa tem 5 países, onde as fronteiras são: A-B, A-C, B-C, B-D, C-D, D-E.

a) Modele como grafo.

b) Encontre o número cromático do grafo.

c) Apresente uma coloração válida usando o mínimo de cores.

---

**Q24.** Prove ou refute: **Todo grafo bipartido tem número cromático ≤ 2.**

---

## 📌 Bloco 7 — Dígrafos

**Q25.** Dado o dígrafo com vértices `{A, B, C, D}` e arestas orientadas `{A→B, A→C, B→D, C→B, C→D}`:

a) Escreva a matriz de adjacência do dígrafo.

b) Calcule o grau de emissão e de recepção de cada vértice.

c) Existe algum vértice **fonte**? E algum **sumidouro**?

---

**Q26.** Para o dígrafo da questão anterior:

a) Existe um percurso de `A` até `D`? Se sim, liste todos os percursos distintos.

b) Existe um percurso de `D` até `A`?

---

## 📌 Bloco 8 — Grafo Valorado e Fluxo Máximo

**Q27.** Desenhe um grafo valorado que represente um sistema de distribuição de água com 5 cidades, onde os pesos das arestas indicam a capacidade das tubulações (em litros/segundo). Sua rede deve ter pelo menos uma fonte e um sumidouro.

---

**Q28.** Considere a rede de fluxo abaixo com capacidades nas arestas:

```
s → B: capacidade 20
s → F: capacidade 20
B → C: capacidade 30
B → G: capacidade 5
F → C: capacidade 25
F → G: capacidade 5
C → t: capacidade 25
G → t: capacidade 15
G → C: capacidade 10
```

a) Encontre um fluxo válido da fonte `s` ao sumidouro `t`.

b) Qual é o fluxo máximo possível? Justifique identificando um corte mínimo.

---

## 📌 Bloco 9 — Planaridade e Fórmula de Euler

**Q29.** Verifique a Fórmula de Euler (`V - E + F = 2`) para os seguintes grafos planares:

a) Um triângulo (K₃) desenhado no plano.

b) K₄ desenhado no plano.

c) Um cubo (8 vértices, 12 arestas).

---

**Q30.** Determine se os grafos abaixo são planares. Justifique:

a) K₄

b) K₅

c) K₃,₃

d) Um ciclo C₆ (hexágono)

---

**Q31.** Um grafo planar conectado tem 10 vértices e 15 arestas. Quantas faces possui?

---

## 📌 Bloco 10 — Vértice de Corte e Conectividade

**Q32.** Dado o grafo:

```
V = {1, 2, 3, 4, 5, 6}
A = {(1,2), (2,3), (3,4), (4,5), (5,6), (3,6)}
```

a) Este grafo é conectado?

b) Existe algum vértice de corte? Se sim, identifique-o e justifique.

---

**Q33.** Explique por que um grafo k-regular com k ≥ 2 não pode ter um vértice de corte isolado (um vértice que ao ser removido deixa um único vértice desconectado). *(Dica: use o teorema sobre grau ≥ 2 e ciclos.)*

---

## 📌 Bloco 11 — Questões Desafio (Nível Prova)

**Q34.** Um grafo simples tem n vértices e todos têm grau (n-1). Que grafo é esse? Quantas arestas ele tem?

---

**Q35.** Prove que em qualquer grafo simples com pelo menos 2 vértices, existem sempre dois vértices com o **mesmo grau**.

*(Dica: use o Princípio da Casa dos Pombos.)*

---

**Q36.** Considere a matriz de adjacência M de um grafo G. O elemento `(M²)ᵢⱼ` representa o número de percursos de comprimento 2 entre os vértices `i` e `j`. Usando esse princípio:

Dado o grafo com matriz:
$$M = \begin{pmatrix} 0 & 1 & 1 & 0 \\ 1 & 0 & 1 & 1 \\ 1 & 1 & 0 & 1 \\ 0 & 1 & 1 & 0 \end{pmatrix}$$

a) Calcule M².

b) Quantos percursos de comprimento 2 existem entre o vértice 1 e o vértice 4?

c) Quantos percursos de comprimento 2 existem entre o vértice 2 e ele mesmo?

---

**Q37.** Um grafo tem 7 vértices. A sequência de graus é `[1, 2, 2, 3, 3, 4, 4]`.

a) Quantas arestas esse grafo tem?

b) Este grafo pode ser Euleriano? Por quê?

c) Esse grafo é conectado necessariamente? Justifique.

---

**Q38.** Explique, com suas palavras e usando definições formais, a diferença entre:

- Subgrafo
- Subgrafo induzido
- Grafo complementar

---
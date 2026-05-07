# Árvores AVL — Guia de Estudos

## O que são Árvores AVL?

As árvores AVL são um tipo de **árvore binária de busca (ABB)** que se mantêm **balanceadas automaticamente**.

Elas foram criadas para evitar o pior caso das árvores binárias comuns, onde a árvore pode ficar parecida com uma lista encadeada, tornando as operações lentas.

## Problema das Árvores Binárias Comuns

Em uma árvore binária de busca comum:

* A eficiência depende da ordem das inserções.
* Inserções em ordem crescente ou decrescente podem deixar a árvore desbalanceada.
* Isso aumenta a altura da árvore.
* No pior caso:

```text
1
 \
  2
   \
    3
     \
      4
```

Nesse caso, a busca deixa de ser eficiente.

---

# Definição de Árvore AVL

Uma árvore AVL segue duas regras:

1. As subárvores esquerda e direita também devem ser AVL.
2. A diferença entre as alturas das subárvores deve ser no máximo 1.

Matematicamente:

\[
|Altura(Esquerda) - Altura(Direita)| <= 1
\]


---

# Fator de Balanceamento (FB)

O fator de balanceamento indica se um nó está equilibrado.

## Fórmula

\[
FB = h_L - h_R
\]

Onde:

- \( FB \) = fator de balanceamento
- \( h_L \) = altura da subárvore esquerda
- \( h_R \) = altura da subárvore direita

## Valores possíveis em uma AVL

O FB só pode ser:

* (-1)
* (0)
* (+1)

Se o fator for:

| FB | Significado    |
| -- | -------------- |
| 0  | Alturas iguais |
| +1 | Esquerda maior |
| -1 | Direita maior  |

---

# Quando a árvore fica desbalanceada?

Uma árvore fica desbalanceada quando algum nó passa a ter:

* FB = +2
* FB = -2

Quando isso acontece, é necessário realizar uma **rotação**.

---

# Tipos de Rotações

Existem 4 rotações principais:

| Caso | Condição        | Rotação                        |
| ---- | --------------- | ------------------------------ |
| LL   | A = +2 e B = +1 | Rotação à direita              |
| RR   | A = -2 e B = -1 | Rotação à esquerda             |
| LR   | A = +2 e B = -1 | Rotação dupla esquerda-direita |
| RL   | A = -2 e B = +1 | Rotação dupla direita-esquerda |

---

# Rotação LL

## Quando ocorre?

Acontece quando:

* O desbalanceamento ocorre na esquerda.
* O filho esquerdo também está pesado para a esquerda.

## Estrutura

Antes:

```text
      A
     /
    B
   /
  C
```

Depois:

```text
    B
   / \
  C   A
```

## Ideia principal

A árvore gira para a direita.

---

# Rotação RR

## Quando ocorre?

Acontece quando:

* O desbalanceamento ocorre na direita.
* O filho direito também está pesado para a direita.

## Estrutura

Antes:

```text
A
 \
  B
   \
    C
```

Depois:

```text
    B
   / \
  A   C
```

## Ideia principal

A árvore gira para a esquerda.

---

# Rotação LR

## Quando ocorre?

Acontece quando:

* O desbalanceamento ocorre na esquerda.
* O filho esquerdo está pesado para a direita.

## Processo

São feitas duas rotações:

1. Rotação RR no filho.
2. Rotação LL no nó desbalanceado.

## Estrutura

Antes:

```text
      A
     /
    B
     \
      C
```

Depois:

```text
      C
     / \
    B   A
```

---

# Rotação RL

## Quando ocorre?

Acontece quando:

* O desbalanceamento ocorre na direita.
* O filho direito está pesado para a esquerda.

## Processo

São feitas duas rotações:

1. Rotação LL no filho.
2. Rotação RR no nó desbalanceado.

## Estrutura

Antes:

```text
A
 \
  B
 /
C
```

Depois:

```text
    C
   / \
  A   B
```

---

# Como identificar rapidamente a rotação?

## Passo 1

Encontre o primeiro nó desbalanceado:

* FB = +2
* FB = -2

Esse nó é chamado de **A**.

## Passo 2

Observe o filho do nó A.

Esse filho é chamado de **B**.

## Passo 3

Use a tabela:

| A  | B  | Rotação |
| -- | -- | ------- |
| +2 | +1 | LL      |
| -2 | -1 | RR      |
| +2 | -1 | LR      |
| -2 | +1 | RL      |

---

# Exemplo Completo de Inserções

## Inserindo 4, 5 e 7

### Inserção do 4

```text
4
```

Balanceada.

---

### Inserção do 5

```text
4
 \
  5
```

Ainda balanceada.

---

### Inserção do 7

```text
4
 \
  5
   \
    7
```

Agora:

* Nó 4 possui FB = -2
* Nó 5 possui FB = -1

Caso RR.

Após rotação:

```text
   5
  / \
 4   7
```

---

# Outro Exemplo — Rotação LL

Inserindo:

```text
5, 4, 2, 1
```

Árvore:

```text
      5
     /
    4
   /
  2
 /
1
```

Desbalanceamento:

* Nó 5 → +2
* Nó 4 → +1

Caso LL.

Após rotação:

```text
    4
   / \
  2   5
 /
1
```

---

# Exemplo — Rotação LR

Inserindo:

```text
5, 2, 4
```

Árvore:

```text
    5
   /
  2
   \
    4
```

Desbalanceamento:

* Nó 5 → +2
* Nó 2 → -1

Caso LR.

Resultado:

```text
    4
   / \
  2   5
```

---

# Exemplo — Rotação RL

Inserindo:

```text
5, 7, 6
```

Árvore:

```text
5
 \
  7
 /
6
```

Desbalanceamento:

* Nó 5 → -2
* Nó 7 → +1

Caso RL.

Resultado:

```text
   6
  / \
 5   7
```

---

# Complexidade

## Operações principais

| Operação | Complexidade |
| -------- | ------------ |
| Busca    | O(log n)     |
| Inserção | O(log n)     |
| Remoção  | O(log n)     |

Isso acontece porque a árvore permanece balanceada.

---

# Vantagens das Árvores AVL

* Busca muito eficiente.
* Altura sempre controlada.
* Melhor desempenho em consultas.
* Evita degeneração da árvore.

---

# Desvantagens

* Inserções e remoções são mais complexas.
* Necessidade de rotações.
* Mais custo de manutenção do balanceamento.

---

# Resumo Geral

## O que é AVL?

Uma árvore binária de busca balanceada.

## Condição AVL

A diferença entre as alturas das subárvores esquerda e direita deve ser no máximo 1.

\[
|h_L - h_R| \leq 1
\]

Onde:

- \( h_L \) = altura da subárvore esquerda
- \( h_R \) = altura da subárvore direita

---

## Fator de Balanceamento

O fator de balanceamento (FB) de um nó é calculado pela diferença entre a altura da subárvore esquerda e da direita.

\[
FB = h_L - h_R
\]

Onde:

- \( h_L \) = altura da subárvore esquerda
- \( h_R \) = altura da subárvore direita

## Valores permitidos

* -1
* 0
* +1

## Se aparecer

* +2
* -2

➡️ Fazer rotação.

---

# Mapa Mental Rápido

```text
AVL
│
├── Balanceamento
│   ├── FB = hL - hR
│   ├── Permitidos: -1, 0, +1
│   └── Desbalanceado: +2 ou -2
│
├── Rotações
│   ├── LL → direita
│   ├── RR → esquerda
│   ├── LR → dupla
│   └── RL → dupla
│
└── Complexidade
    ├── Busca → O(log n)
    ├── Inserção → O(log n)
    └── Remoção → O(log n)
```

---

# Dicas para Prova

## Como descobrir a rotação rapidamente

1. Ache o nó desbalanceado.
2. Veja para qual lado ele está pesado.
3. Veja para qual lado o filho está pesado.
4. Use a tabela:

| Situação          | Rotação |
| ----------------- | ------- |
| esquerda-esquerda | LL      |
| direita-direita   | RR      |
| esquerda-direita  | LR      |
| direita-esquerda  | RL      |


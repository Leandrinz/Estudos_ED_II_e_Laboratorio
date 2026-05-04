# Compressão de Dados - Algoritmo de Huffman
O Algoritmo de Huffman funciona com base na contagem de frequência com base de um certo valor (números, caracteres...)

Juntamos os com menores frequências até não ser mais possível


##  Exemplo de Análise de Frequência (Algoritmo de Huffman)

###  Objetivo

Demonstrar passo a passo como funciona a **análise de frequência** utilizada no algoritmo de Huffman para compressão de dados.

---

##  Texto de exemplo

Vamos utilizar a seguinte string:

```
BANANA
```

---

##  Passo 1: Contagem de frequência

Contamos quantas vezes cada caractere aparece:

| Caractere | Frequência |
| --------- | ---------- |
| A         | 3          |
| N         | 2          |
| B         | 1          |

---

##  Passo 2: Ordenação por frequência

Ordenamos os caracteres do menor para o maior:

| Caractere | Frequência |
| --------- | ---------- |
| B         | 1          |
| N         | 2          |
| A         | 3          |

---

##  Passo 3: Construção da árvore de Huffman

### Junta os dois menores:

* B (1) + N (2) → novo nó (3)

```
   (3)
  /   \
 B(1) N(2)
```

---

### Junta com o próximo menor:

* (BN = 3) + A (3) → raiz (6)

```
      (6)
     /   \
   (3)    A(3)
  /   \
 B(1) N(2)
```

---

##  Passo 4: Geração dos códigos binários

Regra:

* Esquerda = 0
* Direita = 1

| Caractere | Código |
| --------- | ------ |
| A         | 1      |
| B         | 00     |
| N         | 01     |

---

##  Passo 5: Codificação do texto

Texto original:

```
BANANA
```

Substituindo pelos códigos:

| Letra | Código |
| ----- | ------ |
| B     | 00     |
| A     | 1      |
| N     | 01     |
| A     | 1      |
| N     | 01     |
| A     | 1      |

Resultado final:

```
001011011
```

---

##  Comparação de tamanho

### Antes (ASCII - 8 bits por caractere):

* 6 caracteres × 8 bits = **48 bits**

### Depois (Huffman):

* Total = **9 bits**

✅ Redução significativa no tamanho!

---

##  Conclusão

A análise de frequência permite que o algoritmo de Huffman:

* Atribua códigos menores para caracteres mais frequentes
* Reduza o tamanho total da informação
* Otimize armazenamento e transmissão de dados

---

##  Observação

Esse é um exemplo simples. Em textos maiores, o ganho de compressão é ainda mais relevante.

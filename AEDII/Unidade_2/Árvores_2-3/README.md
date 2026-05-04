# 🌳 Árvore 2-3

---

## 📌 1. O que é uma Árvore 2-3

Uma árvore 2-3 é uma **árvore de busca balanceada** onde cada nó pode ter:

* 1 chave → 2 filhos
* 2 chaves → 3 filhos

Todos os elementos seguem regras de ordenação.

---

## 📌 2. Propriedades

* Cada nó contém **uma ou duas chaves**
* Cada nó interno tem:

  * 2 filhos (se tem 1 chave)
  * 3 filhos (se tem 2 chaves)
* Todas as folhas estão no **mesmo nível** (árvore balanceada)

---

## 📌 3. Características

* Filhos da esquerda → valores menores que a chave
* Filhos da direita → valores maiores que a chave
* Filho do meio (quando existe) → valores entre as duas chaves

---

## 📌 4. Busca

```c
Busca(raiz, key):

se raiz == NULL:
    return NULL

se key == chaveEsq:
    return raiz

se numchaves == 2 e key == chaveDir:
    return raiz

se key < chaveEsq:
    return Busca(raiz->esq, key)

se numchaves == 1:
    return Busca(raiz->center, key)

se key < chaveDir:
    return Busca(raiz->center, key)

senão:
    return Busca(raiz->dir, key)
```

---

## 📌 5. Inserção

A inserção sempre ocorre em uma **folha**.

### 🔧 Passos

1. Encontrar a posição correta (como em árvore de busca)
2. Inserir na folha
3. Se o nó ficar com 3 chaves → ocorre **split** (divisão)

---

### 🧠 Exemplo

Inserindo elementos:

```text
A, C, E
```

Forma:

```text
[C]
/ \
[A] [E]
```

---

Inserindo mais elementos pode causar divisão e subida de chave.

---

## 📌 6. Complexidade

* Busca: O(log n)
* Inserção: O(log n)
* Remoção: O(log n)

---

## 📌 7. Remoção

A remoção é mais complexa e pode envolver reorganização.

### 🔧 Passos básicos

1. Remover o elemento
2. Se estiver em nó interno → substituir pelo sucessor
3. Se o nó ficar com 0 chaves → fazer:

   * Redistribuição (emprestar de irmão)
   * ou Fusão (merge)

---

### 🧠 Exemplo

```text
      [20]
     /    \
 [10]    [30]
```

Removendo 10:

* Nó fica vazio
* Pode pegar valor do irmão ou fundir

---

## 🚀 Resumo

* Árvore balanceada
* Nós com 1 ou 2 chaves
* Altura sempre equilibrada
* Operações em O(log n)
* Usa divisão (split) e fusão (merge)

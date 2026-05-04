# 🌳 Estrutura de Dados HEAP

---

## 1) 📌 Prioridade

- Atividades são realizadas com base na prioridade  

---

## 2) 📖 Definição

- Representa uma estrutura (geralmente um vetor) onde cada dado possui uma prioridade  
- Implementada como uma **árvore binária completa**

---

## 3) 🎯 Objetivo

Realizar de forma eficiente:

- Seleção do elemento de maior prioridade  
- Inserção de elemento  
- Remoção do maior elemento  
- Alteração de prioridade  

---

## 🏗️ Exemplo de Construção (Max-Heap)

### 📥 Entradas:
```
(90, 30, 60, 75, 30, 33, 23)
```

---

### 🔄 Passo a passo (inserção + subida)

#### 1) Inserir 90
```
90
```

---

#### 2) Inserir 30
```
   90
  /
30
```

---

#### 3) Inserir 60
```
   90
  /  \
30   60
```

---

#### 4) Inserir 75

- Entra no final → sobe pois 75 > 30

```
   90
  /  \
75   60
/
30
```

---

#### 5) Inserir 30
```
   90
  /  \
75   60
/ \
30 30
```

---

#### 6) Inserir 33

- 33 > 60? ❌ não sobe

```
   90
  /  \
75   60
/ \  /
30 30 33
```

---

#### 7) Inserir 23
```
   90
  /  \
75   60
/ \  / \
30 30 33 23
```

---

### ✔ Resultado final (Max-Heap)

```
        90
      /    \
    75      60
   /  \    /  \
 30   30  33  23
```

---

## 4) ⚙️ Propriedades

Para um índice `i`:

- Pai → `i / 2`  
- Filho esquerdo → `2 * i`  
- Filho direito → `2 * i + 1`  

---

## 5) 🔄 Alteração de Prioridade

- Sempre precisa reorganizar a HEAP

---

### 📈 Aumentar prioridade (Subir)

Exemplo: mudar **30 → 80**

```
Antes:
   90
  /
30

Depois:
   90
  /
80
```

✔️ Se maior que o pai → sobe

---

### 📉 Diminuir prioridade (Descer)

Exemplo: mudar **90 → 20**

```
Antes:
   90
  /  \
75   60

Depois:
   20
  /  \
75   60
```

➡️ 20 desce:

```
   75
  /  \
20   60
```

---

## 6) ➕ Inserção

### 📌 Passos:

1. Inserir no final (`n + 1`)  
2. Comparar com o pai  
3. Subir se necessário  

---

## 7) ➖ Remoção

### 📌 Passos:

1. Remove a raiz (maior valor)  
2. Coloca o último elemento na raiz  
3. Faz **heapify (descer)**  

---

### 📉 Exemplo de remoção

Remover 90:

```
Antes:
        90
      /    \
    75      60
   /  \    /  \
 30   30  33  23
```

➡️ Substitui por 23:

```
        23
      /    \
    75      60
   /  \    /  
 30   30  33
```

➡️ Desce:

```
        75
      /    \
    30      60
   /  \    /  
 23   30  33
```

---

## ✔ Resumo Final

- Heap = árvore binária completa  
- Pode ser:
  - Max-Heap (maior no topo)  
  - Min-Heap (menor no topo)  

- Operações:
  - Inserção → O(log n)  
  - Remoção → O(log n)  
  - Acesso ao topo → O(1)  

---

## 💡 Dica

Sempre que ver HEAP:

1. Pense em **árvore completa**
2. Inserção → sobe  
3. Remoção → desce  
4. Use os índices (`i/2`, `2i`, `2i+1`)  

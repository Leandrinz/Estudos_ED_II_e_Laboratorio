# 🌳 Árvores Genéricas em C (Baseado no Código abaixo)

## Código:
```c
    #include <stdlib.h>
typedef struct no{
    int valor;
    int nfilhos;
    struct no *filhos[10];
} No;

int main(){
    No *raiz = malloc(sizeof(No));
    raiz->valor = 1;
    raiz->nfilhos = 3;

    No *filho1 = malloc(sizeof(No));
    filho1->valor = 3;
    filho1->nfilhos = 2;

    No *filho2 = malloc(sizeof(No));
    filho2->valor = 2;
    filho2->nfilhos = 0;

    No *filho3 = malloc(sizeof(No));
    filho3->valor = 5;
    filho3->nfilhos = 0;

    No *filho4 = malloc(sizeof(No));
    filho4->valor = 4;
    filho4->nfilhos = 0;

    No *filho5 = malloc(sizeof(No));
    filho5->valor = 5;
    filho5->nfilhos = 0;

    raiz->filhos[0] = filho1;
    raiz->filhos[1] = filho2;
    raiz->filhos[2] = filho3;

    filho1->filhos[0] = filho4;
    filho1->filhos[1] = filho5;


    return 0;
}

```

---

## 📌 Estrutura do Nó

```c
typedef struct no{
    int valor;
    int nfilhos;
    struct no *filhos[10];
} No;
```

### 🔍 Explicação

- `valor` → guarda o dado do nó  
- `nfilhos` → quantidade de filhos que o nó possui  
- `filhos[10]` → vetor de ponteiros para os filhos  

✔️ Essa é uma **árvore genérica**, não binária  
➡️ Cada nó pode ter até **10 filhos**

---

## 🧠 Tipo de Estrutura

- 🌳 **Árvore N-ária (genérica)**
- Não é binária (pois não limita a 2 filhos)
- Estrutura dinâmica (usa `malloc`)

---

## 🏗️ Construção da Árvore

### 🌱 Raiz

```c
No *raiz = malloc(sizeof(No));
raiz->valor = 1;
raiz->nfilhos = 3;
```

✔️ Nó principal da árvore  
✔️ Possui 3 filhos  

---

### 🌿 Filhos da raiz

```c
filho1 → valor 3 → 2 filhos
filho2 → valor 2 → 0 filhos
filho3 → valor 5 → 0 filhos
```

---

### 🍃 Filhos do filho1

```c
filho4 → valor 4 → 0 filhos
filho5 → valor 5 → 0 filhos
```

---

## 🔗 Ligações (Ponteiros)

```c
raiz->filhos[0] = filho1;
raiz->filhos[1] = filho2;
raiz->filhos[2] = filho3;

filho1->filhos[0] = filho4;
filho1->filhos[1] = filho5;
```

✔️ Aqui acontece a **ligação da árvore**

---

## 🌳 Representação da Árvore

```
        1
      / | \
     3  2  5
    / \
   4   5
```

---

## 📊 Classificação da Árvore

- Tipo: **Árvore genérica**
- Altura: **2**
- Total de nós: **6**
- Folhas:
  - 2, 5, 4, 5

---


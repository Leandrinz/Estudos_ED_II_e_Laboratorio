# ⏱️ Cronometria de Algoritmos

📅 Aula: 23/03/2026

---

## 1️⃣ Por que analisar a complexidade

Analisar a complexidade é importante para:

- ✔ Comparar algoritmos e escolher o mais eficiente  
- ✔ Prever o comportamento com grandes entradas  
- ✔ Otimizar o código  
- ✔ Melhorar a **performance**

---

## 2️⃣ O que é complexidade

Complexidade define a **eficiência de um algoritmo**.

💡 Geralmente expressamos usando:

👉 **Big O (O-notation)**

---

## 3️⃣ Tabela de complexidades comuns

| Complexidade | Nome                  | Exemplo                         |
|-------------|----------------------|---------------------------------|
| O(1)        | Constante            | Acesso a vetor (`v[i]`)        |
| O(log n)    | Logarítmica          | Busca binária                  |
| O(n)        | Linear               | Percorrer vetor                |
| O(n log n)  | Linear logarítmica   | Merge Sort, Quick Sort         |
| O(n²)       | Quadrática           | Dois loops aninhados           |
| O(2ⁿ)       | Exponencial          | Fibonacci recursivo            |
| O(n!)       | Fatorial             | Problemas de permutação        |

---

## 4️⃣ Complexidade de Tempo x Espaço

### ⏱ Tempo
- Quanto tempo o algoritmo leva para executar

### 💾 Espaço
- Quanto de memória ele utiliza

---

### 🤔 Qual escolher?

Depende do problema:

- Pouca memória disponível → priorizar **tempo**
- Execução rápida não é crítica → economizar **memória**

💡 Muitas vezes é necessário fazer um **trade-off**

---

## 5️⃣ Big O (explicação básica)

Big O descreve o **comportamento do algoritmo** conforme a entrada cresce.

✔ Foca no pior caso  
✔ Ignora constantes  
✔ Considera apenas o crescimento

---

### 📌 Exemplos

```c
// O(1)
int x = v[0];
```

```c
// O(n)
for(int i = 0; i < n; i++){
    printf("%d\n", v[i]);
}
```

```c
// O(n²)
for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
        printf("%d %d\n", i, j);
    }
}
```

---

## 6️⃣ ⚠️ IMPORTANTE: Medindo tempo com clock()

```c
#include <stdio.h>
#include <time.h>

int main(){
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    // Código a ser cronometrado

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %f segundos\n", cpu_time_used);

    return 0;
}
```

---

## 7️⃣ Observações importantes sobre clock()

- Mede **tempo de CPU**, não tempo real absoluto  
- Pode variar dependendo do sistema  
- Ideal para testes simples e comparações  

---

## ✔ Conclusão

- Complexidade ajuda a entender a eficiência do algoritmo  
- Big O descreve o crescimento do custo  
- Tempo e espaço devem ser balanceados  
- `clock()` permite medir desempenho na prática  

---

## 💡 Dica final

👉 Saber **Big O + medir tempo** = combinação perfeita para escrever código eficiente
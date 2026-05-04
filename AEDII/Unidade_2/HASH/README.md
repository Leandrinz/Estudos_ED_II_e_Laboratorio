# 💾 Hash - Tabelas de Dispersão

---

## 📌 1. O que é Hash

O método de pesquisa conhecido como **hash** é utilizado para armazenar e acessar dados de forma rápida.

Ele é composto por duas etapas principais:

* A chave de pesquisa é transformada em um endereço da tabela
* O dado é armazenado ou recuperado nesse endereço

---

## 📌 2. Função Hash

A função hash é responsável por transformar uma chave em um índice.

```text
índice = função_hash(chave)
```

### 🧠 Exemplo simples

```text
chave = 25
índice = 25 % 10 → 5
```

---

## 📌 3. Tabela Hash

É uma estrutura de dados (geralmente um vetor) onde os elementos são armazenados.

```text
índice:   0 1 2 3 4 5 6 7 8 9
valores: [ , , , , ,25, , , , ]
```

---

## 📌 4. Colisões

Ocorrem quando duas chaves geram o mesmo índice.

### 🔧 Exemplo

```text
25 % 10 = 5
35 % 10 = 5  → colisão
```

---

## 📌 5. Formas de tratar colisões

### 🔗 Encadeamento (chaining)

Cada posição da tabela guarda uma lista de elementos.

```text
índice 5 → [25 → 35]
```

---

### 🔁 Endereçamento aberto

Procura outra posição livre na tabela.

* Linear
* Quadrático
* Duplo hash

---

## 📌 6. Vantagens

* Acesso muito rápido (em média O(1))
* Ideal para buscas frequentes

---

## 📌 7. Desvantagens

* Colisões podem ocorrer
* Pode desperdiçar memória
* Depende de uma boa função hash

---

## 📌 8. Aplicações

* Tabelas de símbolos (compiladores)
* Bancos de dados
* Cache
* Dicionários em linguagens (ex: Python)

---

## 📌 9. Métodos

### 🔢 Método da Divisão

Função hash:

```c
h(x) = x % M
```

* `x` → chave
* `M` → tamanho da tabela

⚠️ Observação:

* Evite valores pares ou múltiplos simples
* Prefira números **primos** para melhor distribuição

---

### 📄 Método da Dobra

A chave é dividida em partes e somada (sem considerar o “vai um”).

#### 🔧 Exemplo

```text
chave = 123456

Dividindo:
123 | 456

Somando:
123 + 456 = 579
```

---

### 🔢 Método da Dobra (Binário)

Versão da dobra usando a chave em binário:

* Converte a chave para binário
* Divide em partes iguais
* Combina (soma ou XOR)

🧠 Usado quando se quer melhor distribuição em sistemas computacionais.

---

### ✖️ Método da Multiplicação

```text
h(x) = ⌊ M * (x * A mod 1) ⌋
```

* `A` → constante entre 0 e 1 (ex: 0.618)
* `M` → tamanho da tabela

🧠 Vantagem: menos dependente do valor de `M`.

---

## 🚀 Resumo

* Hash transforma chave → índice
* Usa função hash
* Pode ter colisões
* Estrutura: tabela (vetor)
* Muito eficiente para busca

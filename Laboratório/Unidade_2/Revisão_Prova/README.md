# Hash & Filtro de Bloom — Guia de Estudo

**Plano:** leia este arquivo inteiro (≈1h), depois abra o `GABARITO.md` e tente reproduzir cada código sem olhar (≈1h).

---

## PARTE 1 — TABELA HASH

### O que é
Usa uma **função hash** para mapear uma chave diretamente a uma posição no vetor. Acesso direto — sem percorrer nada.

### Por que é melhor que árvore? (Q1)
| | Hash | Árvore AVL |
|---|---|---|
| Busca / Inserção / Remoção | **O(1) médio** | O(log n) |
| Mantém dados ordenados | Não | Sim |
| Pior caso | O(n) | O(log n) |

A hash ganha em velocidade média. A árvore ganha quando precisa de dados ordenados ou garantia no pior caso.

### Complexidade (Q2)
- **Caso médio:** O(1) para busca, inserção e remoção.
- **Pior caso:** O(n) — quando tudo colide no mesmo lugar (função hash ruim ou tabela lotada).

---

## PARTE 2 — FUNÇÕES HASH (Q3)

```
h(x) = x % m
h(x) = (ax + b) % m
```
O resultado sempre cai entre `0` e `m-1`.

### Q3a — h(x) = x % 13 — inserir: 18 41 22 44 59 32 31 73 85

| Chave | Conta | Pos | Situação |
|---|---|---|---|
| 18 | 18%13 | **5** | livre |
| 41 | 41%13 | **2** | livre |
| 22 | 22%13 | **9** | livre |
| 44 | 44%13 | **5** | ⚠️ colisão |
| 59 | 59%13 | **7** | livre |
| 32 | 32%13 | **6** | livre |
| 31 | 31%13 | **5** | ⚠️ colisão |
| 73 | 73%13 | **8** | livre |
| 85 | 85%13 | **7** | ⚠️ colisão |

### Q3b — h(x) = (3x+11) % 13

| Chave | 3x+11 | Pos | Situação |
|---|---|---|---|
| 18 | 65 | **0** | livre |
| 41 | 134 | **4** | livre |
| 22 | 77 | **12** | livre |
| 44 | 143 | **0** | ⚠️ colisão |
| 59 | 188 | **6** | livre |
| 32 | 107 | **3** | livre |
| 31 | 104 | **0** | ⚠️ colisão |
| 73 | 230 | **9** | livre |
| 85 | 266 | **6** | ⚠️ colisão |

> Como conferir: 65÷13=5 resto **0** ✓ | 134÷13=10 resto **4** ✓ | 266÷13=20 resto **6** ✓

### Q3c — mesma função (3x+11)%13, mas com sondagem linear sB (circular)

Quando colide, avança para a próxima posição livre circularmente.

| Chave | h(x) | Tentativas | Posição final |
|---|---|---|---|
| 18 | 0 | 0 livre | **0** |
| 41 | 4 | 4 livre | **4** |
| 22 | 12 | 12 livre | **12** |
| 44 | 0 | 0 ocupado → tenta 1 | **1** |
| 59 | 6 | 6 livre | **6** |
| 32 | 3 | 3 livre | **3** |
| 31 | 0 | 0,1 ocupados → tenta 2 | **2** |
| 73 | 9 | 9 livre | **9** |
| 85 | 6 | 6 ocupado → tenta 7 | **7** |

**Tabela final:**
```
[0]=18  [1]=44  [2]=31  [3]=32  [4]=41
[5]=--  [6]=59  [7]=85  [8]=--  [9]=73
[10]=-- [11]=-- [12]=22
```

---

## PARTE 3 — TRATAMENTO DE COLISÕES

### Sondagem Linear (Q4a, Q8)
```
posição = (h(x) + i) % m,   i = 0, 1, 2, ...
```
- **sA** — busca do `h(x)` até o **final** da tabela, sem reiniciar.
- **sB** — busca **circular**: chega no final e reinicia do índice 0.

> ⚠️ **Remoção:** nunca apague diretamente. Marque como `DELETADO` (tombstone).
> Se apagar, a busca para ali e não encontra elementos que estão além.

### Sondagem Quadrática (Q4b, Q9)
```
posição = (h(x) + i²) % m,   i = 0, 1, 2, ...
```
Mesma lógica do linear. Só muda o incremento: `1, 4, 9, 16...` em vez de `1, 2, 3, 4...`
Reduz agrupamento, mas pode não cobrir todas as posições se `m` não for primo.

### Duplo Hash (Q4c)
```
posição = (h1(x) + i × h2(x)) % m
```
`h2(x)` nunca pode ser 0. Exemplo: `h2(x) = 7 - (x % 7)`
Cada chave tem um caminho diferente — melhor distribuição.

### Encadeamento (Q10)
Cada posição é uma **lista ligada**. Colisões viram nós extras.
Vantagem: remoção simples, sem limite de fator de carga.
Desvantagem: memória extra com ponteiros.

### Resumo vantagens/desvantagens (Q7)
| Método | Vantagem | Desvantagem |
|---|---|---|
| Linear | Simples, cache-friendly | Agrupamento primário (clusters) |
| Quadrática | Menos agrupamento | Pode não cobrir todas posições |
| Duplo hash | Melhor distribuição | Mais complexo de implementar |
| Encadeamento | Remoção fácil, sem limite de α | Memória extra, cache ruim |

---

## PARTE 4 — FATOR DE CARGA (Q6)

```
α = n / m       (n = elementos inseridos, m = tamanho da tabela)
```

**Probabilidade de colidir** ao inserir um elemento = fração de posições ocupadas.
Com α = 0.30 → P(colisão) = 30% para cada nova inserção.

**Simulação da Q6:**
- Tabela com `m` posições, 30% ocupadas.
- Tenta inserir mais 5%. Se colidir, não insere.
- ~30% dessas tentativas vão colidir (a tabela está 30% cheia).
- Fator de carga final ≈ **30% + 70% de 5% ≈ 33.5%**

---

## PARTE 5 — HASH DE PLACAS (Q5)

### Como raciocinar (importante para adaptar a qualquer formato)

Placa `ABC1D23` tem 7 posições. Cada posição tem um número de valores possíveis:
- Letra: 26 (A–Z)
- Dígito: 10 (0–9)

**Total de placas** = 26 × 26 × 26 × 10 × 26 × 10 × 10 = **456.976.000**

Para converter em número único, trate como um número em base mista (igual a converter horas/minutos em segundos):

```
n = 0
n = n * 26 + (p[0]-'A')   → 1ª letra
n = n * 26 + (p[1]-'A')   → 2ª letra
n = n * 26 + (p[2]-'A')   → 3ª letra
n = n * 10 + (p[3]-'0')   → dígito
n = n * 26 + (p[4]-'A')   → 4ª letra
n = n * 10 + (p[5]-'0')   → dígito
n = n * 10 + (p[6]-'0')   → dígito
```

- **25% das posições:** `n % 114.244.000`
- **Placa antiga ABC1234** → total = 26³ × 10⁴ = 175.760.000 → **12,5%:** `n % 21.970.000`

---

## PARTE 6 — FILTRO DE BLOOM

### O que é
Estrutura de **vetor de bits** que responde: "este elemento está no conjunto?"

- Resposta **NÃO** → certeza absoluta que não está.
- Resposta **SIM** → *provavelmente* está (pode ser falso positivo).
- **Nunca** produz falso negativo.
- Não armazena os elementos — só bits.

### Parâmetros
| Símbolo | Significado |
|---|---|
| `m` | Total de bits no filtro |
| `k` | Número de funções hash |
| `n` | Número de elementos inseridos |
| `Pfp` | Probabilidade de falso positivo |

### Como funciona

**Inserção de `x`:** aplica as `k` funções hash e seta cada bit resultante para 1.

**Consulta de `y`:** aplica as `k` funções hash e verifica os bits.
- Todos os bits são 1 → "provavelmente presente"
- Qualquer bit for 0 → "certamente ausente"

### Fórmulas (Q15, Q16)

```
Pfp  ≈ (1 - e^(-kn/m))^k

k ótimo = (m/n) × ln2  ≈  0.693 × (m/n)

m = -(n × ln(Pfp)) / (ln2)²
  = -(n × ln(Pfp)) / 0.4805
```

### Q16 resolvido — n=128, k=3, Pfp < 2%

**Passo 1 — calcular m:**
```
m = -(128 × ln(0.02)) / 0.4805
  = -(128 × (-3.912)) / 0.4805
  = 500.7 / 0.4805
  ≈ 1042 bits
```

**Passo 2 — verificar se 1042 garante Pfp < 2% com k=3:**
```
Pfp = (1 - e^(-3×128/1042))^3
    = (1 - e^(-0.368))^3
    = (1 - 0.692)^3
    = (0.308)^3
    ≈ 2.9%  → ainda acima de 2%
```

**Passo 3 — aumentar m até garantir:**
```
m = 1300 bits:
Pfp = (1 - e^(-3×128/1300))^3
    = (1 - e^(-0.295))^3
    = (0.256)^3
    ≈ 1.68%  ✓ abaixo de 2%
```
**Usar m = 1300 bits (163 bytes).**

### Q15 resolvido — m=8192 bits, Pfp ≤ 5%, achar n máximo

Isola `n` da fórmula de `m`:
```
n = -(m × (ln2)²) / ln(Pfp)
  = -(8192 × 0.4805) / ln(0.05)
  = -3936 / (-2.996)
  ≈ 1314 elementos
```

### Operações bit a bit — essencial para Q14 e Q21

```
índice global = h(x) % total_de_bits

// Vetor de char (8 bits por elemento):
byte = índice / 8
bit  = índice % 8
setar:     filtro[byte] |=  (1 << bit)
verificar: (filtro[byte] >> bit) & 1

// Vetor de unsigned int (32 bits por elemento):
posicao = índice / 32
desl    = índice % 32
setar:     filtro[posicao] |=  (1u << desl)
verificar: (filtro[posicao] >> desl) & 1u
```

### Q14 resolvido — h(x) = (3x+7), filtro de 16 bytes

```
x = 10:
  índice = (3×10 + 7) % 128 = 37
  byte   = 37 / 8 = 4
  bit    = 37 % 8 = 5
  → setar bit 5 do byte 4: filtro[4] |= (1 << 5)

x = 0:
  índice = 7 % 128 = 7  → byte 0, bit 7

x = 40:
  índice = 127 % 128 = 127  → byte 15, bit 7
```

### Q21 — Little-endian influencia o filtro?

**Não.** Operações bit a bit em C (`>>`, `<<`, `|`, `&`) trabalham na representação lógica do inteiro, consistente em qualquer arquitetura. Little-endian só afeta como bytes são dispostos fisicamente na memória — invisível para o código C. Só seria problema ao salvar/ler o filtro em arquivo entre máquinas com endianness diferentes.

### Geração de funções hash (Q11)

Formato pedido: `h(x) = (ax + b) % K`, com `a` e `b` primos.

Basta gerar números primos em sequência e distribuir como coeficientes.

### Cobertura total da tabela (Q12)

`h(x) = (ax + b) % K` cobre **todas** as K posições se e somente se `mdc(a, K) = 1`.

> Exemplo: K=128=2⁷. Se a=2, mdc(2,128)=2 ≠ 1 → **não** cobre tudo. Se a=3, mdc(3,128)=1 → cobre tudo ✓.

### Q20 — Crivo de Eratóstenes vs Crivo + Bloom

| | Crivo Tradicional | Crivo + Bloom |
|---|---|---|
| Para **gerar** todos os primos | ✅ Ideal, O(n log log n), sem erro | ❌ Não faz sentido (bloom não lista) |
| Para **verificar** um número | O(1) após crivo (array de bool) | O(k) — rápido e pouco memória |
| Falsos positivos | Zero | Possível (configurável) |
| Memória | 1 bit por número (exato) | Pode ser menor para n grande com Pfp tolerável |

**Conclusão:** Para gerar a lista completa de primos, o crivo tradicional é mais simples e exato. O Bloom é vantajoso quando a memória é crítica e uma pequena taxa de erro é aceitável — verificar pontualmente se um número é primo sem armazenar todos eles.

---

> Código de todas as implementações → [`GABARITO.md`](GABARITO.md)
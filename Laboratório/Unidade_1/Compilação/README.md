# ⚙️ Compilação em C

## 1) Compilação

## 1.1) Compilação Padrão

Para compilar um programa em C usando **GCC**:

```bash
gcc programa.c -o programa
```

Explicação:

- `gcc` → compilador
- `programa.c` → arquivo de código fonte
- `-o programa` → nome do executável gerado

---

## 1.2) Compilação para Depuração

Para permitir **debug com GDB**, compilamos o programa a flag `-g`:

```bash
gcc -g programa.c -o programa
```

Essa flag inclui **informações de depuração** no executável.

---

## 2) Execução

## 2.1) Execução Simples

```bash
./programa
```

O `./` indica que o executável está **no diretório atual**.

---

## 2.2) Execução com Debugger - GDB

Para executar usando o **GDB (GNU Debugger)**:

```bash
gdb ./programa
```

---

# 💡 Dica de Atalho

Compilar **e executar em um único comando**:

```bash
gcc programa.c -o programa && ./programa
```

O `&&` é um operador que significa "execute o segundo comando apenas se o primeiro funcionar".

---

# 🐞 Comandos de Fluxo — GDB

## Break [ponto]

> 💡 Também pode ser abreviado como `b`.

Adiciona um ponto de interrupção (breakpoint) para o depurador.
Pode ser chamado com `codigo:linha` ou pelo nome de uma função existente.

Exemplos:

```
break main
```

```
break programa.c:15
```

## Run [argumentos]

> 💡 Também pode ser abreviado como `r`.

Inicia a execução do programa.
É recomendado colocar um breakpoint antes.

Exemplos:

```bash
run
```

```bash
# Passando argumentos para o programa
run argumento1 argumento2
```

## Next

> 💡 Também pode ser abreviado como `n`.

Executa **a próxima linha**, mas **não entra dentro de funções**.

`[Linha 23]` &rarr; `next` &rarr; `[Linha 24]`.

---

## Step

> 💡 Também pode ser abreviado como `s`.

Executa a próxima linha **entrando dentro da função** chamada.

`[Linha 23] (Chamada de X)` &rarr; `step` &rarr; `[Linha 5] (Declaração de X)`.

---

## Continue

> 💡 Também pode ser abreviado como `c`.

Continua a execução **até o próximo breakpoint ou até o fim do programa**.

`[Linha 23]` &rarr; `continue` &rarr; `[Última Linha]`.

---

## Quit

> 💡 Também pode ser abreviado como `q`.

Encerra instantaneamente o programa.

`[Linha 23]` &rarr; `quit` &rarr; `[Programa Interrompido]`.

---

## Layout

> [!NOTE]
> Esse recurso está disponível apenas em sistemas Linux.

Permite visualizar seu código pelo terminal durante a depuração.

Exemplos:

```bash
# Mostra o código fonte em C
layout src
```

```bash
# Mostra o código fonte em Assembly
layout asm
```

Para fechar o layout basta usar a combinação `Ctrl` + `X`, seguida da tecla `A`.

# ✔ Resumo

| Comando    | Função                 |
| ---------- | ---------------------- |
| gcc        | Compilar programa.     |
| ./programa | Executar programa.     |
| gdb        | Depurar programa.      |
| break      | Adiciona breakpoints.  |
| run        | Executar depuração.    |
| next       | Próxima linha.         |
| step       | Entrar em funções.     |
| continue   | Continuar depuração.   |
| quit       | Interromper depuração. |
| layout     | Exibir código.         |

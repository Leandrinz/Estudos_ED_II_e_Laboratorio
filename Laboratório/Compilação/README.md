# ⚙️ Compilação em C

# 1) Compilação

## 1.1) Compilação Padrão

Para compilar um programa em C usando **GCC**:

```bash
gcc programa.c -o programa
```

Explicação:

- `gcc` → compilador
- `programa.c` → arquivo fonte
- `-o programa` → nome do executável gerado

---

## 1.2) Compilação para Depuração

Para permitir **debug com GDB**, usamos a flag `-g`:

```bash
gcc -g programa.c -o programa
```

Essa flag inclui **informações de depuração** no executável.

---

# 2) Execução

## 2.1) Execução Simples

```bash
./programa
```

O `./` indica que o executável está **no diretório atual**.

---

## 2.2) Execução com Debugger

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

O `&&` significa:

```
execute o segundo comando apenas se o primeiro funcionar
```

---

# 🐞 Comandos de Fluxo — GDB

## 1) run [args]

Inicia a execução do programa.

```bash
run
```

ou passando argumentos:

```bash
run argumento1 argumento2
```

---

## 2) next

Executa **a próxima linha**, mas **não entra dentro de funções**.

---

## 3) step

Executa a próxima linha **entrando dentro da função** chamada.

---

## 4) continue

Continua a execução **até o próximo breakpoint ou até o fim do programa**.

---

## 5) finish

Termina a execução da **função atual** e volta para quem a chamou.

---

## 6) quit

Sai do **GDB**.

```bash
quit
```

---

# ✔ Resumo

| Comando | Função |
|------|------|
gcc | Compilar programa |
./programa | Executar programa |
gdb | Depurar programa |
run | Iniciar execução |
next | Próxima linha |
step | Entrar em função |
continue | Continuar execução |
finish | Sair da função |
quit | Sair do debugger |
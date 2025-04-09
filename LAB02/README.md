# Grupo 7 - Relatório do Laboratório

## Integrantes

- Isabela Garcia Godinho
- João Victor Azevedo dos Santos
- Yago Péres dos Santos

### Laboratório 02

Sala: 1002 - Turma A - 0225

---

## Lista de Arquivos Enviados

### Parte 1 - Léxico

- `parte1-lexico/`
  - `main.c`
  - `permissao.c`
  - `permissao.h`
  - `conversor.c`
  - `conversor.h`
  - `combinado`

### Parte 2 - Ponteiros

- `parte2-pointer/`
  - `ex1`
  - `ex1.c`
  - `ex2_int`
  - `ex2-int.c`
  - `ex2_float`
  - `ex2-float.c`
  - `ex3`
  - `ex3.c`

### Parte 3 - Compilador

- `parte3-compiler/`
  - `compiler.c`
  - `compiler.h`
  - `cprocess.c`
  - `lex_process.c`
  - `lexer.c`
  - `main.c`
  - `Makefile`
  - `test.c`
  - `test.h`
  - `build/`
    - `compiler.o`
    - `cprocess.o`
    - `lex_process.o`
    - `lexer.o`
    - `helpers/`
      - `buffer.o`
      - `vector.o`
  - `helpers/`
    - `buffer.c`
    - `buffer.h`
    - `vector.c`
    - `vector.h`

### Parte 4 - Léxico

- `parte4-lex/`
  - `compiler.c`
  - `compiler.h`
  - `cprocess.c`
  - `lex_process.c`
  - `lexer.c`
  - `main.c`
  - `Makefile`
  - `test.c`
  - `outtest`
  - `build/`
    - `compiler.o`
    - `cprocess.o`
    - `lex_process.o`
    - `lexer.o`
    - `helpers/`
      - `buffer.o`
      - `vector.o`
  - `helpers/`
    - `buffer.c`
    - `buffer.h`
    - `vector.c`
    - `vector.h`

---

## Descrição do Trabalho Realizado

Neste laboratório, foram desenvolvidas diversas atividades relacionadas à manipulação de ponteiros, análise léxica e implementação de um compilador básico. As principais atividades realizadas incluem:

1. **Parte 1 - Léxico**:

   - Implementação de programas para manipulação de permissões e conversão de tipos de dados utilizando `union`.
   - Criação de funções para exibir valores em formato binário e hexadecimal.

2. **Parte 2 - Ponteiros**:

   - Desenvolvimento de programas que utilizam ponteiros para implementar operações matemáticas básicas.
   - Uso de arrays de ponteiros para funções e manipulação de tipos `int` e `float`.

3. **Parte 3 - Compilador**:

   - Expansão do compilador básico com a inclusão de análise léxica.
   - Implementação de funções para leitura de tokens, incluindo números, strings, palavras-chave, operadores e símbolos.
   - Modularização do código com o uso de `helpers` para buffers e vetores dinâmicos.

4. **Parte 4 - Léxico**:
   - Implementação de um analisador léxico completo para identificar tokens em um arquivo de entrada.
   - Criação de funções para lidar com comentários, palavras-chave, operadores e símbolos.
   - Testes de integração para validar a funcionalidade do analisador léxico.

---

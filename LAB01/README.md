# Grupo 7 - Relatório do Laboratório

## Integrantes

- Isabela Garcia Godinho
- João Victor Azevedo dos Santos
- Yago Péres dos Santos

### Laboratório 01

Sala: 1002 - Turma A - 0225

---

## Lista de Arquivos Enviados

- **src/**
  - [`compiler.c`](src/compiler.c)
  - [`compiler.h`](src/compiler.h)
  - [`cprocess.c`](src/cprocess.c)
  - [`main`](src/main)
  - [`main.c`](src/main.c)
  - [`Makefile`](src/Makefile)
  - [`test.c`](src/test.c)
  - [`test.h`](src/test.h)
  - **build/**
    - `compiler.o`
    - `cprocess.o`
    - `test.o`
    - **helpers/**
      - `buffer.o`
      - `vector.o`
  - **helpers/**
    - [`buffer.c`](src/helpers/buffer.c)
    - [`buffer.h`](src/helpers/buffer.h)
    - [`vector.c`](src/helpers/vector.c)
    - [`vector.h`](src/helpers/vector.h)

---

## Descrição do Trabalho Realizado

Neste laboratório, foi desenvolvido um compilador básico com funcionalidades de análise léxica e manipulação de estruturas auxiliares. As principais atividades realizadas incluem:

### Estruturas Auxiliares

- **Vetores Dinâmicos (`vector`)**:
  - Implementação de funções para criação, manipulação e leitura de vetores dinâmicos.
  - Localizadas em [`vector.c`](src/helpers/vector.c) e [`vector.h`](src/helpers/vector.h).
- **Buffers (`buffer`)**:
  - Criação de funções para manipulação de buffers dinâmicos.
  - Localizadas em [`buffer.c`](src/helpers/buffer.c) e [`buffer.h`](src/helpers/buffer.h).

### Testes

- Desenvolvimento de funções de teste para validar as operações de vetores e buffers, bem como a funcionalidade de compilação, no arquivo [`test.c`](src/test.c).

### Processo de Compilação

- Criação de um processo de compilação básico no arquivo [`compiler.c`](src/compiler.c), com suporte para leitura e escrita de arquivos.

### Automação

- Configuração de um [`Makefile`](src/Makefile) para automatizar a compilação dos arquivos e geração do executável principal.

### Modularização

- Estruturação do código em módulos para facilitar a manutenção e a expansão futura.

---

## Entregas Solicitadas

### 1. Testes Realizados dos Vetores

Os testes realizados para as funções de manipulação de vetores foram executados com sucesso. Abaixo estão os resultados:

```plaintext
Compiladores - TURMA A - GRUPO 7
Teste vector_create() passou!
Teste vector_push() passou!
Teste vector_pop() passou!
Teste vector_set_peek_pointer() passou!
Teste vector_peek() passou!
Teste compile_file() passou!
```

### 2. Funcionamento do Makefile

O [`Makefile`](src/Makefile) foi configurado para compilar os arquivos do projeto e gerar o executável principal. Abaixo está um exemplo do funcionamento:

```plaintext
gcc ./compiler.c -I./ -o ./build/compiler.o -g -c
gcc ./cprocess.c -I./ -o ./build/cprocess.o -g -c
gcc ./helpers/buffer.c -I./ -o ./build/helpers/buffer.o -g -c
gcc ./helpers/vector.c -I./ -o ./build/helpers/vector.o -g -c
gcc ./test.c -I./ -o ./build/test.o -g -c
gcc main.c -I./ ./build/compiler.o ./build/cprocess.o ./build/helpers/buffer.o ./build/helpers/vector.o ./build/test.o -g -o ./main
```

---

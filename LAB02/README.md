# Grupo 7 - Relatório do Laboratório

## Integrantes

- Isabela Garcia Godinho
- João Victor Azevedo dos Santos
- Yago Péres dos Santos

### Laboratório 02

Sala: 1002 - Turma A - 0225

---

## Lista de Arquivos Enviados

- **src/**
  - [`compiler.c`](src/compiler.c)
  - [`compiler.h`](src/compiler.h)
  - [`cprocess.c`](src/cprocess.c)
  - [`lex_process.c`](src/lex_process.c)
  - [`lexer.c`](src/lexer.c)
  - [`main`](src/main)
  - [`main.c`](src/main.c)
  - [`Makefile`](src/Makefile)
  - [`test.c`](src/test.c)
  - **build/**
    - `compiler.o`
    - `cprocess.o`
    - `lex_process.o`
    - `lexer.o`
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

Neste laboratório, foi desenvolvido o núcleo do analisador léxico para o compilador, com foco na identificação e classificação de tokens. As principais atividades realizadas incluem:

### Estruturas Auxiliares

- **Vetores Dinâmicos (`vector`)**: Funções para criação e manipulação de vetores dinâmicos, localizadas em [`vector.c`](src/helpers/vector.c) e [`vector.h`](src/helpers/vector.h).
- **Buffers (`buffer`)**: Manipulação de buffers dinâmicos para leitura sequencial de caracteres, em [`buffer.c`](src/helpers/buffer.c) e [`buffer.h`](src/helpers/buffer.h).

### Núcleo do Compilador

- **Processamento de Compilação**: [`compiler.c`](src/compiler.c), [`compiler.h`](src/compiler.h) e [`cprocess.c`](src/cprocess.c) implementam a estrutura base do compilador.
- **Função Principal**: [`main.c`](src/main.c) contém o ponto de entrada do programa e a integração com o processo de análise léxica.

### Análise Léxica

- **Processamento Léxico**: [`lex_process.c`](src/lex_process.c) implementa as funções de gerenciamento do processo de análise léxica, incluindo criação, liberação de memória e acesso aos tokens.
- **Analisador Léxico**: [`lexer.c`](src/lexer.c) contém a implementação completa do lexer, incluindo a função `read_next_token()` responsável por identificar e classificar todos os tipos de tokens.

### Automação

- **Makefile**: [`Makefile`](src/Makefile) configurado para compilar todos os módulos e gerar o executável principal, incluindo os novos arquivos `lex_process.c` e `lexer.c`.

---

## Entregas Solicitadas

### **Atividade 1 - Adicionar os arquivos novos ao Makefile**

Implementação e integração dos arquivos `lex_process.c` e `lexer.c` ao processo de compilação:

- **`lex_process.c`**: Funções para criação, gerenciamento e liberação do processo de análise léxica
- **`lexer.c`**: Implementação inicial da função `lex()`
- **`Makefile`**: Atualizado para incluir os novos objetos `lex_process.o` e `lexer.o`

**Resultado da Compilação:**

```bash
❯ make all
gcc ./compiler.c -I./ -o ./build/compiler.o -g -c
gcc ./cprocess.c -I./ -o ./build/cprocess.o -g -c
gcc ./helpers/buffer.c -I./ -o ./build/helpers/buffer.o -g -c
gcc ./helpers/vector.c -I./ -o ./build/helpers/vector.o -g -c
gcc ./lex_process.c -I./ -o ./build/lex_process.o -g -c
gcc ./lexer.c -I./ -o ./build/lexer.o -g -c
gcc main.c -I./ ./build/compiler.o ./build/cprocess.o ./build/helpers/buffer.o ./build/helpers/vector.o ./build/lex_process.o ./build/lexer.o -g -o ./main
```

### **Atividade 2 - Implementação Completa do Analisador Léxico**

Desenvolvimento da função `read_next_token()` para identificar e classificar os seguintes tipos de tokens:

- **TOKEN_TYPE_KEYWORD**: Palavras-chave da linguagem C (`int`, `float`, `if`, `for`, etc.)
- **TOKEN_TYPE_IDENTIFIER**: Identificadores de variáveis e funções (`main`, `printf`, `a`, `b`, etc.)
- **TOKEN_TYPE_OPERATOR**: Operadores aritméticos e relacionais (`+`, `-`, `*`, `/`, `=`, `<`, `>`, etc.)
- **TOKEN_TYPE_SYMBOL**: Símbolos de pontuação (`{`, `}`, `;`, `,`, etc.)
- **TOKEN_TYPE_NUMBER**: Literais numéricos (`10`, `20.5`, etc.)
- **TOKEN_TYPE_STRING**: Literais de string (`"Hello World"`, etc.)
- **TOKEN_TYPE_COMMENT**: Comentários de linha (`//`) e bloco (`/* */`)
- **TOKEN_TYPE_NEWLINE**: Quebras de linha

### Teste de Validação

**Arquivo de entrada (`test.c`):**

```c
#include <stdio.h>

/* Comentário de bloco */

int main() {
  int a = 10;
  float b = 20.5;
  char c = 'x';

  // Operadores
  a = a + b - c * 2 / 1;

  // Controle de fluxo
  if (a > b) {
    printf("a é maior que b\n");
  } else {
    printf("b é maior ou igual a a\n");
  }

  // Laços
  for (int i = 0; i < 10; i++) {
    printf("Valor de i: %d\n", i);
  }

  // Operadores e símbolos adicionais
  a = (b + c) * 2;
  int arr[5] = {1, 2, 3, 4, 5};

  return 0;
}
```

**Resultado da análise léxica:**

```bash
❯ ./main test.c
Compiladores - TURMA A - GRUPO 7
Token: # (SYMBOL)
Token: include (KEYWORD)
Token: stdio.h (IDENTIFIER)
Token: int (KEYWORD)
Token: main (IDENTIFIER)
Token: ( (OPERATOR)
Token: ) (SYMBOL)
Token: { (SYMBOL)
Token: int (KEYWORD)
Token: a (IDENTIFIER)
Token: = (OPERATOR)
Token: 10 (NUMBER)
Token: ; (SYMBOL)
[... análise completa do arquivo ...]
Todos os arquivos foram compilados com sucesso!
```

---

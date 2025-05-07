# Grupo 7 - Relatório do Laboratório

## Integrantes

- Isabela Garcia Godinho
- João Victor Azevedo dos Santos
- Yago Péres dos Santos

### Laboratório 03

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
  - [`node.c`](src/node.c)
  - [`outtest`](src/outtest)
  - [`parser.c`](src/parser.c)
  - [`parser.h`](src/parser.h)
  - [`test.c`](src/test.c)
  - **build/**
    - `compiler.o`
    - `cprocess.o`
    - `lex_process.o`
    - `lexer.o`
    - `parser.o`
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

O trabalho realizado no Laboratório 03 consistiu na ampliação e refinamento do analisador léxico e na implementação inicial do analisador sintático para o compilador. As principais atividades desenvolvidas foram:

### Análise Léxica

- **Leitura de Tokens**: Finalizada a implementação de todos os tipos de tokens
- **Suporte a Literais Numéricos**:
  - Implementado suporte para números hexadecimais e números binários

### Análise Sintática

- **Conceitos Básicos**:
  - Implementação inicial do parser, responsável por construir a árvore de sintaxe abstrata (AST) a partir dos tokens gerados pelo lexer.
  - Estruturas criadas para representar nós da AST, como `FUNCTION_NODE`, `VARIABLE_NODE`, `EXPRESSION_NODE`, entre outros.

**Atualizações no Código**:

- [`compiler.h`](src/compiler.h): Adicionadas estruturas para suportar o parser.
- [`cprocess.c`](src/cprocess.c): Atualizado para inicializar corretamente as novas estruturas.
- [`parser.c`](src/parser.c) e [`node.c`](src/node.c): Criados e adicionados ao [`Makefile`](src/Makefile) para compilar o projeto.

---

## Entregas Solicitadas

- Código-fonte completo do analisador léxico e sintático, incluindo suporte para números hexadecimais e binários.
- Arquivo `Makefile` atualizado para compilar o projeto, incluindo os novos arquivos `parser.c` e `node.c`.
- Arquivo de teste (`test.c`) para validar o funcionamento do compilador, cobrindo os novos casos de análise léxica e sintática.

### **Atividade 1 - Implementação de Todos os Tipos de Tokens**

Implementação dos tokens necessários para identificar e classificar elementos do código-fonte, como:

- `SY`: Símbolos
- `KW`: Palavras-chave
- `ST`: Strings
- `ID`: Identificadores
- `OP`: Operadores
- `NU`: Números
- `NL`: Quebras de linha

**_Função read_next_token atualizada_**

```C++
struct token *read_next_token()
{
    struct token *token = NULL;
    char c = peekc();

    token = handle_comment();
    if (token)
        return token;

    switch (c)
    {
    case EOF: /**/
        break;

    NUMERIC_CASE:
        token = token_make_number();
        break;

    SYMBOL_CASE:
        token = token_make_symbol();
        break;

    OPERATOR_CASE:
        token = token_make_operator_or_string();
        break;

    case '"':
        token = token_make_string('"', '"');
        break;

    case '\t':
    case ' ':
        token = handle_whitespace();
        break;

    case '\n':
        token = token_make_newline();
        break;

    default:
        token = read_special_token();
        if (!token)
        {
            compiler_error(lex_process->compiler, "Token invalido!\n");
        }
        break;
    }
    return token;
}
```

_Código extraído em [`lexer.c`](src/lexer.c)._

### **Atividade 2 - Realização de testes**

Teste do código-fonte para validar o funcionamento do lexer e a correta leitura de tokens

#### Teste 1

```C
#include <stdio.h>

// teste de comentario

int main()
{
    printf("Hello World!");

    return 0;
}

/* teste de comentario 2 */
```

_output:_

```Text
❯ ./main
Compiladores - TURMA A - GRUPO 7
TOKEN   SY: #
TOKEN   KW: include
TOKEN   ST: stdio.h
TOKEN   NL
TOKEN   NL
TOKEN   NL
TOKEN   NL
TOKEN   KW: int
TOKEN   ID: main
TOKEN   OP: (
TOKEN   SY: )
TOKEN   NL
TOKEN   SY: {
TOKEN   NL
TOKEN   ID: printf
TOKEN   OP: (
TOKEN   ST: Hello, World!
TOKEN   SY: )
TOKEN   SY: ;
TOKEN   NL
TOKEN   NL
TOKEN   KW: return
TOKEN   NU: 0
TOKEN   SY: ;
TOKEN   NL
TOKEN   SY: }
TOKEN   NL
TOKEN   NL
Todos os arquivos foram compilados com sucesso!
```

#### Teste 2

```C
#include <stdio.h>

int main()
{
    int a = 1;
    float b = 2;
    double c = 3;

    return a + b * c;
}
```

_output:_

```Text
❯ ./main
Compiladores - TURMA A - GRUPO 7
TOKEN   SY: #
TOKEN   KW: include
TOKEN   ST: stdio.h
TOKEN   NL
TOKEN   NL
TOKEN   KW: int
TOKEN   ID: main
TOKEN   OP: (
TOKEN   SY: )
TOKEN   NL
TOKEN   SY: {
TOKEN   NL
TOKEN   KW: int
TOKEN   ID: a
TOKEN   OP: =
TOKEN   NU: 1
TOKEN   SY: ;
TOKEN   NL
TOKEN   KW: float
TOKEN   ID: b
TOKEN   OP: =
TOKEN   NU: 2
TOKEN   SY: ;
TOKEN   NL
TOKEN   KW: double
TOKEN   ID: c
TOKEN   OP: =
TOKEN   NU: 3
TOKEN   SY: ;
TOKEN   NL
TOKEN   NL
TOKEN   KW: return
TOKEN   ID: a
TOKEN   OP: +
TOKEN   ID: b
TOKEN   OP: *
TOKEN   ID: c
TOKEN   SY: ;
TOKEN   NL
TOKEN   SY: }
Todos os arquivos foram compilados com sucesso!
```

#### Teste 3

```C
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 1;
    float b = 2;
    double c = 3;

    // teste de comentario

    return (a + b) / c;
}
```

_output:_

```Text
❯ ./main
Compiladores - TURMA A - GRUPO 7
TOKEN   SY: #
TOKEN   KW: include
TOKEN   ST: stdio.h
TOKEN   NL
TOKEN   SY: #
TOKEN   KW: include
TOKEN   ST: stdlib.h
TOKEN   NL
TOKEN   NL
TOKEN   KW: int
TOKEN   ID: main
TOKEN   OP: (
TOKEN   SY: )
TOKEN   NL
TOKEN   SY: {
TOKEN   NL
TOKEN   KW: int
TOKEN   ID: a
TOKEN   OP: =
TOKEN   NU: 1
TOKEN   SY: ;
TOKEN   NL
TOKEN   KW: float
TOKEN   ID: b
TOKEN   OP: =
TOKEN   NU: 2
TOKEN   SY: ;
TOKEN   NL
TOKEN   KW: double
TOKEN   ID: c
TOKEN   OP: =
TOKEN   NU: 3
TOKEN   SY: ;
TOKEN   NL
TOKEN   NL
TOKEN   NL
TOKEN   NL
TOKEN   KW: return
TOKEN   OP: (
TOKEN   ID: a
TOKEN   OP: +
TOKEN   ID: b
TOKEN   SY: )
TOKEN   OP: /
TOKEN   ID: c
TOKEN   SY: ;
TOKEN   NL
TOKEN   SY: }
Todos os arquivos foram compilados com sucesso!
```

### **Atividade 3 - Implementar e Converter Números Hexadecimais e Números Binários**

Foi adicionada a capacidade de reconhecer e converter números hexadecimais e binários.

**Função read_number_str e read_number atualizadas**

```C++
const char *read_number_str()
{
    struct buffer *buffer = buffer_create();
    char c = peekc();

    // Verifica prefixos para hexadecimal ou binário
    if (c == '0')
    {
        buffer_write(buffer, nextc()); // Consome o '0'
        c = peekc();
        if (c == 'x' || c == 'X') // Hexadecimal
        {
            buffer_write(buffer, nextc()); // Consome o 'x'
            LEX_GETC_IF(buffer, c, (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
        }
        else if (c == 'b' || c == 'B') // Binário
        {
            buffer_write(buffer, nextc()); // Consome o 'b'
            LEX_GETC_IF(buffer, c, (c == '0' || c == '1'));
        }
        else
        {
            // Não é hexadecimal ou binário, continua como número normal
            LEX_GETC_IF(buffer, c, (c >= '0' && c <= '9'));
        }
    }
    else
    {
        // Número decimal normal
        LEX_GETC_IF(buffer, c, (c >= '0' && c <= '9'));
    }

    // Finaliza a string
    buffer_write(buffer, 0x00);
    return buffer_ptr(buffer);
}

unsigned long long read_number()
{
    const char *s = read_number_str();

    // Detecta o prefixo e converte para decimal
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        return strtoull(s, NULL, 16); // Hexadecimal
    }
    else if (s[0] == '0' && (s[1] == 'b' || s[1] == 'B'))
    {
        return strtoull(s + 2, NULL, 2); // Binário (ignora o "0b")
    }
    else
    {
        return atoll(s); // Decimal
    }
}
```

_Código extraído em [`lexer.c`](src/lexer.c)._

#### Teste do Código

```C
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0xFFFF;
    float b = 0b1010;
    double c = 50 + 20 + 10;
    float d = 0x400;

    // Teste de comentário

    return NULL;
}
```

_output:_

```Text
❯ ./main
Compiladores - TURMA A - GRUPO 7
TOKEN   SY: #
TOKEN   KW: include
TOKEN   ST: stdio.h
TOKEN   NL
TOKEN   SY: #
TOKEN   KW: include
TOKEN   ST: stdlib.h
TOKEN   NL
TOKEN   NL
TOKEN   KW: int
TOKEN   ID: main
TOKEN   OP: (
TOKEN   SY: )
TOKEN   NL
TOKEN   SY: {
TOKEN   NL
TOKEN   KW: int
TOKEN   ID: a
TOKEN   OP: =
TOKEN   NU: 65535
TOKEN   SY: ;
TOKEN   NL
TOKEN   KW: float
TOKEN   ID: b
TOKEN   OP: =
TOKEN   NU: 10
TOKEN   SY: ;
TOKEN   NL
TOKEN   KW: double
TOKEN   ID: c
TOKEN   OP: =
TOKEN   NU: 50
TOKEN   OP: +
TOKEN   NU: 20
TOKEN   OP: +
TOKEN   NU: 10
TOKEN   SY: ;
TOKEN   NL
TOKEN   KW: float
TOKEN   ID: d
TOKEN   OP: =
TOKEN   NU: 1024
TOKEN   SY: ;
TOKEN   NL
TOKEN   NL
TOKEN   NL
TOKEN   NL
TOKEN   KW: return
TOKEN   ID: NULL
TOKEN   SY: ;
TOKEN   NL
TOKEN   SY: }
Todos os arquivos foram compilados com sucesso!
```

### **Atividade 4 - Criar os arquivos parser.c e node.c (Makefile)**

Por fim, foram criados os arquivos [`parser.c`](src/parser.c) e [`node.c`](src/node.c). Além disso, o [`Makefile`](src/Makefile) foi atualizado para incluir esses novos arquivos e garantir que o projeto seja compilado corretamente.

_output com Makefile atualizado:_

```text
❯ ./main
Compiladores - TURMA A - GRUPO 7
TOKEN   SY: #
TOKEN   KW: include
TOKEN   ST: stdio.h
TOKEN   NL
TOKEN   SY: #
TOKEN   KW: include
TOKEN   ST: stdlib.h
TOKEN   NL
TOKEN   NL
TOKEN   KW: int
TOKEN   ID: main
TOKEN   OP: (
TOKEN   SY: )
TOKEN   NL
TOKEN   SY: {
TOKEN   NL
TOKEN   KW: int
TOKEN   ID: a
TOKEN   OP: =
TOKEN   NU: 65535
TOKEN   SY: ;
TOKEN   NL
TOKEN   KW: float
TOKEN   ID: b
TOKEN   OP: =
TOKEN   NU: 10
TOKEN   SY: ;
TOKEN   NL
TOKEN   KW: double
TOKEN   ID: c
TOKEN   OP: =
TOKEN   NU: 50
TOKEN   OP: +
TOKEN   NU: 20
TOKEN   OP: +
TOKEN   NU: 10
TOKEN   SY: ;
TOKEN   NL
TOKEN   KW: float
TOKEN   ID: d
TOKEN   OP: =
TOKEN   NU: 1024
TOKEN   SY: ;
TOKEN   NL
TOKEN   NL
TOKEN   NL
TOKEN   NL
TOKEN   KW: return
TOKEN   ID: NULL
TOKEN   SY: ;
TOKEN   NL
TOKEN   SY: }
Todos os arquivos foram compilados com sucesso!

```

---

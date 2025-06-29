# Grupo 7 - Relatório do Laboratório

## Integrantes

- Gabriel Andrade Silva Pinto
- Isabela Garcia Godinho
- João Victor Azevedo dos Santos
- Luiz Eduardo Campos Dias
- Yago Péres dos Santos

### Laboratório 06

Sala: 1002 - Turma A - 0225

---

## Lista de Arquivos Enviados

- **src/**
  - [`compiler.c`](src/compiler.c)
  - [`compiler.h`](src/compiler.h)
  - [`cprocess.c`](src/cprocess.c)
  - [`expressionable.c`](src/expressionable.c)
  - [`lex_process.c`](src/lex_process.c)
  - [`lexer.c`](src/lexer.c)
  - [`main`](src/main)
  - [`main.c`](src/main.c)
  - [`Makefile`](src/Makefile)
  - [`node.c`](src/node.c)
  - [`output.c`](src/output.c)
  - [`parser.c`](src/parser.c)
  - [`scope.c`](src/scope.c) - **(NOVO)**
  - [`symresolver.c`](src/symresolver.c) - **(NOVO)**
  - [`test.c`](src/test.c)
  - [`test1.c`](src/test1.c)
  - [`test2.c`](src/test2.c)
  - [`test3.c`](src/test3.c)
  - [`token.c`](src/token.c)
  - **build/**
    - `compiler.o`
    - `cprocess.o`
    - `expressionable.o`
    - `lex_process.o`
    - `lexer.o`
    - `node.o`
    - `parser.o`
    - `scope.o`
    - `symresolver.o`
    - `token.o`
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

Neste laboratório, implementamos três novas funcionalidades de sintaxe para o compilador:

### Atividade 1 - Nova Sintaxe para Declaração de Variáveis

**Forma Proposta:** `A igual int;`

Implementamos a função `parse_variable_igual_syntax()` que permite declarar variáveis usando a palavra-chave "igual" em vez do formato tradicional. A sintaxe segue o padrão:
- Nome da variável
- Palavra-chave "igual"
- Tipo de dados
- Ponto e vírgula

**Funcionalidades Suportadas:**
- Tipos de dados: `int`, `float`, `double`, `char`, `bool`, `void`
- Arrays multidimensionais
- Verificação de sintaxe e tratamento de erros

### Atividade 2 - Nova Sintaxe para Declaração de Structs

**Forma Proposta:** `struct ABC /int A\ /int B\ /int C\;`

Implementamos a função `parse_struct_nova_sintaxe()` que permite declarar structs usando uma sintaxe alternativa:
- Palavra-chave "struct" seguida do nome
- Membros separados por "/" e "\"
- Suporte a ponteiros e arrays
- Finalização com ponto e vírgula

**Funcionalidades Suportadas:**
- Membros com diferentes tipos de dados
- Arrays multidimensionais
- Ponteiros
- Tratamento de quebras de linha e comentários

### Atividade 3 - Nova Sintaxe para Declaração de If/Else

**Forma Proposta:** `if A>B ? return 0 ? return 1;`

Implementamos a função `parse_if_nova_sintaxe()` que permite declarar estruturas condicionais usando:
- Palavra-chave "if" seguida da condição
- Primeiro "?" para separar a ação se verdadeiro
- Segundo "?" para separar a ação se falso
- Finalização com ponto e vírgula

**Funcionalidades Suportadas:**
- Condições complexas
- Ações simples e compostas
- Tratamento de expressões

---

## Entregas Solicitadas

### Código Fonte Implementado

1. **`parse_variable_igual_syntax()`** - Nova sintaxe para declaração de variáveis
2. **`parse_struct_nova_sintaxe()`** - Nova sintaxe para declaração de structs  
3. **`parse_if_nova_sintaxe()`** - Nova sintaxe para declaração de if/else

### Arquivos de Teste

- **`test.c`** - Arquivo principal de teste contendo exemplos de todas as novas sintaxes


### Resultados dos Testes

O compilador foi testado com sucesso, processando:
- Declarações de variáveis com a nova sintaxe
- Structs com membros simples e complexos (arrays, ponteiros)
- Estruturas condicionais if/else
- Geração correta de tokens e árvore de nodes


---

## Como Executar

```bash
cd LAB06/src
make
./main test.c
```

O programa irá processar o arquivo de teste e exibir:
- Lista de tokens reconhecidos
- Árvore de nodes gerada
- Mensagens de status do processamento

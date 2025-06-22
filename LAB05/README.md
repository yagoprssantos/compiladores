# Grupo 7 - Relatório do Laboratório

## Integrantes

- Isabela Garcia Godinho
- João Victor Azevedo dos Santos
- Luiz Eduardo Campos Dias
- Yago Péres dos Santos

### Laboratório 05

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
    - `scope.o` - **(NOVO)**
    - `symresolver.o` - **(NOVO)**
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

No Laboratório 05, foram implementadas funcionalidades avançadas do analisador sintático, incluindo gerenciamento de escopo, resolução de símbolos e suporte a estruturas de dados complexas como arrays e structs.

### Principais implementações

1. **Sistema de Gerenciamento de Escopo (`scope.c`)**

   - Implementação de estruturas hierárquicas de escopo
   - Funções para criação, navegação e destruição de escopos
   - Suporte a escopo raiz e aninhamento de escopos

2. **Resolvedor de Símbolos (`symresolver.c`)**

   - Sistema de tabela de símbolos para identificadores
   - Registro e busca de símbolos por nome
   - Suporte a diferentes tipos de símbolos (variáveis, funções, estruturas)

3. **Aprimoramento do Parser**
   - Refatoração da função `parser_build_random_type_name()` para gerar nomes únicos para tipos anônimos
   - Implementação de suporte a declarações múltiplas de variáveis na mesma linha
   - Suporte completo a arrays multidimensionais
   - Implementação de parsing de estruturas (structs)

---

## Entregas Solicitadas

### Atividade 1: Integração e Refatoração

- ✅ Integração das funções do LAB4
- ✅ Refatoração da função `parser_build_random_type_name()` com alocação dinâmica de memória e geração de nomes únicos

### Atividade 2: Sistema de Escopo e Símbolos

- ✅ Criação do arquivo `scope.c` com funções de gerenciamento de escopo
- ✅ Criação do arquivo `symresolver.c` com sistema de resolução de símbolos
- ✅ Atualização do `Makefile` para incluir os novos arquivos
- ✅ Implementação do tipo `NODE_TYPE_VARIABLE_LIST` para declarações múltiplas
- ✅ Suporte a declarações como `int a, b, c, d, e;` e `float aa, bb, cc;`

### Atividade 3: Estruturas de Dados Avançadas

#### Arrays Multidimensionais

- ✅ Suporte a arrays unidimensionais: `float B[100];`
- ✅ Suporte a arrays multidimensionais: `int A[50][50];`
- ✅ Parsing correto de dimensões e armazenamento em estruturas de dados

**Exemplo de saída para arrays:**

```
└── VARIABLE_LIST (count: 1)
│   └── VARIABLE (name: A, type: int, ARRAY[50][50])

└── VARIABLE_LIST (count: 1)
│   └── VARIABLE (name: B, type: float, ARRAY[100])
```

#### Estruturas (Structs)

- ✅ Parsing de definições de struct simples
- ✅ Suporte a múltiplos membros na mesma linha
- ✅ Validação de sintaxe (chaves, ponto e vírgula)

**Exemplos suportados:**

- `struct ABC {int A; float B; double C;}`
- `struct ABC {int A, B, C, D, E;}`

**Exemplo de saída para structs:**

```
Processando struct:
Nome da struct: ABC
Membro adicionado: int A
Membro adicionado: float B
Membro adicionado: double C
Struct criada com 3 membros
└── STRUCT (name: ABC)
```

### Testes Realizados

**Teste 1 - Declarações múltiplas (`test1.c`):**

```c
int a, b, c, d, e;
float aa, bb, cc;
```

**Teste 2 - Arrays (`test2.c`):**

```c
int A[50][50];
float B[100];
```

**Teste 3 - Structs (`test3.c`):**

```c
struct ABC {
    int A;
    float B;
    double C;
};

struct ABC {
    int A, B, C, D, E;
};
```

Todos os testes foram executados com sucesso, demonstrando o funcionamento correto das implementações.

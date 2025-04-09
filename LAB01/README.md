# Grupo 7 - Relatório do Laboratório

## Integrantes

- Isabela Garcia Godinho
- João Victor Azevedo dos Santos
- Yago Péres dos Santos

### Laboratório 01

Sala: 1002 - Turma A - 0225

## Lista de Arquivos Enviados

- `compiler/`
  - `compiler.c`
  - `compiler.h`
  - `cprocess.c`
  - `main.c`
  - `Makefile`
  - `test.c`
  - `test.h`
  - `helpers/`
    - `buffer.c`
    - `buffer.h`
    - `vector.c`
    - `vector.h`
  - `build/`
    - `compiler.o`
    - `cprocess.o`
    - `test.o`
    - `helpers/`
      - `buffer.o`
      - `vector.o`

## Descrição do Trabalho Realizado

Neste laboratório, foi desenvolvido um compilador básico com funcionalidades de análise léxica e manipulação de estruturas auxiliares. As principais atividades realizadas incluem:

1. Implementação de funções para manipulação de vetores dinâmicos (`vector`) e buffers (`buffer`), localizadas na pasta `helpers/`.
2. Desenvolvimento de funções de teste para validar as operações de vetores e buffers, bem como a funcionalidade de compilação, no arquivo `test.c`.
3. Criação de um processo de compilação básico no arquivo `compiler.c`, com suporte para leitura e escrita de arquivos.
4. Configuração de um `Makefile` para automatizar a compilação dos arquivos e geração do executável principal.
5. Estruturação do código em módulos para facilitar a manutenção e a expansão futura.

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

O `Makefile` foi configurado para compilar os arquivos do projeto e gerar o executável principal. Abaixo está um exemplo do funcionamento:

```plaintext
gcc ./compiler.c -I./ -o ./build/compiler.o -g -c
gcc ./cprocess.c -I./ -o ./build/cprocess.o -g -c
gcc ./helpers/buffer.c -I./ -o ./build/helpers/buffer.o -g -c
gcc ./helpers/vector.c -I./ -o ./build/helpers/vector.o -g -c
gcc ./test.c -I./ -o ./build/test.o -g -c
gcc main.c -I./ ./build/compiler.o ./build/cprocess.o ./build/helpers/buffer.o ./build/helpers/vector.o ./build/test.o -g -o ./main
```

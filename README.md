# Projeto de Compiladores - Grupo 7

## Visão Geral

Este repositório contém os trabalhos realizados pelo **Grupo 7** na disciplina de **Compiladores**. O objetivo principal é desenvolver um compilador funcional, passando por todas as etapas do processo de compilação, desde a análise léxica até a geração de código. Cada laboratório aborda um aspecto específico do desenvolvimento de compiladores, com atividades práticas e teóricas.

## Integrantes do Grupo

- **Gabriel Andrade Silva Pinto**
- **Isabela Garcia Godinho**
- **João Victor Azevedo dos Santos**
- **Luiz Eduardo Campos Dias**
- **Yago Péres dos Santos**

## Estrutura do Repositório

O repositório está organizado em pastas, cada uma representando um laboratório (LAB). Abaixo, segue uma breve descrição de cada LAB:

---

### **LAB01 - Introdução e Estruturas Auxiliares**

- **Objetivo**: Implementar estruturas auxiliares para o compilador, como vetores dinâmicos e buffers.
- **Atividades**:
  - Criação de funções para manipulação de vetores (`vector`) e buffers (`buffer`).
  - Desenvolvimento de testes unitários para validar as estruturas implementadas.
  - Configuração de um `Makefile` para automatizar a compilação.
- **Resultados**:
  - Estruturas auxiliares funcionais e testadas.
  - Base para o desenvolvimento do compilador.

---

### **LAB02 - Ponteiros e Análise Léxica**

- **Objetivo**: Introduzir conceitos de ponteiros e implementar a análise léxica do compilador.
- **Atividades**:
  - Manipulação de permissões e conversão de tipos de dados utilizando `union`.
  - Uso de ponteiros para implementar operações matemáticas e manipulação de arrays de funções.
  - Expansão do compilador com análise léxica básica.
  - Implementação de um analisador léxico completo para identificar tokens em um arquivo de entrada.
- **Resultados**:
  - Analisador léxico funcional, capaz de identificar números, strings, palavras-chave, operadores e símbolos.

---

### **LAB03 - Análise Léxica Avançada e Introdução à Análise Sintática**

- **Objetivo**: Refinar o analisador léxico e implementar a análise sintática inicial.
- **Atividades**:
  - Finalização da implementação de todos os tipos de tokens, incluindo suporte para números hexadecimais e binários.
  - Implementação inicial do parser, responsável por construir a árvore de sintaxe abstrata (AST).
  - Criação de estruturas para representar nós da AST, como `FUNCTION_NODE`, `VARIABLE_NODE`, `EXPRESSION_NODE`, entre outros.
  - Atualização do `Makefile` para incluir os novos arquivos do parser.
- **Resultados**:
  - Analisador léxico refinado e funcional.
  - Parser inicial implementado, com suporte básico para análise sintática.

---

### **LAB04 - Análise Sintática e Manipulação de Expressões**

- **Objetivo**: Evoluir o compilador com a implementação da análise sintática completa e manipulação de expressões, além do refinamento do analisador léxico.
- **Atividades**:
  - Implementação e integração de novos módulos para análise sintática (parser) e manipulação de expressões.
  - Criação e manipulação de estruturas auxiliares, como vetores dinâmicos (`vector`) e buffers (`buffer`).
  - Desenvolvimento do núcleo do compilador, incluindo controle de arquivos, flags e integração entre analisador léxico e sintático.
  - Implementação do analisador léxico com suporte a números, operadores, palavras-chave, símbolos, strings e comentários.
  - Construção da árvore de sintaxe abstrata (AST) e definição dos nós para funções, variáveis e expressões.
  - Implementação da análise e avaliação de expressões, incluindo precedência de operadores.
  - Geração de saída intermediária ou código a partir da AST.
  - Criação de testes de unidade e integração para validar análise léxica, sintática e precedência de operadores.
  - Automatização da compilação com `Makefile`.
- **Resultados**:
  - Compilador com análise léxica e sintática integradas, capaz de construir a AST e manipular expressões com precedência correta.
  - Estruturas auxiliares robustas para vetores e buffers.
  - Testes validados para os principais módulos do compilador.
  - Processo de compilação automatizado via `Makefile`.

---

### **LAB05 - Gerenciamento de Escopo e Resolução de Símbolos**

- **Objetivo**: Implementar gerenciamento de escopo e resolução de símbolos no compilador.
- **Atividades**:
  - Implementação do sistema de escopo para variáveis e funções.
  - Criação de estruturas para gerenciar diferentes níveis de escopo.
  - Desenvolvimento do resolvedor de símbolos para identificar e validar declarações.
  - Integração do sistema de escopo com o parser existente.
  - Implementação de verificações de tipo e validação de símbolos.
  - Criação de testes para validar o gerenciamento de escopo.
- **Resultados**:
  - Sistema de escopo funcional para variáveis e funções.
  - Resolvedor de símbolos integrado ao compilador.
  - Validação de tipos e declarações implementada.
  - Testes abrangentes para o sistema de escopo.

---

### **LAB06 - Novas Sintaxes e Funcionalidades Avançadas**

- **Objetivo**: Implementar novas sintaxes alternativas e funcionalidades avançadas no compilador.
- **Atividades**:
  - **Nova Sintaxe para Declaração de Variáveis**: Implementação da sintaxe `A igual int;` usando a palavra-chave "igual".
  - **Nova Sintaxe para Declaração de Structs**: Implementação da sintaxe `struct ABC /int A\ /int B\ /int C\;` usando separadores alternativos.
  - **Nova Sintaxe para Declaração de If/Else**: Implementação da sintaxe `if A>B ? return 0 ? return 1;` usando operadores "?".
  - Suporte a arrays multidimensionais e ponteiros nas novas sintaxes.
  - Tratamento robusto de erros e validação de sintaxe.
  - Integração das novas funcionalidades com o sistema existente.
- **Resultados**:
  - Três novas sintaxes alternativas implementadas e funcionais.
  - Suporte completo a tipos de dados complexos (arrays, ponteiros).
  - Sistema de tratamento de erros robusto.
  - Testes abrangentes para todas as novas funcionalidades.
  - Compilador expandido com funcionalidades avançadas.

---

## Como Executar

1. Navegue até a pasta do laboratório desejado.
2. Compile o projeto utilizando o `Makefile`:

   ```bash
   make
   ```

3. Execute o programa gerado:

   ```bash
   ./main
   ```

### Exemplo para LAB06

```bash
cd LAB06/src
make
./main test.c
```

## Testes e Resultados

Cada laboratório inclui testes específicos para validar as funcionalidades implementadas. Os testes podem ser executados compilando o projeto e rodando o executável gerado. Consulte os arquivos `README.md` de cada laboratório para mais detalhes sobre os testes realizados e seus resultados.

### Funcionalidades Implementadas

- **Estruturas Auxiliares**: Vetores dinâmicos e buffers
- **Análise Léxica**: Reconhecimento de tokens, números, strings, operadores
- **Análise Sintática**: Parser e construção de AST
- **Manipulação de Expressões**: Precedência de operadores e avaliação
- **Gerenciamento de Escopo**: Controle de variáveis e funções
- **Resolução de Símbolos**: Validação de declarações e tipos
- **Sintaxes Alternativas**: Novas formas de declarar variáveis, structs e condicionais

---

## Status do Projeto

✅ **LAB01** - Concluído  
✅ **LAB02** - Concluído  
✅ **LAB03** - Concluído  
✅ **LAB04** - Concluído  
✅ **LAB05** - Concluído  
✅ **LAB06** - Concluído  

O projeto está **100% completo** com todas as funcionalidades implementadas e testadas.

---

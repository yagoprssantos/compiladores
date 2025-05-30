# Projeto de Compiladores - Grupo 7

## Visão Geral

Este repositório contém os trabalhos realizados pelo **Grupo 7** na disciplina de **Compiladores**. O objetivo principal é desenvolver um compilador funcional, passando por todas as etapas do processo de compilação, desde a análise léxica até a geração de código. Cada laboratório aborda um aspecto específico do desenvolvimento de compiladores, com atividades práticas e teóricas.

## Integrantes do Grupo

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

### **LAB05 - _a ser feito_**

---

### **LAB06 - _a ser feito_**

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

## Testes e Resultados

Cada laboratório inclui testes específicos para validar as funcionalidades implementadas. Os testes podem ser executados compilando o projeto e rodando o executável gerado. Consulte os arquivos `README.md` de cada laboratório para mais detalhes sobre os testes realizados e seus resultados.

---

#include "test.h"
#include "helpers/vector.h"
#include "compiler.h"
#include <stdio.h>
#include <assert.h>

// Função de teste para o vector_create()
void test_vector_create() {
    struct vector* vec = vector_create(sizeof(int));
    assert(vec != NULL); // Certifique-se de que o vetor foi criado
    assert(vec->data != NULL); // Certifique-se de que a memória foi alocada
    printf("Teste vector_create() passou!\n");
}

// Função de teste para o vector_push()
void test_vector_push() {
    struct vector* vec = vector_create(sizeof(int));
    int value = 10;
    vector_push(vec, &value);
    assert(vec->count == 1); // Verifique se um item foi adicionado
    assert(*(int*)vector_at(vec, 0) == 10); // Verifique se o valor está correto
    printf("Teste vector_push() passou!\n");
}

// Função de teste para o vector_pop()
void test_vector_pop() {
    struct vector* vec = vector_create(sizeof(int));
    int value = 20;
    vector_push(vec, &value);
    vector_pop(vec);
    assert(vec->count == 0); // Verifique se o vetor está vazio após o pop
    printf("Teste vector_pop() passou!\n");
}

// Função de teste para o vector_set_peek_pointer()
void test_vector_set_peek_pointer() {
    struct vector* vec = vector_create(sizeof(int));
    int value = 30;
    vector_push(vec, &value);
    vector_set_peek_pointer(vec, 0);
    assert(*(int*)vector_peek(vec) == 30); // Verifique se o valor apontado é o correto
    printf("Teste vector_set_peek_pointer() passou!\n");
}

// Função de teste para o vector_peek()
void test_vector_peek() {
  struct vector* vec = vector_create(sizeof(int));
  int value1 = 40, value2 = 50;

  // Adiciona os valores ao vetor
  vector_push(vec, &value1);
  vector_push(vec, &value2);

  // Configura o ponteiro de leitura para o primeiro valor
  vector_set_peek_pointer(vec, 0);
  int* peeked_value1 = (int*)vector_peek(vec);
  assert(peeked_value1 != NULL && *peeked_value1 == 40); // O primeiro valor deve ser 40

  // Avança o ponteiro de leitura para o próximo valor
  vector_set_peek_pointer(vec, 1);
  int* peeked_value2 = (int*)vector_peek(vec);
  assert(peeked_value2 != NULL && *peeked_value2 == 50); // O segundo valor deve ser 50

  printf("Teste vector_peek() passou!\n");
}

// Função de teste para o compile_file()
void test_compile_file() {
    int result = compile_file("main.c", "main.o", 0);
    assert(result == COMPILER_FILE_COMPILED_OK); // Verifique se a compilação foi bem-sucedida
    printf("Teste compile_file() passou!\n");
}

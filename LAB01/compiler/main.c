#include <stdio.h>
#include "compiler.h"
#include "test.h"
#include "helpers/vector.h" 
#include "helpers/buffer.h" 
 
int main() { 
  printf("Compiladores - TURMA A -GRUPO 7\n");  

    /* TESTE DAS FUNÇÕES HELPERS */
   // Teste do vetor
   test_vector_create();
   test_vector_push();
   test_vector_pop();
   test_vector_set_peek_pointer();
   test_vector_peek();
  
  // Compile_file
  test_compile_file();
  compile_file("main.c", "main.o", 0);
  
  return 0;  
}
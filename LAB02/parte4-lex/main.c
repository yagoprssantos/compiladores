#include <stdio.h>
#include "compiler.h"
#include "helpers/vector.h" 
#include "helpers/buffer.h" 
 
int main() { 
  printf("Compiladores - TURMA A -GRUPO 7\n");  

    /* TESTE DAS FUNÇÕES HELPERS */

    int res = compile_file("./test.c", "./outtest", 0);
    if (res == COMPILER_FILE_COMPILED_OK){
      printf("Todos os arquivos foram compilados com sucesso!\n");
    } else if (res == COMPILER_FAILED_WITH_ERRORS){
      printf("Erro na compilação!\n");
    } else {
      printf("Erro desconhecido!\n");
    }
  
  return 0;  
}
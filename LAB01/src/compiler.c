#include "compiler.h"

int compile_file(const char* filename, const char* out_filename, int flags) {
  struct compile_process* process = compile_process_create(filename, out_filename, flags); 
  if (!process) {
    return COMPILER_FAILED_WITH_ERRORS; 
  }

  /* Aqui entra a analise lexica*/


  /* Aqui entra o parsing do codigo*/

  
  /* Aqui entra a geracao de codigo*/

  
  return COMPILER_FILE_COMPILED_OK;
}
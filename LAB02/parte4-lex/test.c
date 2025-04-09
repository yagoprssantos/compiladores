#include <stdio.h>

/* Assim */

// Função principal
int main() {
  int a = 10;
  float b = 20.5;
  char c = "x";

  // Operadores
  a = a + b - c * 2 / 1;

  // Controle de fluxo
  if (a > b) {
    printf("a é maior que b\n");
  } else {
    printf("b é maior ou igual a a\n");
  }

  // Laços
  for (int i = 0; i < 10; i++) {
    printf("Valor de i: %d\n", i);
  }


  // Operadores e símbolos adicionais
  a = (b + c) * 2;
  int arr[5] = {1, 2, 3, 4, 5};

  return 0;
}

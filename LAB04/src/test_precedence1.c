#include <stdio.h>

int main()
{
  // Teste de precedência entre multiplicação/divisão e adição/subtração
  // Precedência: 3 (*/%) > 4 (+-) conforme tabela
  int a = 5 + 3 * 2;         // Deve resultar em 11, não em 16
  int b = 10 - 6 / 2;        // Deve resultar em 7, não em 2
  int c = 2 + 3 * 4 - 6 / 2; // Deve resultar em 2+12-3 = 11

  printf("Resultados: a=%d b=%d c=%d\n", a, b, c);
  return 0;
}
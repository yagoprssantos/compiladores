#include <stdio.h>

int main()
{
  // Teste de precedência com uso explícito de parênteses
  // Testa se parênteses estão tendo a precedência mais alta (nível 1)
  int a = 5, b = 3, c = 2;

  // Expressão normal com precedência padrão
  int result1 = a + b * c; // Deve ser 11 (5 + 6)

  // Mesma expressão com parênteses para alterar a precedência
  int result2 = (a + b) * c; // Deve ser 16 (8 * 2)

  // Expressão complexa com vários operadores e parênteses
  int result3 = (a + b) * (c + 1) - b / c; // Deve ser (8 * 3) - 1 = 23

  // Teste de operadores ternários e sua associatividade (da direita para esquerda)
  // Nível 13 na tabela
  int result4 = a > b ? a : b > c ? b
                                  : c; // Deve ser interpretado como: a > b ? a : (b > c ? b : c)

  printf("Resultados: result1=%d result2=%d result3=%d result4=%d\n",
         result1, result2, result3, result4);
  return 0;
}
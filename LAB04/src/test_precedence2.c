#include <stdio.h>

int main()
{
  // Teste de precedência entre operadores relacionais e lógicos
  // Precedência: 6/7 (<,>,<=,>=,==,!=) > 11/12 (&&, ||)
  int a = 5, b = 10, c = 15;

  // Deve avaliar como ((a < b) && (b < c)), não como (a < (b && b) < c)
  int result1 = a < b && b < c;

  // Deve avaliar como ((a > b) || (b < c)), não como (a > (b || b) < c)
  int result2 = a > b || b < c;

  // Teste complexo de precedência: && (nível 11) tem maior precedência que || (nível 12)
  int result3 = a < b || b > c && a < c; // Deve ser avaliado como: a < b || (b > c && a < c)

  printf("Resultados: result1=%d result2=%d result3=%d\n", result1, result2, result3);
  return 0;
}
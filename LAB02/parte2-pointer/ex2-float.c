#include <stdio.h>

float soma(float a, float b) { return a + b; }
float subtracao(float a, float b) { return a - b; }
float multiplicacao(float a, float b) { return a * b; }
float divisao(float a, float b) { return b != 0 ? a / b : 0; }

int main() {
    float (*operacoes[])(float, float) = { soma, subtracao, multiplicacao, divisao };
    char simbolos[] = { '+', '-', '*', '/' };
    int escolha;
    float a, b;

    printf("Digite dois números: ");
    scanf("%f %f", &a, &b);

    printf("Escolha a operação (0 = +, 1 = -, 2 = *, 3 = /): ");
    scanf("%d", &escolha);

    if (escolha < 0 || escolha > 3) {
        printf("Operação inválida!\n");
        return 1;
    }

    printf("%.2f %c %.2f = %.2f\n", a, simbolos[escolha], b, operacoes[escolha](a, b));

    return 0;
}
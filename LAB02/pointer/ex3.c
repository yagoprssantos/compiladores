#include <stdio.h>

typedef int (*Operacao)(int, int);

int soma(int a, int b) { return a + b; }
int subtracao(int a, int b) { return a - b; }
int multiplicacao(int a, int b) { return a * b; }
int divisao(int a, int b) { return b != 0 ? a / b : 0; }

int main() {
    Operacao operacoes[] = { soma, subtracao, multiplicacao, divisao };
    char simbolos[] = { '+', '-', '*', '/' };
    int escolha, a, b;

    printf("Digite dois números: ");
    scanf("%d %d", &a, &b);

    printf("Escolha a operação (0 = +, 1 = -, 2 = *, 3 = /): ");
    scanf("%d", &escolha);

    if (escolha < 0 || escolha > 3) {
        printf("Operação inválida!\n");
        return 1;
    }

    printf("%d %c %d = %d\n", a, simbolos[escolha], b, operacoes[escolha](a, b));

    return 0;
}
#include <stdio.h>

int soma(int a, int b) {
    return a + b;
}

int subtracao(int a, int b) {
    return a - b;
}

int main() {
    int (*operacao)(int, int);
    int escolha, a, b;

    printf("Digite dois números: ");
    scanf("%d %d", &a, &b);

    printf("Escolha a operação (1 para soma, 2 para subtração): ");
    scanf("%d", &escolha);

    if (escolha == 1) {
        operacao = soma;
    } else if (escolha == 2) {
        operacao = subtracao;
    } else {
        printf("Operação inválida!\n");
        return 1;
    }

    printf("Resultado: %d\n", operacao(a, b));

    return 0;
}
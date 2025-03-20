#include "permissao.h"
#include "conversor.h"
#include <stdio.h>

int main() {
    int opcao;
    printf("Escolha o programa a ser executado:\n");
    printf("1. Programa de Permissao\n");
    printf("2. Programa de Conversor\n");
    printf("Digite sua escolha: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            executar_permissao();
            break;
        case 2:
            executar_conversor();
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }

    return 0;
}

#include "permissao.h"
#include <stdio.h>

void mostrar_binario(unsigned char valor) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (valor >> i) & 1);
    }
    printf("\n");
}

void executar_permissao() {
    Permissao permissao = {0};
    int leitura, escrita, execucao;

    printf("Tem permissão de leitura? (1 para sim, 0 para não): ");
    scanf("%d", &leitura);
    printf("Tem permissão de escrita? (1 para sim, 0 para não): ");
    scanf("%d", &escrita);
    printf("Tem permissão de execução? (1 para sim, 0 para não): ");
    scanf("%d", &execucao);

    permissao.permissoes.leitura = leitura;
    permissao.permissoes.escrita = escrita;
    permissao.permissoes.execucao = execucao;

    printf("Valor final em decimal: %d\n", permissao.valor);
    printf("Valor final em binário: ");
    mostrar_binario(permissao.valor);
}

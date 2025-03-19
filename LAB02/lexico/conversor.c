#include "conversor.h"
#include <stdio.h>

void mostrar_bytes(unsigned char* bytes, size_t tamanho) {
    for (size_t i = 0; i < tamanho; i++) {
        printf("%02X ", bytes[i]);
    }
    printf("\n");
}

void executar_conversor() {
    Conversor conversor;
    int escolha;
    printf("Escolha um tipo de dado:\n");
    printf("1. unsigned int\n");
    printf("2. float\n");
    printf("3. double\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            printf("Digite um valor unsigned int: ");
            scanf("%u", &conversor.inteiro);
            mostrar_bytes(conversor.bytes, sizeof(conversor.inteiro));
            break;
        case 2:
            printf("Digite um valor float: ");
            scanf("%f", &conversor.decimal);
            mostrar_bytes(conversor.bytes, sizeof(conversor.decimal));
            break;
        case 3:
            printf("Digite um valor double: ");
            scanf("%lf", &conversor.duplo);
            mostrar_bytes(conversor.bytes, sizeof(conversor.duplo));
            break;
        default:
            printf("Escolha inválida.\n");
            break;
    }
}

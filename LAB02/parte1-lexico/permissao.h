#ifndef PERMISSAO_H
#define PERMISSAO_H

typedef union {
    unsigned char valor;
    struct {
        unsigned char leitura : 1;
        unsigned char escrita : 1;
        unsigned char execucao : 1;
        unsigned char reservado : 5;
    } permissoes;
} Permissao;

void mostrar_binario(unsigned char valor);
void executar_permissao();

#endif // PERMISSAO_H

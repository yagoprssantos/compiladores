#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <stddef.h> // Adicionado para definir 'size_t'

typedef union {
    unsigned int inteiro;
    float decimal;
    double duplo;
    unsigned char bytes[8];
} Conversor;

void mostrar_bytes(unsigned char* bytes, size_t tamanho);
void executar_conversor();

#endif // CONVERSOR_H

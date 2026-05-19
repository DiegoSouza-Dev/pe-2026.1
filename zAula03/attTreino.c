#include <stdio.h>

#define TAM_DESCRICAO 30;

struct Produto {
    int codigo;
    char descricao[TAM_DESCRICAO];
    double valorunit;
}
#include <stdlib.h>
#include <stdio.h>

int buscaBinaria(int v[], int n, int chave){
    int inicio = 0, meio, fim = n - 1;

    if(n == 0){
        return -2;
    }

    do{
        meio = (inicio + fim) / 2;
        if(v[meio] > chave){
            fim = meio - 1;
        } else if (v[meio] < chave){
            inicio = meio + 1;
        }
    }while(v[meio] != chave && inicio <= fim);

    if(v[meio] == chave){
        return meio;
    }else{
        return -1;
    }
}


int main() {
    // O vetor PRECISA estar ordenado para a busca binária funcionar
    int meuVetor[] = {10, 20, 30, 40, 50};
    int tamanho = 5;
    int busca = 10;

    int resultado = buscaBinaria(meuVetor, tamanho, busca);

    if (resultado >= 0) {
        printf("Elemento %d encontrado no indice: %d\n", busca, resultado);
    } else if (resultado == -1) {
        printf("Elemento %d nao encontrado.\n", busca);
    } else {
        printf("Vetor vazio.\n");
    }

    return 0;
}

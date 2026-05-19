#include <stdlib.h>
#include <stdio.h>

// bubble sort

void ordenar(int v[], int n){
    int aux = 0, pos = 0, fim = n - 2, troca = 1;
    while(troca == 1){
        troca = 0;
        for(int i = 0; i <= fim; i++){
            if(v[i] > v[i + 1]){
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                pos = i;
                troca = 1;
            }
        }
        fim = pos - 1;
    }
}

int main(){
    int v[5];

    // preencher
    for(int i = 0; i < 5; i++){
        printf("Digite %d numero: ", i + 1);
        scanf("%d", &v[i]);
    }

    ordenar(v, 5);

    // imprimir resultado
    printf("Vetor ordenado: { ");
    for(int i = 0; i < 5; i++){
        printf("%d", v[i]);
        if(i < 4) printf(", ");
    }
    printf(" }\n");

    return 0;
}
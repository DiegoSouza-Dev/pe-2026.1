#include <stdlib.h>
#include <stdio.h>

//  vetor recebido como parâmetro solicitando 
// que o usuário digite n valores inteiros
void lerVetor(int v[], int n){
    int numero = 0;
    for(int i = 0; i < n; i++){
        printf("Digite %d numero: ", i + 1);
        scanf("%d", &numero); 
        v[i] = numero;
    }
}

//  os n valores armazenados 
// neste vetor separados por vírgula e dentro de chaves.
void imprimirVetor(int v[], int n){
    printf(" [ ");
    for(int i = 0; i < n; i++){
        printf("%d", v[i]);
        if(i < n - 1) printf("  ");
    }
    printf(" ]\n");
}

int main(){
    int v[5];

    lerVetor(v, 5);
    imprimirVetor(v, 5);

    return 0;
}
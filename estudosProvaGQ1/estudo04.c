#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//  deverá imprimir o maior valor ímpar do vetor, ou a
// mensagem “Não há números ímpares no vetor” 

void imprimirMenorPar(int v[], int n){
    int menorpar = INT_MAX;
    for(int i = 0; i < n; i++){
        if(v[i] % 2 == 0 && v[i] < menorpar){
            menorpar = v[i];
        }
    }
    if(menorpar == INT_MAX){
        printf("Nao ha numeros pares no vetor");
    } else {
        printf("%d", menorpar);
    }
}

int main(){        // <-- main depois da função
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int v[n];
    for(int i = 0; i < n; i++){
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &v[i]);
    }

    imprimirMenorPar(v, n);

    return 0;
}


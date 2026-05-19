#include <stdlib.h>
#include <stdio.h>

// recebe um vetor v preenchido, e preenche
// os vetores pares e ímpares, contendo, respectivamente, todos os números pares e números ímpares do vetor
// original. OBS: todas as posições dos vetores pares e impares que não foram preenchidas, deve ser preenchida
// com o valor -1 

void criarParesImpares(int v[], int n, int pares[], int impares[]){
    int contadorpares = 0, contadorimpares = 0;
    for(int i = 0; i < n; i++){
        if(v[i] % 2 == 0){
            pares[contadorpares] = v[i];
            contadorpares += 1;
        } else {
            impares[contadorimpares] = v[i];
            contadorimpares += 1;
        }
    }
    for(int i = contadorpares; i < n; i++){
        pares[i] = -1;
    }
    for(int i = contadorimpares; i < n; i++){
        impares[i] = -1;
    }
}

int main(){
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int v[n], pares[n], impares[n];

    for(int i = 0; i < n; i++){
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &v[i]);
    }

    criarParesImpares(v, n, pares, impares);

    printf("Pares: { ");
    for(int i = 0; i < n; i++){
        printf("%d ", pares[i]);
    }
    printf("}\n");

    printf("Impares: { ");
    for(int i = 0; i < n; i++){
        printf("%d ", impares[i]);
    }
    printf("}\n");

    return 0;
}
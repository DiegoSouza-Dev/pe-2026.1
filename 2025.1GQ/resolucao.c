#include <stdio.h>

void preencherVetor(int v[], int n){  //ler vetor
    int numero = 0;
    for(int i = 0; i < n; i++){
        printf("Digite %d numeros inteiros: ", i + 1);
        scanf("%d", &numero);
        v[i] = numero;
    }
}

void imprimirVetor(int v[], int n){  //entre colchetes
     printf(" { ");
    for(int i = 0; i < n; i++){
        printf("%d", v[i]);
        if(i < n - 1) printf("  ");
    }
    printf(" }\n");
}

void ordenarDecrescente(int v[], int n){  //bubble sort
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

void imprimirMaiorImpar(int v[], int n){  //maior valor impar
    int maiorimpar = 0;
    for(int i = 0; i < n; i++){
        if(v[i] % 2 == 1 && v[i] > maiorimpar){
            maiorimpar = v[i];
        }
    }
    if(maiorimpar == 0){
        printf("nao ha numeros impares no vetor");
    } else {
        printf("%d", maiorimpar);
    }
}

void criarParesImpares(int v[], int n, int pares[], int impares[]){
    int contadorimpares = 0, contadorpares = 0;
    for(int i = 0; i < n; i++){
        if(v[i] % 2 == 0){
            pares[contadorpares] = v[i];
            contadorpares += 1;
        } else {
            impares[contadorimpares] = v[i];
            contadorimpares += 1;
        }     // --------------- isso aqui sem precisar de -1 complete        
    }                       
    for(int i = contadorpares; i < n; i++){
        pares[i] = -1;
    }
    for(int i = contadorimpares; i < n; i++){
        impares[i] = -1;
    }
}

// Matriz

void preencherMatriz(int m[][QTD_COLUNAS], int qtdLinhas, int qtdColunas){
    int num = 0;
    for(int i = 0; i < qtdLinhas; i++){
        for(int j = 0; j < qtdColunas; i++){
            printf("Digite o numero de celulas[%d][%d]", i, j);
            scanf("%d", &num);
            m[i][j] = num;
        }
    }
}




int main(){
    int vetor[5];
    preencherVetor(vetor, 5);
    return 0;
}
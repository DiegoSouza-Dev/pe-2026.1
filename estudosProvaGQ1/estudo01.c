#include <stdio.h>
#include <stdlib> 


// treino de tecla


void lerVetor(int v[], int n){
    int numero = 0;
    for(int i = 0; i < n; i++){
        printf("Digite %d numeros inteiros: ", i + 1);
        scanf("%d", &numero);
        v[i] = numero;
    }
}
 // exibir entre cochetes separados por espaço
//(pode ser entre chaves e por virgula)

void exibirVetor(int v[], int n){
    printf(" { ");
    for(int i = 0; i < n; i++){
        printf("%d", v[i]);
        if(i < n - 1) printf("  ");
    }
    printf(" }\n");
}

// bubble sort

void ordenarDecrescente(int v[], int n){
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

// menor valor par no vetor

void imprimirMenorPar(int v[], int n){
    int menorpar = INT_MAX;
    for(int i = 0; i < n; i++){
        if(v[i] % 2 == 0 && v[i] < menorpar){
            menorpar = v[i];
        }
    }
    if(menorpar == INT_MAX){
       printf("nao ha numeros pares no vetor"); 
    } else {
        printf("%d", menorpar);
    }  
}

// maior valor impar no vetor

void imprimirMaiorImpar(int v[], int n){
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

// divide numeros pares e impares 

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

// busca binaria

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

// busca sequencial

int buscaSequencial(int v[], int n, int x) {
    for (int i = 0; i < n; i += 1) {
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}
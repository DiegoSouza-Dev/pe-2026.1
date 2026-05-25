#include <stdio.h>
#include <string.h>

// 1 questao 

#define ESTADOS 26

struct Estado {
    char nome[30];
    int veiculos;
    int acidentes;
};

// (a) Coletar dados dos 26 estados
void coletarDados(struct Estado e[], int n){
    for(int i = 0; i < n; i++){
        printf("\n--- Estado %d ---\n", i + 1);
        printf("Nome do estado: ");
        scanf("%s", e[i].nome);
        printf("Numero de veiculos (2007): ");
        scanf("%d", &e[i].veiculos);
        printf("Numero de acidentes (2007): ");
        scanf("%d", &e[i].acidentes);
    }
}

// (b) Encontrar maior e menor acidentes
void encontrarExtremos(struct Estado e[], int n, int *idxMaior, int *idxMenor){
    *idxMaior = 0;
    *idxMenor = 0;
    
    for(int i = 1; i < n; i++){
        if(e[i].acidentes > e[*idxMaior].acidentes){
            *idxMaior = i;
        }
        if(e[i].acidentes < e[*idxMenor].acidentes){
            *idxMenor = i;
        }
    }
}

// (c) Calcular percentual
float calcularPercentual(struct Estado e[], int n, char nomeEstado[]){
    for(int i = 0; i < n; i++){
        if(strcmp(e[i].nome, nomeEstado) == 0){
            return (e[i].acidentes * 100.0) / e[i].veiculos;
        }
    }
    return -1;
}

// (d) Calcular média
float calcularMedia(struct Estado e[], int n){
    int soma = 0;
    for(int i = 0; i < n; i++){
        soma += e[i].acidentes;
    }
    return soma / (float)n;
}

// (e) Exibir estados acima da média
void exibirAcimaMedia(struct Estado e[], int n, float media){
    printf("\n=== ESTADOS ACIMA DA MEDIA ===\n");
    for(int i = 0; i < n; i++){
        if(e[i].acidentes > media){
            printf("%s - %d acidentes\n", e[i].nome, e[i].acidentes);
        }
    }
}

int main(){
    struct Estado estados[ESTADOS];
    int idxMaior, idxMenor;
    float media;
    
    coletarDados(estados, ESTADOS);
    
    encontrarExtremos(estados, ESTADOS, &idxMaior, &idxMenor);
    printf("\n=== MAIOR E MENOR ACIDENTES ===\n");
    printf("MAIOR: %s com %d acidentes\n", 
           estados[idxMaior].nome, estados[idxMaior].acidentes);
    printf("MENOR: %s com %d acidentes\n", 
           estados[idxMenor].nome, estados[idxMenor].acidentes);
    
    float percentual = calcularPercentual(estados, ESTADOS, estados[0].nome);
    printf("\n=== PERCENTUAL DE VEICULOS EM ACIDENTES ===\n");
    printf("%s: %.2f%%\n", estados[0].nome, percentual);
    
    media = calcularMedia(estados, ESTADOS);
    printf("\n=== MEDIA DE ACIDENTES ===\n");
    printf("Media nacional: %.2f acidentes\n", media);
    
    exibirAcimaMedia(estados, ESTADOS, media);
    
    return 0;
}
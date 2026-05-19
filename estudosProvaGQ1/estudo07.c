#include <stdlib.h>
#include <stdio.h>


#define QTD_COLUNAS 3


// preencha um vetor v recebido como parâmetro,
//  onde cada posição tem a média de todos os valores 
//  respectiva coluna na matriz.

void preencherVetorMedia(int m[][QTD_COLUNAS], int qtdLinhas, int qtdColunas, int v[]){
    int soma = 0, media = 0;
    for(int i = 0; i < qtdColunas; i++){
    for(int j = 0; j < qtdLinhas; j++){
    soma += m[j][i];
}
    media = soma/qtdLinhas;
    v[i] = media;
    soma = 0;
  }
}

void preencherMatriz(int m[][QTD_COLUNAS], int qtdLinhas, int qtdColunas){
    int num = 0;
    for(int i = 0; i < qtdLinhas; i++){
        for(int j = 0; j < qtdColunas; j++){
            printf("Digite o numero da celula[%d][%d]", i,j);
            scanf("%d", &num);
            m[i][j] = num;        
        }
    }
}

int main(){
    int linhas;
    printf("Digite a quantidade de linhas: ");
    scanf("%d", &linhas);

    int m[linhas][QTD_COLUNAS];
    int v[QTD_COLUNAS];

    preencherMatriz(m, linhas, QTD_COLUNAS);
    preencherVetorMedia(m, linhas, QTD_COLUNAS, v);

    printf("Medias por coluna: { ");
    for(int i = 0; i < QTD_COLUNAS; i++){
        printf("%d ", v[i]);
    }
    printf("}\n");

    return 0;
}
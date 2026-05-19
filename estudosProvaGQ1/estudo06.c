#include <stdlib.h>
#include <stdio.h>

#define QTD_COLUNAS 3

// prepreenche a matriz inteira
// com valores digitados pelo usuário

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

    preencherMatriz(m, linhas, QTD_COLUNAS);

    // imprimindo a matriz
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < QTD_COLUNAS; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}
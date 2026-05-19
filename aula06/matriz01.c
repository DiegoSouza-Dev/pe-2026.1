#include <stdio.h>

#define LIN 2
#define COL 3

void preencherMatriz(int m[][COL], int lin, int col);
void imprimirMatriz(int m[][COL], int lin, int col);

int main() {
    int m[LIN][COL];
    preencherMatriz(m, LIN, COL);
    printf("\nMatriz digitada\n");
    imprimirMatriz(m, LIN, COL);
    return 0;
}

void preencherMatriz(int m[][COL], int lin, int col) {
    for (int i = 0; i < lin; i += 1) {
        for (int j = 0; j < col; j += 1) {
            printf("Digite o valor de m[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}

void imprimirMatriz(int m[][COL], int lin, int col) {
    for (int i = 0; i < lin; i += 1) {
        for (int j = 0; j < col; j += 1) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}
#include <stdio.h>
#include <stdlib.h>

#define LIN 8
#define COL 8

void preencherMatriz(int m[][COL], int lin, int col);
void preencherMatrizAleatorio(int m[][COL], int lin, int col);
void imprimirMatriz(int m[][COL], int lin, int col);
void maiorValorMatriz(int m[][COL], int lin, int col);
void menorValorMatriz(int m[][COL], int lin, int col);
void zerarAbaixoDigPrincipal(int m[][COL], int lin, int col);
void zerarAbaixoDigPrincipalOtimizada(int m[][COL], int lin, int col);

int main() {
    int m[LIN][COL];
    srand(3);
    preencherMatrizAleatorio(m, LIN, COL);
    printf("\nMatriz preenchida\n");
    imprimirMatriz(m, LIN, COL);
    maiorValorMatriz(m, LIN, COL);
    menorValorMatriz(m, LIN, COL);
    zerarAbaixoDigPrincipalOtimizada(m, LIN, COL);
    printf("\nMatriz zerada abaixo da diagonal principal\n");
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

void preencherMatrizAleatorio(int m[][COL], int lin, int col) {
    for (int i = 0; i < lin; i += 1) {
        for (int j = 0; j < col; j += 1) {
            m[i][j] = rand() % 100 + 1;
        }
    }
}

void imprimirMatriz(int m[][COL], int lin, int col) {
    for (int i = 0; i < lin; i += 1) {
        for (int j = 0; j < col; j += 1) {
            printf("%3d\t", m[i][j]);
        }
        printf("\n");
    }
}

void maiorValorMatriz(int m[][COL], int lin, int col) {
    int iMaior = 0, jMaior = 0;
    for (int i = 0; i < lin; i += 1) {
        for (int j = 0; j < col; j += 1) {
            if (m[i][j] > m[iMaior][jMaior]) {
                iMaior = i;
                jMaior = j;
            }
        }
    }
    printf("O maior valor é %d e ele está na posição (%d, %d)\n",
        m[iMaior][jMaior], iMaior + 1, jMaior + 1);
}

void menorValorMatriz(int m[][COL], int lin, int col) {
    int iMenor = 0, jMenor = 0;
    for (int i = 0; i < lin; i += 1) {
        for (int j = 0; j < col; j += 1) {
            if (m[i][j] < m[iMenor][jMenor]) {
                iMenor = i;
                jMenor = j;
            }
        }
    }
    printf("O menor valor é %d e ele está na posição (%d, %d)\n",
        m[iMenor][jMenor], iMenor + 1, jMenor + 1);
}

void zerarAbaixoDigPrincipal(int m[][COL], int lin, int col) {
    if (lin != col) {
        printf("Essa não é uma matriz quadrada!\n");
        return;
    }
     for (int i = 0; i < lin; i += 1) {
        for (int j = 0; j < col; j += 1) {
            if (i > j) {
                m[i][j] = 0;
            }
        }
    }
}

void zerarAbaixoDigPrincipalOtimizada(int m[][COL], int lin, int col) {
    if (lin != col) {
        printf("Essa não é uma matriz quadrada!\n");
        return;
    }
     for (int i = 1; i < lin; i += 1) {
        for (int j = 0; j < i; j += 1) {
            m[i][j] = 0;
        }
    }
}

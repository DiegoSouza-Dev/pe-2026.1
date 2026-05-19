#include <stdio.h>

#define QTD 30
#define PESO1 2
#define PESO2 3

void lerNotas(double nota1[], double nota2[], int n);
void calcularMedias(double nota1[], double nota2[], double media[], int n);
double calcularMediaTurma(double media[], int n);
void imprimirAcimaMedia(double nota1[], double nota2[], double media[], int n, double mediaTurma);

void lerNotas(double nota1[], double nota2[], int n) {
    for (int i = 0; i < n; i++) {
        do {
            printf("Aluno %d - Digite a nota 1 (0-10): ", i + 1);
            scanf("%lf", &nota1[i]);
        } while (nota1[i] < 0 || nota1[i] > 10);

        do {
            printf("Aluno %d - Digite a nota 2 (0-10): ", i + 1);
            scanf("%lf", &nota2[i]);
        } while (nota2[i] < 0 || nota2[i] > 10);
    }
}

void calcularMedias(double nota1[], double nota2[], double media[], int n) {
    for (int i = 0; i < n; i++) {
        media[i] = (nota1[i] * PESO1 + nota2[i] * PESO2) / (PESO1 + PESO2);
    }
}

double calcularMediaTurma(double media[], int n) {
    double soma = 0;
    for (int i = 0; i < n; i++) {
        soma += media[i];
    }
    return soma / n;
}

void imprimirAcimaMedia(double nota1[], double nota2[], double media[], int n, double mediaTurma) {
    int achou = 0;
    for (int i = 0; i < n; i++) {
        if (media[i] > mediaTurma) {
            printf("Aluno %2d | Nota1: %5.2lf | Nota2: %5.2lf | Media: %5.2lf\n",
                   i + 1, nota1[i], nota2[i], media[i]);
            achou = 1;
        }
    }
    if (!achou) {
        printf("Nenhum aluno acima da média da turma.\n");
    }
}

int main() {
    double nota1[QTD], nota2[QTD], media[QTD];
    double mediaTurma;

    lerNotas(nota1, nota2, QTD);
    calcularMedias(nota1, nota2, media, QTD);
    mediaTurma = calcularMediaTurma(media, QTD);

    printf("Média da turma: %.2lf\n", mediaTurma);
    printf("\nAlunos acima da média da turma:\n");
    imprimirAcimaMedia(nota1, nota2, media, QTD, mediaTurma);

    return 0;
}
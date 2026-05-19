#include <stdio.h>

#define QTD 30
#define PESO1 2
#define PESO2 3

typedef struct {
    double nota1;
    double nota2;
    double media;
} Aluno;


void lerNotas(Aluno turma[], int n) {
    for (int i = 0; i < n; i++) {
        do {
            printf("Aluno %d - Digite a nota 1 (0-10): ", i + 1);
            scanf("%lf", &turma[i].nota1);
        } while (turma[i].nota1 < 0 || turma[i].nota1 > 10);

        do {
            printf("Aluno %d - Digite a nota 2 (0-10): ", i + 1);
            scanf("%lf", &turma[i].nota2);
        } while (turma[i].nota2 < 0 || turma[i].nota2 > 10);
    }
}

void calcularMedias(Aluno turma[], int n) {
    for (int i = 0; i < n; i++) {
        turma[i].media = (turma[i].nota1 * PESO1 + turma[i].nota2 * PESO2) / (PESO1 + PESO2);
    }
}

double calcularMediaTurma(Aluno turma[], int n) {
    double soma = 0;
    for (int i = 0; i < n; i++) {
        soma += turma[i].media;
    }
    return soma / n;
}

void imprimirAcimaMedia(Aluno turma[], int n, double mediaTurma) {
    int achou = 0;
    for (int i = 0; i < n; i++) {
        if (turma[i].media > mediaTurma) {
            printf("Aluno %2d | Nota1: %5.2lf | Nota2: %5.2lf | Media: %5.2lf\n",
                   i + 1, turma[i].nota1, turma[i].nota2, turma[i].media);
            achou = 1;
        }
    }
    if (!achou) {
        printf("Nenhum aluno acima da média da turma.\n");
    }
}

int main() {
    Aluno turma[QTD];
    double mediaTurma;

    lerNotas(turma, QTD);
    calcularMedias(turma, QTD);
    mediaTurma = calcularMediaTurma(turma, QTD);

    printf("Média da turma: %.2lf\n", mediaTurma);
    printf("\nAlunos acima da média da turma:\n");
    imprimirAcimaMedia(turma, QTD, mediaTurma);

    return 0;
}
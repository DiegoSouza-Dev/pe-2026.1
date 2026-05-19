#include <stdio.h>

#define MAX_QTD 5
#define MIN_IDADE 0
#define MAX_IDADE 130

int main() {
    int idades[MAX_QTD];
    int soma = 0;
    double media;
    for (int i = 0; i < MAX_QTD; i += 1) {
        do {
            printf("Digite a idade do %d participante (%d-%d): ", i + 1, MIN_IDADE, MAX_IDADE);
            scanf("%d", &idades[i]);
        } while (idades[i] < MIN_IDADE || idades[i] > MAX_IDADE);
        soma += idades[i];
    }
    if (MAX_QTD != 0) {
        media = (double) soma / (double) MAX_QTD;
        printf("A media de idade dos participantes e de %.2lf anos\n", media);

        printf("\n\nAs idades maiores ou iguais a media sao\n");
        for (int i = 0; i < MAX_QTD; i += 1) {
            if (idades[i] >= media) {
                printf("idade do %d participiante: %d\n", i + 1, idades[i]);
            }
        }
    } else {
        printf("Nenhuma idade valida foi digitada!\n");
    }
    return 0;
}
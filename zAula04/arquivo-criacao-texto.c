#include <stdio.h>
#include <string.h>

#define TAM_FRASE 100

void lerStr(char str[], int tamMax);

int main() {
    FILE *arq;
    char nomeArq[] = "teste.txt";
    char frase[TAM_FRASE];
    int status, tamFrase;

    arq = fopen(nomeArq, "wt");
    if (!arq) {
        printf("Erro ao tentar abrir o arquivo %s\n", nomeArq);
        return 1;
    }

    printf("Digite frases (linha em branco para finalizar):\n");
    lerStr(frase, TAM_FRASE);
    tamFrase = strlen(frase);
    status = fprintf(arq, "%s\n", frase);
    while (tamFrase > 0 && status == tamFrase + 1) {
        lerStr(frase, TAM_FRASE);
        tamFrase = strlen(frase);
        status = fprintf(arq, "%s\n", frase);
    }

    status = fclose(arq);
    if (status != 0) {
        printf("Erro ao tentar fechar o arquivo %s\n", nomeArq);
        return 2;
    }

    printf("Arquivo  fechado com sucesso\n", nomeArq);
    return 0;
}

void lerStr(char str[], int tamMax) {
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
}
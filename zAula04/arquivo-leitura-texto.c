#include <stdio.h>
#include <string.h>

#define TAM_FRASE 100

void lerStr(char str[], int tamMax);
char *fLerStr(char str[], int tamMax, FILE *arq);

int main() {
    FILE *arq;
    char nomeArq[] = "teste.txt";
    char frase[TAM_FRASE], *statusFrase;
    int tamFrase, status;

    arq = fopen(nomeArq, "rt");
    if (!arq) {
        printf("Erro ao tentar abrir o arquivo %s\n", nomeArq);
        return 1;
    }

    printf("Conteudo do arquivo:\n");
    printf("------------------------------------------------------------\n");
    statusFrase = fLerStr(frase, TAM_FRASE, arq);
    while (statusFrase != NULL && !feof(arq)) {
        printf("%s\n", frase);
        statusFrase = fLerStr(frase, TAM_FRASE, arq);
    }
    printf("------------------------------------------------------------\n");

    status = fclose(arq);
    if (status != 0) {
        printf("Erro ao tentar fechar o arquivo %s\n", nomeArq);
        return 2;
    }

    printf("Arquivo  fechado com sucesso\n", nomeArq);
    return 0;
}

char *fLerStr(char str[], int tamMax, FILE *arq) {
    char *res = fgets(str, tamMax, arq);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
    return res;
}

void lerStr(char str[], int tamMax) {
    fLerStr(str, tamMax, stdin);
}
#include <stdio.h>

#define QTD 5

int main ( ) {
    FILE * arq;
    char nomeArq[] = "teste.bin";
    int status, num;
    arq = fopen(nomeArq, "wb");

    if (arq == NULL) {
        printf("Erro ao tentar criar o arquivo %s\n", nomeArq);
        return 1;
    }
    
    printf("Arquivo %s criado com sucesso\n", nomeArq);

    for (int i = 1; i <= QTD; i += 1) {
        printf("Digite um numero inteiro: ");
        scanf("%d", &num);

        status = fwrite(&num, sizeof (int), 1, arq);
        if (status == 1) {
            printf ("Registro gravado com sucesso\n\n");
        } else {
            printf ("Erro na gravação do registro\n");
            break;
        }
    }

    status = fclose(arq);
    if (status == 0) {
        printf("Arquivo %s fechado com sucesso\n", nomeArq);
    } else {
        printf("Erro ao tentar fechar o arquivo %s\n", nomeArq);
        return 2;
    }

    return 0;
}
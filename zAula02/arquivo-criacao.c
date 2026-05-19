#include <stdio.h>
int main ( ) {
    FILE * arq;
    char nomeArq[] = "teste.bin";
    int status, num = 50;
    arq = fopen(nomeArq, "wb");

    if (arq == NULL) {
        printf("Erro ao tentar criar o arquivo %s\n", nomeArq);
        return 1;
    }
    
    printf("Arquivo %s criado com sucesso\n", nomeArq);

    status = fwrite(&num, sizeof (int), 1, arq);
    if (status == 1) {
        printf ("Registro gravado com sucesso\n");
    } else {
        printf ("Erro na gravação do registro\n");
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
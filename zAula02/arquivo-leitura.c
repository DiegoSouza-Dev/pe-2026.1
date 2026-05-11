#include <stdio.h>
int main ( ) {
    FILE * arq;
    char nomeArq[] = "teste.bin";
    int status, num;
    arq = fopen(nomeArq, "rb");

    if (arq == NULL) {
        printf("Erro ao tentar abrir o arquivo %s\n", nomeArq);
        return 1;
    }
    
    printf("Arquivo %s aberto com sucesso\n", nomeArq);

    status = fread(&num, sizeof (int), 1, arq);
    if (status == 1) {
        printf ("Registro lido com sucesso: %d\n", num);
    } else {
        printf ("Erro na leitura do registro\n");
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
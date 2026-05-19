#include <stdio.h>
int main ( ) {
    FILE * arq;
    char nomeArq[] = "teste.bin";
    int status, num;
    arq = fopen(nomeArq, "r+b");

    if (arq == NULL) {
        printf("Erro ao tentar abrir o arquivo %s\n", nomeArq);
        return 1;
    }
    
    printf("Arquivo %s aberto com sucesso\n", nomeArq);

    status = fread(&num, sizeof (int), 1, arq);
    while (!feof(arq)) {
        if (status == 1) {
            printf ("Registro lido com sucesso: %d\n", num);
            num *= 2;
            status = fseek(arq, -(long long int)sizeof(int), SEEK_CUR);
            if (status == 0) {
                status = fwrite(&num, sizeof (int), 1, arq);
                if (status == 1) {
                    printf ("Registro atualizado com sucesso\n");
                    fflush(arq);
                    // fseek(arq, 0, SEEK_CUR);
                } else {
                    printf ("Erro na atualização do registro\n");
                    break;
                }
            } else {
                printf ("Erro no posicionamento para a atualização do registro\n");
                break;
            }
        } else {
            printf ("Erro na leitura do registro\n");
            break;
        }
        status = fread(&num, sizeof (int), 1, arq);
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
#include <stdio.h>

#define MAX 50

// imprime o vetor
void imprimir(int v[], int n) {
    if (n == 0) {
        printf("vetor vazio\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// busca binaria
int buscaBinaria(int v[], int n, int x) {
    int ini = 0, fim = n - 1, meio;

    while (ini <= fim) {
        meio = (ini + fim) / 2;

        if (v[meio] == x)
            return meio;
        else if (v[meio] < x)
            ini = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

// insercao ordenada
void inserirOrdenado(int v[], int *n, int x) {
    if (*n >= MAX) {
        printf("vetor cheio\n");
        return;
    }

    int i = *n - 1;

    while (i >= 0 && v[i] > x) {
        v[i + 1] = v[i];
        i--;
    }

    v[i + 1] = x;
    (*n)++;
}

// remover elemento
void remover(int v[], int *n, int x) {
    int pos = buscaBinaria(v, *n, x);

    if (pos == -1) {
        printf("elemento nao encontrado\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        v[i] = v[i + 1];
    }

    (*n)--;
    printf("elemento removido\n");
}

int main() {
    int v[MAX];
    int n, qtd, valor, opcao;

    // tamanho do vetor
    do {
        printf("digite o tamanho do vetor (3 a 50): ");
        scanf("%d", &n);
    } while (n < 3 || n > 50);

    int capacidade = n;
    n = 0;

    // quantidade inicial de elementos
    printf("quantos valores deseja inserir inicialmente: ");
    scanf("%d", &qtd);

    if (qtd > capacidade) qtd = capacidade;

    // insercao inicial ordenada
    for (int i = 0; i < qtd; i++) {
        printf("digite um valor: ");
        scanf("%d", &valor);
        inserirOrdenado(v, &n, valor);
    }

    do {
        printf("\nmenu:\n");
        printf("1 - imprimir vetor\n");
        printf("2 - buscar elemento\n");
        printf("3 - remover elemento\n");
        printf("4 - inserir elemento\n");
        printf("0 - sair\n");
        printf("opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                imprimir(v, n);
                break;

            case 2:
                printf("digite o valor: ");
                scanf("%d", &valor);
                int pos = buscaBinaria(v, n, valor);
                printf("posicao: %d\n", pos);
                break;

            case 3:
                printf("digite o valor a remover: ");
                scanf("%d", &valor);
                remover(v, &n, valor);
                break;

            case 4:
                if (n >= capacidade) {
                    printf("sem espaco no vetor\n");
                } else {
                    printf("digite o valor: ");
                    scanf("%d", &valor);
                    inserirOrdenado(v, &n, valor);
                }
                break;

            case 0:
                printf("encerrando...\n");
                break;

            default:
                printf("opcao invalida\n");
        }

    } while (opcao != 0);

    return 0;
}
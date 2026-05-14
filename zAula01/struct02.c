#include <stdio.h>
#include <string.h>

#define TAM_NOME 30
#define QTD_PESSOAS 7

struct Pessoa {
    char nome[TAM_NOME];
    int idade;
    double peso, altura;
};

void lerStr(char str[], int tamMax);
void imprimirPessoa(struct Pessoa p);
void imprimirPessoas(struct Pessoa vp[], int tam);
void preencherPessoa(struct Pessoa *p);
void preencherPessoas(struct Pessoa vp[], int tam);
double calcularMediaAltura(struct Pessoa vp[], int tam);
int buscaSequencialPorNome(struct Pessoa vp[], int tam, char x[]);
void buscarNomes(struct Pessoa vp[], int tam);
void bubblesortPorNome(struct Pessoa v[], int n);
void insercaoDiretaPorNome(struct Pessoa v[], int n);
void selecaoDiretaPorIdade(struct Pessoa v[], int n);
void insercaoDiretaPorIdadeDecrescNomeCresc(struct Pessoa v[], int n);


int main() {
    struct Pessoa pessoas[QTD_PESSOAS];
    printf("---------digitacao------------\n");
    preencherPessoas(pessoas, QTD_PESSOAS);
    printf("\n---------impressao vetor original------------\n");
    imprimirPessoas(pessoas, QTD_PESSOAS);
    insercaoDiretaPorIdadeDecrescNomeCresc(pessoas, QTD_PESSOAS);
    printf("\n---------impressao vetor ordenado 1------------\n");
    imprimirPessoas(pessoas, QTD_PESSOAS);
    bubblesortPorNome(pessoas, QTD_PESSOAS);
    printf("\n---------impressao vetor ordenado 2------------\n");
    imprimirPessoas(pessoas, QTD_PESSOAS);
    double mediaAlturas = calcularMediaAltura(pessoas, QTD_PESSOAS);
    printf("\nA media de altura das pessoas e %.2lf", mediaAlturas);
    buscarNomes(pessoas, QTD_PESSOAS);
    return 0;
}

void imprimirPessoa(struct Pessoa p) {
    printf("[%15s: %d anos,  %.2lf kg,  %.2lf m]\n", p.nome, p.idade, p.peso, p.altura);
}

void imprimirPessoas(struct Pessoa vp[], int tam){
    for (int i = 0; i < tam; i += 1) {
        printf("---pessoa %d---\n", i + 1);
        imprimirPessoa(vp[i]);
    }
}

void preencherPessoa(struct Pessoa *p) {
    char tempStr[TAM_NOME];
    printf("Digite o nome:\n");
    lerStr(p->nome, TAM_NOME);
    printf("Digite a idade:\n");
    scanf("%d", &p->idade);
    printf("Digite o peso:\n");
    scanf("%lf", &p->peso);
    printf("Digite a altura:\n");
    scanf("%lf", &p->altura);
    lerStr(tempStr, TAM_NOME);
}

void preencherPessoas(struct Pessoa vp[], int tam) {
    for (int i = 0; i < tam; i += 1) {
        printf("---digitacao pessoa %d---\n", i + 1);
        preencherPessoa(&vp[i]);
    }
}

double calcularMediaAltura(struct Pessoa vp[], int tam) {
    double soma = 0.0;
    for (int i = 0; i < tam; i += 1) {
        soma += vp[i].altura;
    }
    return soma / tam;
}

int buscaSequencialPorNome(struct Pessoa vp[], int tam, char x[]) {
    for (int i = 0; i < tam; i += 1) {
        if (strcmp(vp[i].nome, x) == 0) {
            return i;
        }
    }
    return -1;
}

void bubblesortPorNome(struct Pessoa v[], int n) {
    int i, fim, pos, troca;
    struct Pessoa chave;
    troca = 1; fim = n - 2; pos = 0;
    while (troca == 1) {
        troca = 0;
        for (i = 0; i <= fim; i++) {
            if (strcmp(v[i].nome, v[i+1].nome) > 0) {
                chave = v[i]; v[i] = v[i+1]; v[i+1] = chave;
                pos = i; troca = 1;
            }
        }
        fim = pos-1;
    }
}

void insercaoDiretaPorNome(struct Pessoa v[], int n) {
    int i, j;
    struct Pessoa chave;
    for (i = 1; i <= n - 1; i += 1) {
        chave = v[i];
        j = i - 1;
        while (j >= 0 && strcmp(v[j].nome, chave.nome) > 0) {
            v[j+1] = v[j];
            j -= 1;
        }
        v[j+1] = chave;
    }
}

void insercaoDiretaPorIdadeDecrescNomeCresc(struct Pessoa v[], int n) {
    int i, j;
    struct Pessoa chave;
    for (i = 1; i <= n - 1; i += 1) {
        chave = v[i];
        j = i - 1;
        while (
            j >= 0 && (
                v[j].idade < chave.idade ||
                (v[j].idade == chave.idade && strcmp(v[j].nome, chave.nome) > 0)
            )
        ) {
            v[j+1] = v[j];
            j -= 1;
        }
        v[j+1] = chave;
    }
}


void selecaoDiretaPorIdade(struct Pessoa v[], int n) {
    int i, j, menor;
    struct Pessoa aux;
    for (i = 0; i < n - 1; i += 1) {
        menor = i;
        for (j = i + 1; j <= n - 1 ; j += 1) {
            if (v[j].idade < v[menor].idade) {
                menor = j;
            }
        }
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}


void buscarNomes(struct Pessoa vp[], int tam) {
    char nome[TAM_NOME], tempStr[TAM_NOME];
    char opcao;
    int pos;
    printf("---------busca por nome------------\n");
    do {
        printf("Digite o nome a ser buscado: \n");
        lerStr(nome, TAM_NOME);
        pos = buscaSequencialPorNome(vp, tam, nome);
        if (pos != -1) {
            printf("A pessoa %d tem o nome buscado!\n", pos + 1);
        } else {
            printf("Nenhuma pessoa com o nome procurado!\n");
        }
        printf("Voce deseja realizar outra busca (s/n): ");
        scanf("%c",&opcao);
        lerStr(tempStr, TAM_NOME);
    } while (opcao == 'S' || opcao == 's');
}

void lerStr(char str[], int tamMax) {
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
}
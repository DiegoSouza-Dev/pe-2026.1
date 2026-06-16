// questoes da possivel 1 chamada 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONTAS     50
#define MAX_OPERACOES  200
#define MAX_DEVEDORES  50

struct Conta {
    int   id;
    char  nome[100];
    float saldo;
    float limite;
};

struct Operacao {
    int   id_operacao;
    int   id_cliente;
    char  tipo[20];
    float valor;
    float saldo_apos;
};

// QUESTÃO 1 — Cadastrar conta

void cadastrarConta(struct Conta v[], int *qtd, int id, const char *nome, float saldo_inicial, float limite) {
    if (*qtd >= MAX_CONTAS) {
        printf("Erro: limite de contas atingido.\n");
        return;
    }

    if (buscar_por_id(id) != NULL) {
        printf("Erro: id %d ja existe.\n", id);
        return;
    }

    v[*qtd].id     = id;
    v[*qtd].saldo  = saldo_inicial;
    v[*qtd].limite = limite;
    strncpy(v[*qtd].nome, nome, sizeof(v[*qtd].nome) - 1);
    (*qtd)++;

    printf("Conta de '%s' cadastrada com sucesso.\n", nome);
}

void cadastrarConta(struct Conta v[], int *qtd, int id, const char *nome, float saldo_inicial, float limite) {
    if (*qtd >= MAX_CONTAS) {
        printf("Erro: limite de contas atingido.\n");
        return;
    }

    if (buscar_por_id(id) != NULL) {
        printf("Erro: id %d ja existe.\n", id);
        return;
    }

    v[*qtd].id = id;
    v[*qtd].saldo = saldo_inicial;
    v[*qtd].limite = limite;
    strcnpy(v[*qtd].nome, nome, sizeof(v[*qtd].nome) - 1);
    (*qtd)++;

    printf("Conta '%s' cadastrada com sucesso.\n", nome);
}

// bubble sorte 

void selectionSortPorDescricao(struct Produto v[], int qtd){
    int menor;
    struct Produto aux;
    for(int i = 0; i < qtd-1; i+=1){
        menor = i;
        for(int j = i + 1; j <= qtd-1; j+=1){
            if(strcmp(v[j].descricao, v[menor].descricao) < 0){
                menor = j;
            }
        }
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

void selectionSortPorDescricao(struct Produto v[], int qtd){
    int menor; 
    struct Produto aux;
    for(int i = 0; i < qtd-1; i++){
        menor = i;
        for( int j = i + 1; j <= qtd-1; j++){
            if(strcmp(v[i].descricao, v[menor].descricao) < 0){
            menor = j;;
        }
    }

    aux = v[i];
    v[i] = v[menor];
    v[menor] = aux;
}
}

int buscaBinaria(struct TIPO v[], int qtd, char *x) {

    if (qtd == 0) return -2;

    int inicio = 0;
    int fim    = qtd - 1;
    int meio;

    do {
        meio = (inicio + fim) / 2;

        if (strcmp(v[meio].CAMPO, x) > 0) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }

    } while (strcmp(v[meio].CAMPO, x) != 0 && inicio <= fim);

    if (strcmp(v[meio].CAMPO, x) == 0) {
        return meio;
    } else {
        return -1;
    }
}

int buscaBinaria(struct TIPO v[], int qtd, char *x) {
    if (qtd == 0)
        return -2;

        int inicio = 0;
        int meio;
        int fim = qtd-1;

        do{
            meio=(inicio + fim) / 2;
            if(strcmp(v[meio].CAMPO, x) > 0){
                fim = meio -1;
            } else {
                inicio = meio + 1;
            }
        } while (strcmp(v[meio].CAMPO, x) != 0 && inicio <= fim);
        if(strcmp(v[meio].CAMPO, x) == 0){
            return meio;
        } else {
            return -1;
            
        }
    
}
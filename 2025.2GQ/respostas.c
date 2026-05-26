#include <stdio.h>
#include <string.h>

#define TAM 100

struct Categoria{
    int codigo;
    char nome[50];
};

struct Produto{
    int codigo;
    char titulo[100];
    char descricao[256];
    int categoria;
    int preco;
};

void CadastrarCategoria(struct Categoria v[], int *qtd);
int buscarCategoria(struct Categoria v[], int qtd, int codigo);
void imprimirCategorias(struct Categoria v[], int qtd);
void imprimirProdutos(struct Produto vp[], int qtdProdutos, struct Categoria vc[], int qtdCategorias);
void selectionSortPorDescricao(struct Produto v[], int qtd);
int buscaBinariaPorDescricao(struct Produto v[], int qtd, char *x);
void CadastrarProduto(struct Produto vp[], int *qtdProd, struct Categoria vc[], int qtdCat);

void CadastrarCategoria(struct Categoria v[], int *qtd){
    if(TAM == *qtd){
        printf("Limite de categorias cadastradas atingido.");
        return;
    }

    int acontece = 1;
    while(acontece){
        printf("Digite o numero do codigo da categoria: ");
        int codigo;
        scanf("%d", &codigo);
        getchar();

        if(buscarCategoria(v, *qtd, codigo) != -1){
            printf("Codigo ja cadastrado.\n");
            continue;
        }

        v[*qtd].codigo = codigo;
        printf("Digite o nome da categoria: ");
        fgets(v[*qtd].nome, 50, stdin);                    
        v[*qtd].nome[strcspn(v[*qtd].nome, "\n")] = '\0';  
        *qtd += 1;
        printf("Categoria cadastrada com sucesso.\n");
        acontece = 0;
    }
}

int buscarCategoria(struct Categoria v[], int qtd, int codigo){
    for(int i = 0; i < qtd; i += 1){
        if(v[i].codigo == codigo){
            return i;
        }
    }
    return -1;
}

void imprimirCategorias(struct Categoria v[], int qtd){
    for(int i = 0; i < qtd; i += 1){
        printf("\nCodigo: %d", v[i].codigo);
        printf("\nNome: %s\n", v[i].nome);
    }
}

void CadastrarProduto(struct Produto vp[], int *qtdProd, struct Categoria vc[], int qtdCat) {
    if(TAM == *qtdProd){
        printf("Limite de produtos atingido.\n");
        return;
    }
    printf("Digite o codigo do produto: ");
    scanf("%d", &vp[*qtdProd].codigo);
    getchar();

    printf("Digite o titulo do produto: ");
    fgets(vp[*qtdProd].titulo, 100, stdin);
    vp[*qtdProd].titulo[strcspn(vp[*qtdProd].titulo, "\n")] = '\0';

    printf("Digite a descricao do produto: ");
    fgets(vp[*qtdProd].descricao, 256, stdin);
    vp[*qtdProd].descricao[strcspn(vp[*qtdProd].descricao, "\n")] = '\0';

    printf("Digite o codigo da categoria deste produto: ");
    scanf("%d", &vp[*qtdProd].categoria);
    
    printf("Digite o preco (em centavos): ");
    scanf("%d", &vp[*qtdProd].preco);
    getchar();

    *qtdProd += 1;
    printf("Produto cadastrado com sucesso!\n");
}

void imprimirProdutos(struct Produto vp[], int qtdProdutos, struct Categoria vc[], int qtdCategorias){
    for(int i = 0; i < qtdProdutos; i += 1){
        printf("\nCodigo: %d", vp[i].codigo);
        printf("\nTitulo: %s", vp[i].titulo);
        printf("\nDescricao: %s", vp[i].descricao);
        int idx = buscarCategoria(vc, qtdCategorias, vp[i].categoria);
        if(idx != -1){
            printf("\nCategoria: %s", vc[idx].nome);
        } else {
            printf("\nCategoria: Desconhecida");
        }
        printf("\nPreco: %.2lf\n", vp[i].preco/100.0);
    }
}

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

int buscaBinariaPorDescricao(struct Produto v[], int qtd, char *x){
    if(qtd == 0){
        return -2;
    }

    int inicio = 0, meio, fim = qtd-1;
    do{
        meio = (inicio + fim) / 2;
        if(strcmp(v[meio].descricao, x) > 0){
            fim = meio - 1;
        }else{
            inicio = meio + 1;
        }
    } while(strcmp(v[meio].descricao, x) != 0 && inicio <= fim);

    if(strcmp(v[meio].descricao, x) == 0){
        return meio;
    } else {
        return -1;
    }
}

// 2. A FUNÇÃO MAIN FICA AQUI POR ÚLTIMO:
int main(){
    struct Categoria categorias[TAM];
    struct Produto produtos[TAM];
    int qtdCat = 0;
    int qtdProd = 0;
    int opcao;
    char termoBusca[256];
    int resultadoBusca;

    do {
        printf("\n--- SISTEMA DE GESTAO ---\n");
        printf("1. Cadastrar Categoria\n");
        printf("2. Mostrar Categorias\n");
        printf("3. Cadastrar Produto\n");
        printf("4. Mostrar Produtos\n");
        printf("5. Ordenar Produtos por Descricao (Selection Sort)\n");
        printf("6. Buscar Produto por Descricao (Busca Binaria)\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                CadastrarCategoria(categorias, &qtdCat);
                break;
            case 2:
                printf("\n--- CATEGORIAS CADASTRADAS ---");
                imprimirCategorias(categorias, qtdCat);
                break;
            case 3:
                CadastrarProduto(produtos, &qtdProd, categorias, qtdCat);
                break;
            case 4:
                printf("\n--- PRODUTOS CADASTRADOS ---");
                imprimirProdutos(produtos, qtdProd, categorias, qtdCat);
                break;
            case 5:
                selectionSortPorDescricao(produtos, qtdProd);
                printf("Produtos ordenados com sucesso!\n");
                break;
            case 6:
                printf("Digite a descricao exata para buscar: ");
                fgets(termoBusca, 256, stdin);
                termoBusca[strcspn(termoBusca, "\n")] = '\0';
                
                resultadoBusca = buscaBinariaPorDescricao(produtos, qtdProd, termoBusca);
                if(resultadoBusca >= 0) {
                    printf("\nProduto encontrado no indice %d!\n", resultadoBusca);
                    printf("Titulo: %s\n", produtos[resultadoBusca].titulo);
                } else {
                    printf("\nProduto nao encontrado (Certifique-se de que ordenou a lista antes).\n");
                }
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}
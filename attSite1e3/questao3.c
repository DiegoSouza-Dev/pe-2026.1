#include <stdio.h>
#include <string.h>

#define MAX_CONTAS 100

struct Conta {
    int numero;
    char nome[50];
    char cpf[15];
    char telefone[15];
    float saldo;
};

// (a) Função de busca
int buscarConta(struct Conta c[], int n, int numConta){
    if(n == 0) return -1;
    
    for(int i = 0; i < n; i++){
        if(c[i].numero == numConta) return i;
    }
    return -2;
}

// (b) Procedimento para cadastrar nova conta
void cadastrarConta(struct Conta c[], int *n){
    if(*n >= MAX_CONTAS){
        printf("Limite de contas atingido!\n");
        return;
    }
    
    int numConta;
    printf("\nNumero da conta: ");
    scanf("%d", &numConta);
    
    if(buscarConta(c, *n, numConta) != -2){
        printf("Erro: Conta ja existe!\n");
        return;
    }
    
    c[*n].numero = numConta;
    
    printf("Nome do titular: ");
    scanf(" %[^\n]", c[*n].nome);
    
    printf("CPF: ");
    scanf("%s", c[*n].cpf);
    
    printf("Telefone: ");
    scanf("%s", c[*n].telefone);
    
    printf("Saldo inicial: ");
    scanf("%f", &c[*n].saldo);
    
    (*n)++;
    printf("Conta cadastrada com sucesso!\n");
}

// (c) Procedimento para consultar saldo
void consultarSaldo(struct Conta c[], int n, int numConta){
    int idx = buscarConta(c, n, numConta);
    
    if(idx == -1){
        printf("Cadastro vazio!\n");
        return;
    }
    if(idx == -2){
        printf("Conta nao cadastrada!\n");
        return;
    }
    
    printf("Saldo de %s: R$ %.2f\n", c[idx].nome, c[idx].saldo);
}

// (d) Procedimento para fazer depósito
void fazerDeposito(struct Conta c[], int n, int numConta){
    int idx = buscarConta(c, n, numConta);
    
    if(idx == -1){
        printf("Cadastro vazio!\n");
        return;
    }
    if(idx == -2){
        printf("Conta nao cadastrada!\n");
        return;
    }
    
    float valor;
    printf("Valor do deposito: ");
    scanf("%f", &valor);
    
    if(valor <= 0){
        printf("Valor invalido!\n");
        return;
    }
    
    c[idx].saldo += valor;
    printf("Deposito realizado! Novo saldo: R$ %.2f\n", c[idx].saldo);
}

// (e) Procedimento para fazer saque
void fazerSaque(struct Conta c[], int n, int numConta){
    int idx = buscarConta(c, n, numConta);
    
    if(idx == -1){
        printf("Cadastro vazio!\n");
        return;
    }
    if(idx == -2){
        printf("Conta nao cadastrada!\n");
        return;
    }
    
    float valor;
    printf("Valor do saque: ");
    scanf("%f", &valor);
    
    if(valor <= 0){
        printf("Valor invalido!\n");
        return;
    }
    
    if(valor > c[idx].saldo){
        printf("Saldo insuficiente! Saldo atual: R$ %.2f\n", c[idx].saldo);
        return;
    }
    
    c[idx].saldo -= valor;
    printf("Saque realizado! Novo saldo: R$ %.2f\n", c[idx].saldo);
}

// (f) Procedimento para exibir todas as contas
void exibirContas(struct Conta c[], int n){
    if(n == 0){
        printf("Nenhuma conta cadastrada!\n");
        return;
    }
    
    printf("\n========== CONTAS CADASTRADAS ==========\n");
    for(int i = 0; i < n; i++){
        printf("Conta: %d | Nome: %s | Telefone: %s\n", 
               c[i].numero, c[i].nome, c[i].telefone);
    }
    printf("========================================\n");
}

// Menu principal
void menu(){
    printf("\n===== BANCO DINHEIRO CERTO =====\n");
    printf("1. Cadastrar nova conta\n");
    printf("2. Consultar saldo\n");
    printf("3. Fazer deposito\n");
    printf("4. Fazer saque\n");
    printf("5. Exibir todas as contas\n");
    printf("6. Sair\n");
    printf("================================\n");
    printf("Escolha uma opcao: ");
}

int main(){
    struct Conta contaCorrente[MAX_CONTAS];
    struct Conta contaPoupanca[MAX_CONTAS];
    int nCorrente = 0, nPoupanca = 0;
    int opcao, tipo, numConta;
    
    while(1){
        menu();
        scanf("%d", &opcao);
        
        if(opcao == 6){
            printf("Saindo...\n");
            break;
        }
        
        if(opcao >= 2 && opcao <= 4){
            printf("Tipo de conta (1-Corrente, 2-Poupanca): ");
            scanf("%d", &tipo);
            
            if(tipo != 1 && tipo != 2){
                printf("Tipo invalido!\n");
                continue;
            }
        }
        
        switch(opcao){
            case 1:
                printf("Tipo de conta (1-Corrente, 2-Poupanca): ");
                scanf("%d", &tipo);
                
                if(tipo == 1){
                    cadastrarConta(contaCorrente, &nCorrente);
                } else if(tipo == 2){
                    cadastrarConta(contaPoupanca, &nPoupanca);
                } else {
                    printf("Tipo invalido!\n");
                }
                break;
                
            case 2:
                printf("Numero da conta: ");
                scanf("%d", &numConta);
                
                if(tipo == 1){
                    consultarSaldo(contaCorrente, nCorrente, numConta);
                } else {
                    consultarSaldo(contaPoupanca, nPoupanca, numConta);
                }
                break;
                
            case 3:
                printf("Numero da conta: ");
                scanf("%d", &numConta);
                
                if(tipo == 1){
                    fazerDeposito(contaCorrente, nCorrente, numConta);
                } else {
                    fazerDeposito(contaPoupanca, nPoupanca, numConta);
                }
                break;
                
            case 4:
                printf("Numero da conta: ");
                scanf("%d", &numConta);
                
                if(tipo == 1){
                    fazerSaque(contaCorrente, nCorrente, numConta);
                } else {
                    fazerSaque(contaPoupanca, nPoupanca, numConta);
                }
                break;
                
            case 5:
                printf("1-Contas Correntes, 2-Contas Poupanca: ");
                scanf("%d", &tipo);
                
                if(tipo == 1){
                    exibirContas(contaCorrente, nCorrente);
                } else if(tipo == 2){
                    exibirContas(contaPoupanca, nPoupanca);
                } else {
                    printf("Tipo invalido!\n");
                }
                break;
                
            default:
                printf("Opcao invalida!\n");
        }
    }
    
    return 0;
}9
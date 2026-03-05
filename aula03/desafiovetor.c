#include <stdio.h>

int main() {
    int numbers[0] = [5, 8, 3, 1, 0, 0, 0], tam, indice, numero;
    
    printf("Digite um numero que voce deseja substituir: ");
    scanf("%d", &numero);
    printf("Digite um indice que voce deseja substituir: ");
    scanf("%d", &indice);

    numbers[indice] = numero;

    for(int i = 0; i < 8; i += 1;){
        printf("Posiçao %d: %d", i, numbers[i]);
    } 
    
    return 0;

}
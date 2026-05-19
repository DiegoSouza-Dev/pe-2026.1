#include <stdio.h>

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main() {
    int m = 5, n = 4;
    troca(&m, &n);
    printf("m = %d n = %d",  m, n);

    return 0;
}
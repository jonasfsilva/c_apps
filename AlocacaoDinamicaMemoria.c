#include <stdio.h>
#include <stdlib.h>

int* alocaVetor(int tamanho){
    int *aux;

    /* Aloca memoria no vetor e pega o tamanho que um int ocupa na memoria */
    aux = (int*) malloc(tamanho * sizeof(int));

    return aux;
}

int main (){

    /* declara um ponteiro para alocar o vetor na memoria */
    int *vetor, tamanho, count;

    printf("Digite um tamanho para o vetor dinamico...\n");
    scanf("%d", &tamanho);
    vetor = alocaVetor(tamanho);

    for(count=0; count<tamanho; count++){
        vetor[count] = count + 1;
    }

    for(count=0; count<tamanho; count++){
        printf("%d\n", vetor[count]);
    }

    /* removendo memoria alocada */
    free(vetor);
    /* fim do programa */
    return 0;
}


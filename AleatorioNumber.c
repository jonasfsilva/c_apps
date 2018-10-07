#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){

    /* programa */
    srand((unsigned)time(NULL));

    int aleatorio = rand() % 3;

    int aleatorio_2 = (rand() % 3) + 1;

    printf("Aleatorio 1 %d: \n", aleatorio);
    printf("Aleatorio 2 %d: \n", aleatorio_2);


    /* fim do programa */
    return 0;
}


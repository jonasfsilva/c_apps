#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){

    /* programa */
    char palavra[10];
    printf("Digite uma palavra...");

    setbuf(stdin, 0);

    fgets(palavra, 255, stdin);
    palavra[strlen(palavra)-1] = '\0';

    printf("%s", palavra);
    /* fim do programa */
    return 0;
}


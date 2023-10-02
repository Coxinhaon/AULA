#include <stdio.h>
#include <stdlib.h>

int main(){
    int v;
    char *p;
    printf ("\nescreva o numero da string\n");
    scanf("%i",&v);
    p=(char *) malloc(v*sizeof(char));
    printf("\nescreva o conteudo da string\n");
    fflush(stdin);
    scanf(" %s",p);
    printf("\n%s",p);
    free(p);
    return 0;
}
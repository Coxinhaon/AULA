#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * arq;
    int i;
    char s[100],c;
    arq = fopen("arq.txt","r+");

    if (arq == NULL){
        printf("Não foi possivel abrir o arquivo");
        return 0;
    };

    while ((c = fgetc(arq)) != EOF ){
        printf("%c",c);
    }

    fclose(arq);
    return 0;
}
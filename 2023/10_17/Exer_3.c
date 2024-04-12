#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    FILE * arq;
    char c;
    int con=0;
    arq = fopen("arq.txt","r+");

    while((c = fgetc(arq)) != EOF){
        switch(tolower(c)){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            con++;
            break;
        };

    };

    printf ("a quantidade de vogais é %i",con);

    return 0;
}
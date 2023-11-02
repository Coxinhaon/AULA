#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * arq;
    char c;
    int con=0;
    arq = fopen("arq.txt","r+");

    while((c = fgetc(arq)) != EOF){
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            con++;
        }
    
    };

    printf ("a quantidade de vogais é %i",con);

    return 0;
}
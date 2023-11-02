#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE * arq;
    int i;
    arq = fopen("arq.txt", "r+");

    for (i=0;i<100;i++){
        fprintf(arq,"%i\n",i+1);

    };


    fclose(arq);
    return 0;
}
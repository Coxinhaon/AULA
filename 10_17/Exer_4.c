#include <stdio.h>
#include <stdlib.h>

struct reg{
    char nome[50];
    int matri,idade;
};

int main(){
    FILE *arq;
    struct reg reg ={"Joao carlos", 2323 , 18};
    arq = fopen("arq.txt","w");
    if (arq == NULL){
        printf("Erro na abertura");
        return 0;
    };

    fwrite(&reg, sizeof(struct reg),1,arq);


    return 0;
}
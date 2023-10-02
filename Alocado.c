#include <stdio.h> 
#include <stdlib.h>

int main(){
    int l,c,**p,i,j,soma;
    soma=0;
    printf("escreva o valor de linha");
    scanf("%i",&l);
    printf("escreva o valor de coluna");
    scanf("%i",&c);
    p=(int**) malloc (l * sizeof(int*));
    for(i=0;i<l;i++)
    {
        p[i]=(int*) malloc (c* sizeof(int));
        for(j=0;j<c;j++)
        {
            printf("escreva o valor da linha %i da coluna %i",i+1,j+1);
            scanf("%i",&p[i][j]);
        };
    };
    for(i=0;i<l;i++)
    {
        printf("\n");
        for(j=0;j<c;j++)
        {
            printf(" %i |",p[i][j]);
            soma=soma+p[i][j];
        }
    }
    printf("\n soma total é %i",soma);
    for(i=0;i<c;i++){
        free(p[i]);
    }
    free(p);
    return 0;
}
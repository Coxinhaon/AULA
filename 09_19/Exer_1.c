#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,qta,*p;
    printf("escreva quantos coponentes tem");
    scanf("%i",&qta);
    p=(int *)malloc(qta*sizeof(int));
    for(i=0;i<qta;i++){
        printf("\nescreva o valor do componente %i\n",i+1);
        scanf("%i",&p[i]);
    }
    for(i=0;i<qta;i++){
        printf("\n valor do componente %i é %i\n",i+1,p[i]);
    }
    free(p);
    return 0;
}
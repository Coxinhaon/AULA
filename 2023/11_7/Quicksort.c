#include <stdio.h>
#include <stdlib.h>

int particiona(int *v,int inicio,int final){
    int esq,dir,pivo,aux;
    esq  = inicio;
    dir  = final;
    pivo = v[inicio];
    while (esq < dir){
        while(v[esq] <= pivo) {
            esq++;
        };
        while(v[dir] > pivo){        
            dir--;
        };
        if(esq < dir){
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        };
    }
    v[inicio] = v[dir];
    v[dir] = pivo;
    return dir;
}
void quicksort(int *v, int inicio,int fim){
    int pivo;
    if (fim > inicio){
        pivo = particiona(v,inicio,fim);
        quicksort (v,inicio,pivo-1);
        quicksort (v,pivo + 1, fim);
    }
}



int main(){
int *v,n,i;
printf("escreva o numero de espaços do vetor");
scanf("%i",&n);
v=(int *)malloc (n * sizeof(int));
for (i = 0;i < n;i++){
    printf("Escreva o valor da posição %i",i+1);
    scanf("%i",&v[i]);
};
printf("vetor organizado");
quicksort(v,0,n - 1);
for (i = 0;i < n;i++){
    printf("\n %i",v[i]);
};

    return 0;
}
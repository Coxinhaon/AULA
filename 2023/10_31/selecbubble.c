#include <stdio.h>
#include <stdlib.h>

void selectionsort(int * v , int n){
    int i, j,menor,troca;
    for (i = 0;i < n;i++){
        menor = i;
        for (j = i + 1; j < n; j++){
            if (v[j]<v[menor]){
                menor = j;
            }; 
        };
        if (i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        };
    }
}


int main(){
    int n,i;
    printf("escreva quantos numeros terá o vetor");
    scanf("%i",&n);
    int v[n];
    for (i = 0;i < n;i++){
        printf("escreva o valor da posição %i",i+1);
        scanf("%i",&v[i]);
    };
    selectionsort(v,n);
    printf ("valores ordenados por selectionsort:");

    for (i = 0;i < n;i++){
        printf("\n %i ",v[i]);
    };

    return 0;
}
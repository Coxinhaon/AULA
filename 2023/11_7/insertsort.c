#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *v,int n){
    int i,j,aux;
    j=0;
    for (i = 1; i < n; i++){
        aux = v[i];
        j = i - 1;
        while ((j >=0) && (aux < v[j])){
            v[j + 1] = v[j];
            j--;
        };
        v[j + 1] = aux;
    }
}



int main(){
    int *v;
    int i,n;
    printf("escreva quantos numeros terá o vetor");
    scanf("%i",&n);
    v= (int *)malloc (n * sizeof(int));
    for (i = 0;i < n;i++){
        printf("escreva o valor da posição %i",i+1);
        scanf("%i",&v[i]);
    };
    insertion_sort(v,n);
    printf("valores ordenador por insertsort");

    for (i = 0;i < n;i++){
        printf("\n %i ",v[i]);
    };


    return 0;
}
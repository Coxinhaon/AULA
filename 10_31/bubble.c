#include <stdio.h>
#include <stdlib.h>


void bubblesort(float *v,int n){
    int i,cont,aux,fim=n;
    do{
        cont=0;
        for (i = 0;i < fim - 1;i++){
            if (v[i] > v[i+1]){
                aux = v[i];
                v[i] = v [i + 1];
                v[i + 1] = aux;
                cont=i;
            }
        }
        fim --;
    }while(cont != 0);
}


int main(){
    int n,i;
    printf("escreva quantos numeros terá o vetor");
    scanf("%i",&n);
    float v[n];
    for (i = 0;i < n;i++){
        printf("escreva o valor da posição %i",i+1);
        scanf("%f",&v[i]);
    };
    bubblesort(v,n);
    printf("valores ordenados");
    for (i = 0;i < n;i++){
        printf("\n %f ",v[i]);
    };

    return 0;
}
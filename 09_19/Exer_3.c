#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,v;
    float *p,vmenor,vmaior,vtotal=0,vm;
    printf("escreva a quantiidade de aluno ");
    scanf("%i",&v);
    p=(float *) malloc (v * sizeof(float));
    for(i=0;i<v;i++){
        printf("escreva a nota do aluno %i ",i+1);
        scanf("%f",&p[i]);
    }
    vmaior=vmenor=p[0];
    for(i=0;i<v;i++){
        vtotal+=p[i];
        if (p[i]>vmaior){
            vmaior=p[i];
        }else if(p[i]<vmenor){
            vmenor=p[i];
        }
    }
    vm=vtotal/v;
    printf("a maior nota foi %.1f\n a menor nota foi %.1f\n e a media foi %.1f\n",vmaior,vmenor,vm);


    return 0;
}
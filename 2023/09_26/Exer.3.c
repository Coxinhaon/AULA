#include <stdio.h>
#include <stdlib.h>

struct taref{
    char nome[50];
    float tgas;
};

int main(){
    int t,i;
    float ttotal=0;
    struct taref*p;
    printf("escreva o numero de tarefas");
    scanf("%i",&t);
    p=(struct taref*)malloc (t *sizeof(struct taref));
    for(i=0;i<t;i++){
        printf("\n tarefa %i \n",i+1);
        printf("escreva o nome da tarefa\n");
        fflush(stdin);
        gets(p[i].nome);
        printf("escreva o tempo gasto em minutos\n");
        scanf("%f",&p[i].tgas);
    }

    for(i=0;i<t;i++){
        ttotal+=p[i].tgas;
        printf("\ntarefa %i\n",i+1);
        printf("nome: %s\n",p[i].nome);
        printf("tempo gasto: %.2f",p[i].tgas);
    }
    printf("\ntempo gasto total: %.2f\n", ttotal);
    free(p);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct produto{
    char nome[50];
    int codigo;
    char desc[100];
    float preco;

};

int main(){
    int qta,i;
    struct produto * p;
    printf("escreva o quantos produtos vão ser cadastrado");
    scanf("%i",&qta);
    p=(struct produto *)malloc(qta* sizeof (struct produto));
    for(i=0;i<qta;i++)
    {
        printf("\n escreva produto %i \n",i+1);
        printf("escreva o nome do produto\n");
        fflush(stdin);
        gets(p[i].nome);
        p[i].codigo=i+1;
        printf("escreva a descrição do produto\n");
        fflush(stdin);
        gets(p[i].desc);
        printf("escreva o valor do produto \n");
        scanf("%f",&p[i].preco);
    };
    
    for(i=0;i<qta;i++){
        printf("\n nome: %s\n",p[i].nome);
        printf("codigo: %d\n",p[i].codigo);
        printf(" Descrição: %s\n",p[i].desc);
        printf("valor: %.2f\n",p[i].preco);
    }
    free(p);
    return 0;
}

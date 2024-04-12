#include <stdio.h>
#include <stdlib.h>

struct reg{
    char nome[50];
    int matri,idade;
};

int main(){
    FILE *arq;
    struct reg reg ={"Joao carlos", 2323 , 18};
    arq = fopen("arq.txt","r+");
    char linha[100];
    if (arq == NULL){
        printf("Erro na abertura");
        return 0;
    };
    
    printf("\n Escreva o nome: \n");
    fflush(stdin);
    gets(reg.nome);
    printf("\n Escreva a Matricula \n ");
    scanf("%d",&reg.matri);
    printf("\n Escreva a idade \n ");
    scanf("%d",&reg.idade);
    fprintf(arq,"Nome: %s \nMatricula: %d \nIdade: %d \n",reg.nome, reg.matri, reg.idade);



    // fwrite(&reg,sizeof (struct reg), 1, arq);
    // if (ferror(arq)){
    //     printf("\n erro gravação \n");
    // }else{
    //     printf("\n sucesso gravação \n");
    // };


    system("cls");
    printf(" DADOOS DOOO ARQUIVO");
    arq= fopen("arq.txt","r");
    
    while (fgets(linha,sizeof(linha),arq) != NULL){
        printf("%s",linha);
    }
    fclose(arq);
    return 0;
}
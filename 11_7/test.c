#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int ID;
    char Nome[50];
    int Idade;
}cliente;

void cad_cliente(){
    cliente c;
    printf("################################### CADASTRO DO CLIENTE ###################################");
    printf("\n ID do cliente: ");
    scanf("%i",&c.ID);
    printf(" \n Nome do cliente: ");
    fflush(stdin);
    gets(c.Nome);
    printf(" \n Idade do cliente: ");
    scanf("%i",&c.Idade);
    FILE * arq=fopen("arquivo.txt","a");
    fprintf(arq," %i  /  %s  /  %i  \n",c.ID,c.Nome,c.Idade);
    fclose(arq);

}
void imp_cliente(){
    FILE * arq=fopen("arquivo.txt","r");
    char linha[100];
    while((fgets(linha,sizeof(linha),arq)) != NULL){
        printf(" \n %s \n",linha);
    }
}
void menu_p(){
    printf("             MENU              \n");
    printf("Digite 1 para cadastrar cliente\n");
    printf(" Digite 2 para mostrar clientes\n");
    printf("      Digite 0 para sair       \n");
}
void orga_txt(){
    FILE * arq = fopen ("arquivo.txt","r");
    char linha[100], **linhas;
    int contador = 0,vetor[contador],i;
    while((fgets(linha,sizeof(linha),arq)) != NULL){
        contador ++;
        linhas = realloc (linha,contador * sizeof(char*));
        linhas[contador - 1]=malloc (strlen(linha + 1));
        strcpy(linhas[contador - 1],linha);
        vetor[contador - 1] = atoi(linha);
    };
    for (i = 0;i < contador;i++){
        printf(" \n %i",vetor[i]);
        free(linhas[i]);
    };
    free(linhas);
    fclose(arq);
}

int main(){
    int menu=0;
    do{
        menu_p();
        scanf("%i",&menu);
        switch (menu)
        {
        case 1:
            cad_cliente();
            break;
        
        case 2:
            imp_cliente();
            break;
        
        case 3:
            orga_txt();
            break;
        case 0:
            printf("Até a proxima");
            Sleep(2000);
        default:
            break;
        }
    }while(menu != 0);



    return 1;
}
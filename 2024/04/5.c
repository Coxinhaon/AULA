#include <stdlib.h>
#include <stdio.h>

int sumValue(int *a,int size){
    int aux=0;
    for(int i = 0;i<size;i++){
        aux+=a[i];
    }
    return aux;
}
int getHigher(int *a,int size){
    int aux = a[0];
    for(int i=1;i<size;i++){
        if(a[i] > aux){
            aux = a[i];
        }
    }
    return aux;
}
void addStudent(){
    char name[50];
    float mean;
    FILE *arq = fopen("Alunos.txt","a");
    printf("Escreva o nome do aluno");
    fflush(stdin);
    gets(name);
    printf("Escreva a media do aluno");
    scanf("%f",&mean);
    fprintf(arq,"%s  %.2f\n",name,mean);
    fclose(arq);
}
void seeStudent(){
    char buffer[100];
    FILE *arq = fopen("Alunos.txt","r");
    while (fgets(buffer,100,arq) != NULL){
        printf(" %s \n",buffer);
    }
    fclose(arq);
}
void addCouser(){
    char name[50];
    FILE *arq = fopen("Curso.txt","a");
    printf("Escreva o nome do curso");
    fflush(stdin);
    gets(name);
    fprintf(arq," %s ",name);
    fclose(arq);
}
void seeCouser(){
    char buffer[100];
    FILE *arq = fopen("Curso.txt","r");
    while (fgets(buffer,100,arq) != NULL){
        printf(" %s \n",buffer);
    }
    fclose(arq);
}

int main(){
    // //Exer 1 e 2:
    // int *array = (int*)malloc(5*sizeof(int));
    // for (int i = 0;i < 5;i++){
    //     array[i]=i+1;
    // }
    // printf("valor da soma do valores do vetor %i ",sumValue(array,5));
    // printf("O maior numero %i do array",getHigher(array,5));
    // free(array);
    int menu;
    int breakLoop = 0;
    while(breakLoop == 0){
        printf("Escreva \n 1 == adicionar aluno \n 2 == ver alunos \n 3 == adicionar curso \n 4 == ver curso\n 0 == Sair \n");
        scanf("%i",&menu);
        switch (menu)
        {
        case 0:
            breakLoop = 1;
            break;
        case 1:
            addStudent();
            break;
        case 2:
            seeStudent();
            break;
        case 3: 
            addCouser();
            break;
        case 4:
            seeCouser();
            break;
        default:
            printf("valor invalido");
            break;
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  School{

    char name[50];
    int registration_number;
    int code_displine;
    float note_1;
    float note_2;

}School;

void add_school(School *list,char name[],int reg_number,int code_displine,float note_1,float note_2){

    strcpy(list->name,name);
    list->registration_number = reg_number;
    list->code_displine = code_displine;
    list->note_1 = note_1;
    list->note_2 = note_2;

}

void exer_1(){

    School * list = malloc(10 * sizeof(School));

    char name[50];
    int reg_number,code_displine;
    float note_1,note_2;

    for(int i = 0; i < 10; i ++){

        printf("\nEscreva o nome: ");
        fflush(stdin);
        gets(name);

        printf("\nEscreva a matricula: ");
        scanf("%i", &reg_number);

        printf("\nEscreva o codigo da disiplina: ");
        scanf("%f", &code_displine);

        printf("Escreva a nota 1: ");
        scanf("%f", &note_1);

        printf("Escreva a nota 2: ");
        scanf("%f", &note_2);

        add_school(&list[i],name,reg_number,code_displine,note_1,note_2);

    }

    for (int i = 0; i < 10; i++){

        printf("\nNome: %s media: %.2f",list[i].name,(list[i].note_1 + list[i].note_2*2)/3);

    }

}

typedef struct Employers{

    char name[50];
    int age;
    char gender;
    char CPF[11];
    char born_date[11];
    int section;
    char post[30];
    float wage;

}Employers;

void add_employer(Employers *list,char name[],int age,char gender,char CPF[],char born_date[],int section,char post[],float wage){

    strcpy(list->name,name);
    list->age = age;
    strcpy(list->gender,gender);
    strcpy(list->CPF,CPF);
    strcpy(list->born_date,born_date);
    list->section = section,
    strcpy(list->post,post);
    list->wage = wage;

    FILE * arq = fopen("arquivo.txt","a");

    fprintf(arq,"\nNome: %s \nIdade: %i \n Genero %c \n CPF  %s \n Data de nascimento: %s \n Setor : %s \n Posto: %s \n Salario %.2f \n",list->name,list->age,list->gender,list->CPF,list->born_date,list->section,list->post,list->wage);


}

void Exer_2(){
    Employers employer;

    char name[50],gender,cpf[11],born_date[11],post[30];
    int age,section;
    float wage;

    printf("\n Escreva o nome");
    fflush(stdin);
    gets(name);

    printf("\n Escreva o idade");
    scanf("%i",&age);

    printf("\n Escreva m ou f");
    scanf(" %c",&gender);

    printf("\n Escreva o cpf");
    fflush(stdin);
    gets(cpf);

    printf("\n Escreva o data de nascimento");
    fflush(stdin);
    gets(born_date);

    printf("\n Escreva o setor");
    fflush(stdin);
    gets(post);

    printf("\nEscreva o salario");
    scanf("%f",wage);

    add_employer(&employer,name,age,gender,cpf,born_date,section,post,wage);

}

typedef struct Schedule{

    char name[50];
    char adress[50];
    char phone[20];

}Schedule;


void add_schedule(Schedule * list,char name[], char adress[], char phone[]){

    strcpy(list->name,name);
    strcpy(list->adress,adress);
    strcpy(list->phone,phone);

}



void bubblesort(Schedule *list, int size) {

    int endWhile = 1;

    Schedule temp;

    while (endWhile != 0) {

        endWhile = 0;

        for (int i = 0; i < size - 1; i++) {

            if (strcmp(list[i].name, list[i + 1].name) > 0) {

                temp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = temp;
                
                endWhile = 1;

            }
        }
    }
}




void Exer_3(){

    Schedule *list = malloc(5*sizeof(Schedule));

    add_schedule(list,"Jao","rua da legal","99999");
    add_schedule(&list[1],"Pedro","rua da triste","99991239");
    add_schedule(&list[2],"Carlos","rua da rua","9111139");
    add_schedule(&list[3],"Fer","rua","123991239");
    add_schedule(&list[4],"Lucas","rua 2323","99123239");

    bubblesort(list,5);

    for(int i = 0; i < 5 ; i++ ){
        printf("nome: %s ",list[i].name);
    }



}


int main(){

    Exer_3();


    return 1;
}
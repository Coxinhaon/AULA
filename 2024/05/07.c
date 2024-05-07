#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Hour{

    int hour;
    int minuts;
    int seconds;

}Hours;



typedef struct  Date{

    int day;
    int month;
    int year;

}Date;


typedef struct  Schedule{

    Date date;
    Hours hour;
    char desc[50];

}Schedule;


typedef struct Student{

    char name[50];
    int registration_number;
    char subject[50];
    
}Student;


void add_student(Student * list,char name[],int reg_number,char subject[]){

    strcpy(list->name,name);
    list->registration_number = reg_number;
    strcpy(list->subject,subject);

}


void exer_2(){
    Student * list = malloc(5*sizeof(Student)); 
    
    add_student(list,"Jao",2323,"Matematica");
    add_student(&list[1],"Milena",2324,"Logica matematica");
    add_student(&list[2],"Ingrid",2325,"Eletronica");
    add_student(&list[3],"Amilton",2326,"Maneiro");
    add_student(&list[4],"Fernando",2327,"Sinuqueiro");

    for(int i = 0; i < 5; i ++){

        printf("Nome: %s Matricula: %i Materia: %s \n",list[i].name,list[i].registration_number,list[i].subject);

    }

    free(list);

}

typedef struct Students{

    int registration_number;
    char name[50];
    float first_note;
    float second_note;
    float third_note;

}Students;

void add_students(Students *list,char name[],int reg_number,float first_note,float second_note,float third_note){

    list->registration_number = reg_number;
    strcpy(list->name,name);
    list->first_note = first_note;
    list->second_note = second_note;
    list->third_note = third_note;

}

int main(){
    //exer_2();

    Students * list = malloc(5*sizeof(Students));

    char name[50];
    int reg_number,index_min,index_max,index_max_first;
    float first_note, second_note, third_note, max_mean, min_mean;

    for(int i = 0; i < 5;i ++){

        printf("\n Escreva o nome: \n");
        fflush(stdin);
        gets(name);

        printf("\n Escreva o numero da matricula: \n");
        scanf("%i",&reg_number);

        printf("\n Escreva a primeira nota: \n");
        scanf("%f",&first_note);

        printf("\n Escreva a segunda nota: \n");
        scanf("%f",&second_note);

        printf("\n Escreva a terceira nota: \n");
        scanf("%f",&third_note);

        add_students(&list[i],name,reg_number,first_note,second_note,third_note);

    }
    
    max_mean = (list[0].first_note + list[0].second_note + list[0].third_note) / 3;
    min_mean = max_mean;
    index_min = 0;
    index_max = 0;
    index_max_first = 0;

    for( int i = 0; i < 5; i ++){
        
        if( max_mean < (list[i].first_note + list[i].second_note + list[i].third_note) / 3 ){

            max_mean = (list[i].first_note + list[i].second_note + list[i].third_note) / 3;
            index_max = i;

        }

        if( min_mean > (list[i].first_note + list[i].second_note + list[i].third_note) / 3 ){

            min_mean = (list[i].first_note + list[i].second_note + list[i].third_note) / 3;
            index_min = i;

        }

        if( list[i].first_note > list[index_max_first].first_note){

            index_max_first = i;

        }

        if ((( list[i].first_note + list[i].second_note + list[i].third_note )  / 3) >= 6 ){

            printf("\n Nome: %s foi aprovado",list[i].name);

        }else{

            printf("\n Nome: %s foi reprovado",list[i].name);

        }
        
    }


    printf("\n Aluno com a maior nota da primeira prova: %s",list[index_max_first].name);
    printf("\n Aluno com a maior media geral: %s ",list[index_max].name);
    printf("\n Aluno com a menor media geral: %s ",list[index_min].name);


    free(list);
    return 1;
}



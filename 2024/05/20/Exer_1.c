#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Time
{
    int hour;
    int minutes;
    int seconds;

    int day;
    int month;
    int year;

}Time;

Time set_time(int hour,int minutes,int seconds,int day,int month,int year){

    Time new_time;

    new_time.hour = hour;
    new_time.minutes = minutes;
    new_time.seconds = seconds;

    new_time.day = day;
    new_time.month = month;
    new_time.year = year;

    return new_time;

}


typedef struct Owner{

    char name[30];
    char surname[30];
    int age;

}Owner;

Owner create_owner(char name[],char surname[],int age){

    Owner new_owner;

    strcpy(new_owner.name,name);
    strcpy(new_owner.surname,surname);
    new_owner.age = age;

    return new_owner;

}


typedef struct Vehicles{

    char brand[30];
    int year;
    char color[30];
    char plate[8];
    char model[30];
    Owner owner;

}Vehicles;

Vehicles create_vehicle(char brand[],int year,char color[],char plate[],char model[],Owner owner){

    Vehicles new_vehicle;

    strcpy(new_vehicle.brand,brand);
    new_vehicle.year = year;
    strcpy(new_vehicle.color,color);
    strcpy(new_vehicle.plate,plate);
    strcpy(new_vehicle.model,model);
    new_vehicle.owner = owner;

    return new_vehicle;

};

typedef struct Parktop{

    Vehicles * array;
    int size;
    int capacity;

}Parktop;

Parktop  construct_parktop(){

    Parktop  new_parktop;

    new_parktop.array = NULL;
    new_parktop.capacity = 0;
    new_parktop.size = 0;

    return new_parktop;

}

void add_vehicle(Parktop * parktop,Vehicles vehicle,Time time){

    if(!parktop->array){

        parktop->capacity++;
        parktop->array = malloc(parktop->capacity * sizeof(Vehicles));

    }

    if(parktop->size == parktop->capacity){

        parktop->capacity *= 2;
        realloc(parktop->array,parktop->capacity*sizeof(Vehicles));

    }

    parktop->array[parktop->size++] = vehicle;


    FILE * arq = fopen("Nota.txt","a");


    fprintf(arq,"\n\nVeiculo cadastrado no dia %i/%i/%i as %i:%i:%i:",time.day,time.month,time.year,time.hour,time.minutes,time.seconds);
    fprintf(arq,"\n Marca: %s\n Ano: %i \n cor: %s \n Placa %s \n Modelo %s\n",vehicle.brand,vehicle.year,vehicle.color,vehicle.plate,vehicle.model);
    fprintf(arq,"Nome do propietario: %s %s \n idade: %i \n \n \n",vehicle.owner.name,vehicle.owner.surname,vehicle.owner.age);

    fclose(arq);

}


void detruct_parktop(Parktop * parktop){

    free(parktop->array);

};

int main(){

    Parktop  parktop = construct_parktop();

    char brand[30],color[30],plate[30],model[30],name[30],surname[30];
    int hour,minutes,seconds,day,month,year,yearcar,breakmenu = 1;

    printf("\nEscreva a data de hj separda por espaços xx yy zzzz");
    scanf("%i %i %i",&day,&month,&year);

    printf("\nEscreva a hora atual separada por espaços xx yy zz");
    scanf("%i %i %i",&hour,&minutes,&seconds);

    Time time = set_time(hour,minutes,seconds,day,month,year);

    while (breakmenu != 0){

        printf("\nescreva 0 para sair e 1 para casdastrar veiculo");
        scanf("%i", &breakmenu);

        if( breakmenu != 0){

            printf("\nEscreva a marca:");
            scanf(" %s",brand);
            printf("\nEscreva o ano:");
            scanf("%i",&yearcar);
            printf("\nEscreva a cor:");
            scanf(" %s",color);
            printf("\nEscreva o model:");
            scanf(" %s",model);
            printf("\nEscreva o nome do proprietario:");
            scanf(" %s %s",name,surname);
            printf("\nEscreva o ano de nascimento:");
            scanf("%i",&year);

            add_vehicle(&parktop,create_vehicle(brand,yearcar,color,plate,model,create_owner(name,surname,time.year - year)),time);

        }

    }
    
    
    detruct_parktop(&parktop);



    return 1;
}


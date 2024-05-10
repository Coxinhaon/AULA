#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  Date{

    int day;
    int month;
    int year;

}Date;


typedef struct Contact{

    char name[50];
    char email[50];
    char adress[50];
    char phone[50];
    Date birth_date;
    char note[50];

}Contact;

Contact make_contact(char name[],char email[],char adress[],char phone[],int day,int month,int year,char note[]){

    Contact new_contact;

    strcpy(new_contact.name,name);

    strcpy(new_contact.email,email);

    strcpy(new_contact.adress,adress);

    strcpy(new_contact.phone,phone);

    new_contact.birth_date.day = day;
    new_contact.birth_date.month = month;
    new_contact.birth_date.year = year;

    strcpy(new_contact.note,note);

    return new_contact;
}


typedef struct Schedule {

        Contact *list;
        int capacity;
        int size;
    
}Schedule;


Schedule construct_schedule(){

    Schedule list;

    list.capacity = 0;
    list.size = 0;
    list.list = NULL;

    return list;
}

Contact get_contact(Schedule * schedule, int index){

    if ( index > schedule->size ){

        return schedule->list[0];

    }

    return schedule->list[index];
}

void add_contact(Schedule * schedule,Contact contact){
    
    if (!schedule->size){

        schedule->list = malloc(sizeof(Contact));
        schedule->capacity ++;

    }

    if(schedule->capacity == schedule->size){

        schedule->capacity *= 2;
        realloc(schedule->list, schedule->capacity * sizeof(Contact));

    }


    schedule->list[schedule->size++] = contact;
}


void add_contact_sort(Schedule * schedule, Contact contact){

    int positiontoplace = schedule->size;
    

    if (schedule->size == 0){

        schedule->list = malloc(2* sizeof(Contact));
        schedule->capacity += 2;
        schedule->list[schedule->size] = contact;
        schedule->size ++;
        
        return;
    }

    if (schedule->size == schedule->capacity){

        schedule->capacity *= 2;
        realloc(schedule->list,schedule->capacity*sizeof(Contact));

    }

    while (positiontoplace > 0 && strcmp(contact.name,schedule->list[positiontoplace - 1].name) < 0 ){

        schedule->list[positiontoplace] = schedule->list[positiontoplace - 1];
        positiontoplace --;

    }

    schedule->list[positiontoplace] = contact;
    schedule->size ++;
    
}


void remove_contact(Schedule * list,int index){

    if( list->size < index){

        return;

    }

    for(int i = index; i < list->size - 1; i ++){

        list->list[i] = list->list[ i + 1 ];

    }

    list->size --;

}

void new_contact(Schedule * schedule){

    char name[50],email[50],adress[50],phone[50],note[50];
    int day, month, year;

    printf("\nEscreva o nome: ");
    scanf(" %s",&name);

    printf("\nEscreva o Email: ");
    scanf(" %s",&email);

    printf("\nEscreva o Endereço: ");
    scanf(" %s",&adress);

    printf("\nEscreva o telefone: ");
    scanf(" %s",&phone);

    printf("\nEscreva a data de nascimento separado por espaço: ");
    scanf("%i",&day);
    scanf("%i",&month);
    scanf("%i",&year);

    printf("\nEscreva a nota: ");
    scanf(" %s",&note);


    Contact new_contact = make_contact(name,email,adress,phone,day,month,year,note);
    add_contact_sort(schedule,new_contact);

}

void view_contacts(Schedule *schedule){

    for( int i = 0; i < schedule->size; i ++){

        printf("\nNome: %s\n",schedule->list[i].name);

    }

}

void get_contact_name(Schedule * schedule){

    char name[50];
    Contact contact;

    printf("\nEscreva o nome que deseja procurar ");
    scanf(" %s",&name);

    for(int i = 0; i < schedule->size; i ++){

        if (strcmp(name,schedule->list[i].name) == 0){

            contact = get_contact(schedule,i);

            printf("Nome: %s \nEmail: %s \nEndereço: %s \nTelefone: %s \nData de nascimento %i/%i/%i \nNota: %s",contact.name,contact.email,contact.adress,contact.phone,contact.birth_date.day,contact.birth_date.month,contact.birth_date.year,contact.note);

        }
    }

}

void get_contact_month(Schedule * schedule){

    int month;
    Contact contact;

    printf("\nEscreva o mes que deseja pesquisar");
    scanf("%i",&month);


    for(int i = 0; i < schedule->size; i ++){

        if (month == schedule->list[i].birth_date.month){

            contact = get_contact(schedule,i);

            printf("Nome: %s \nEmail: %s \nEndereço: %s \nTelefone: %s \nData de nascimento %i/%i/%i \nNota: %s",contact.name,contact.email,contact.adress,contact.phone,contact.birth_date.day,contact.birth_date.month,contact.birth_date.year,contact.note);

        }
    }

}

void get_contact_day(Schedule * schedule){

    int month,day;
    Contact contact;

    printf("\nEscreva o dia que deseja pesquisar");
    scanf("%i",&day);

    printf("\nEscreva o mes que deseja pesquisar");
    scanf("%i",&month);


    for(int i = 0; i < schedule->size; i ++){

        if (month == schedule->list[i].birth_date.month && day == schedule->list[i].birth_date.day ){

            contact = get_contact(schedule,i);

            printf("Nome: %s \nEmail: %s \nEndereço: %s \nTelefone: %s \nData de nascimento %i/%i/%i \nNota: %s",contact.name,contact.email,contact.adress,contact.phone,contact.birth_date.day,contact.birth_date.month,contact.birth_date.year,contact.note);

        }
    }

}

void remove_contact_name(Schedule * schedule){

    char name[50];
    Contact contact;

    printf("\nEscreva o nome que deseja procurar ");
    scanf(" %s",&name);

    for(int i = 0; i < schedule->size; i ++){

        if (strcmp(name,schedule->list[i].name) == 0){

            contact = get_contact(schedule,i);

            schedule->size --;

            remove_contact(schedule,i);

        }
    }

}




int main(){

    Schedule schedule = construct_schedule();

    int menu = 1;

    while (menu != 0){

        printf("\nEscreva \n0 == Sair \n1 == adicionar contato \n2 == ver contatos \n3 == Pesquisar por nome \n 4 == Pesquisar por mês \n 5 == Pesquisar por dia e mês");
        scanf("%i",&menu);

        switch (menu)
        {
        case 1:

            new_contact(&schedule);

            break;

        case 2:

            view_contacts(&schedule);

            break;

        case 3:

            get_contact_name(&schedule);

            break;
        
        case 4:

            get_contact_month(&schedule);

            break;

        case 5:

            get_contact_day(&schedule);

            break;

        case 6:

            remove_contact_name(&schedule);

            break;
        
        default:
            break;
        }
    }
    

    


    free(schedule.list);

    return 1;
}

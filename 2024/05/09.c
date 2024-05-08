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

void add_contact(Schedule * schedule,Contact contact){
    
    if (!schedule->list){

        schedule->list = malloc(sizeof(contact));
        schedule->capacity ++;

    }

    if(schedule->capacity == schedule->size){

        schedule->capacity *= 2;
        realloc(schedule->list, schedule->capacity * sizeof(Contact));

    }


    schedule->list[schedule->size++] = contact;
}






void add_schedule

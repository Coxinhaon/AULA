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


// void add_contact_sort(Schedule * schedule, Contact contact){

//     int findPlace = 0, i = 0;
//     Contact current;

//     if (!schedule->size){

//         schedule->list = malloc(2* sizeof(Contact));
//         schedule->capacity += 2;
//         schedule->list[schedule->size] = contact;
//         schedule->size ++;
        
//         return;

//     }

//     if(schedule->capacity == schedule->size){

//         schedule->capacity *= 2;
//         realloc(schedule->list, schedule->capacity * sizeof(Contact));

//     }

//     while ( findPlace == 0 && i < schedule->size){

//         current = get_contact(schedule,i);
        
//         if ( strcmp( contact.name, current.name) <= 0){

//             findPlace = i;

//         }

//         i++;
        
//     }

//     if(findPlace == schedule->size - 1 ){

//         schedule->list[schedule->size++] = contact;

//         return;

//     }else{

//         for(int i = schedule->size - 1 ; i >= findPlace ; i --){

//             schedule->list[i+1] = schedule->list[i];

//         }

//         schedule->size ++;
//         schedule->list[findPlace] = contact;

//     }

// }


void add_contact_sort(Schedule *schedule, Contact contact) {

    if ( schedule->size  == 0){

        schedule->capacity = 2;
        schedule->list = malloc(schedule->capacity * sizeof(Contact));
        schedule->list[schedule->size++] = contact;
        return;

    }


    // Ensure capacity
    if (schedule->size == schedule->capacity) {

        schedule->capacity *= 2;
        schedule->list = realloc(schedule->list, schedule->capacity * sizeof(Contact));

    }

    // Find the position to insert
    int insert_index = schedule->size;

    while (insert_index > 0 && strcmp(contact.name, schedule->list[insert_index - 1].name) < 0) {

        schedule->list[insert_index] = schedule->list[insert_index - 1];
        insert_index--;

    }

    // Insert the contact
    schedule->list[insert_index] = contact;
    schedule->size++;
}


void remove_contact(Schedule * list,int index){

    if( list->size < index){

        return;

    }

}


int main(){

    Schedule list = construct_schedule();

    Contact contact;

    Contact contact1 = {"Alice", "alice@example.com", "123 Main St", "123-456-7890", {1, 1, 1990}, "Friend"};
    Contact contact2 = {"Bob", "bob@example.com", "456 Elm St", "987-654-3210", {2, 2, 1980}, "Colleague"};
    Contact contact3 = {"Charlie", "charlie@example.com", "789 Oak St", "555-123-4567", {3, 3, 1970}, "Relative"};

     
    
    for(int i = 0; i < list.size ; i ++){

        contact = get_contact(&list,i);

        printf("\nNome:  %s ",contact.name);
        

    }

    free(&list);

    return 1;
}

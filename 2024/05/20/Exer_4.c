#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Task{

    char title[50];
    char desc[50];
    char creation_data[50];
    char end_data[50];
    char status[50];

}Task;

Task  construct_task(char title[],char desc[],char creation_data[],char end_data[],char status[]){
    Task new;

    strcpy(new.title,title);
    strcpy(new.desc,desc);
    strcpy(new.creation_data,creation_data);
    strcpy(new.end_data,end_data);
    strcpy(new.status,status);

    return new;
}

typedef struct Schedule{

    Task * array;
    int capacity;
    int size;
    
}Schedule;


Schedule construct_schedule(){

    Schedule new;

    new.array = NULL;
    new.capacity = 0;
    new.size = 0;

    return new;

}


void addtask(Schedule * schedule,Task task){

    if (!schedule->array){

        schedule->capacity ++;
        schedule->array = malloc(schedule->capacity * sizeof(Task));

    }

    if(schedule->size == schedule->capacity){

        schedule->capacity *= 2;
        realloc(schedule->array,schedule->capacity * sizeof(Task));

    }

    schedule->array[schedule->size++] = task;

}

Task* gettask(Schedule * schedule,int index){

    if( index > schedule->size){

        return NULL;

    }

    return &schedule->array[index];

}

void remove_task(Schedule * schedule,int index){

    if( index > schedule->size){

        return;

    }

    for(int i = index; i<schedule; i++){

        
    }

}

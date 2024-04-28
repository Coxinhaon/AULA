#include <stdio.h>
#include <stdlib.h>


void swap_names(char **names,int index_1,int index_2){
    char *aux = names[index_1];
    names[index_1]  = names[index_2];
    names[index_2] = aux;

}

void swap(int *value_1,int *value_2){  
    int aux = *value_1;                 // 1
    *value_1 = *value_2;                // 1
    *value_2 = aux;                     // 1
}

int factorial(int number){
    if (number <= 1){                  // 1n
        return number;                 
    }
    return number*factorial(number-1); // 2n
}

void pair_to_factorial(int *array,int size){
    for(int i=0;i<size;i++){       
        if (!(array[i]&1)){
            array[i] = factorial(array[i]);
        }
    }
}

void select_sort_with_names(char **names,int *wages,int size){
    int index_minimun;
    for(int i=0;i<size-1;i++){
        index_minimun = i;
        for(int j=i+1;j<size;j++){
            if(wages[index_minimun] > wages[j]){
                index_minimun = j;
            }
        }
        swap(&wages[index_minimun],&wages[i]);
        swap_names(names,index_minimun,i);
    }
}

void select_sort_with_names_decreasing(char **names,int *wages,int size){
    int index_maximun;
    for(int i=0;i<size-1;i++){
        index_maximun = i;
        for(int j=i+1;j<size;j++){
            if(wages[index_maximun] < wages[j]){
                index_maximun = j;
            }
        }
        swap(&wages[index_maximun],&wages[i]);
        swap_names(names,index_maximun,i);
    }
}
void select_sort(int *array,int size){
    int index_minimun;                              
    for(int i=0;i<size-1;i++){                      
        index_minimun = i;                          
        for(int j=i+1;j<size;j++){                  
            if(array[index_minimun] > array[j]){   
                index_minimun = j;                   
            }
        }
        swap(&array[index_minimun],&array[i]);      
    }
}
void get_minor(int *array,int size){   
    int i=1,count = 1; 
    select_sort(array,size);
    while(array[i++] == array[0]){
        count++;
    }
    printf("%i * %i",array[0],count);
}
void get_maximun(int *array,int size){
    int i=size-1,count = 0; 
    select_sort(array,size);
    while(array[i--] == array[9]){
        count++;
    }
    printf("%i * %i",array[9],count);   
}
void exer_1(){
    int *wage=(int*)malloc(5*sizeof(int));
    char **names = (char **)malloc(5*sizeof(char*));
    for(int i=0;i<5;i++){
        names[i]=(char*)malloc(20*sizeof(char));
    }
    names[0] = "jao";     wage[0] = 2300;
    names[1] = "carlos";  wage[1] = 1900;
    names[2] = "pedro";   wage[2] = 1300;
    names[3] = "gabriel"; wage[3] = 1400;
    names[4] = "vasco";   wage[4] = 13000;

    select_sort_with_names(names,wage,5);
    for(int i=0;i<5;i++){
        printf("\n %s : %i ",names[i],wage[i]);
    }
    select_sort_with_names_decreasing(names,wage,5);
    for(int i=0;i<5;i++){
        printf("\n %s : %i ",names[i],wage[i]);
    } 
    free(wage);
    for(int i=0;i<5;i++){
        free(names[i]);
    }
    free(names);
}
void exer_2(){
    int *array = (int*)malloc(10*sizeof(int));
    array[0] = 23;
    array[1] = 30;
    array[2] = 99;
    array[3] = 99;
    array[4] = 22;
    array[5] = 22;
    array[6] = 99;
    array[7] = 99;
    array[8] = 99;
    array[9] = 99;
    get_minor(array,10);
    printf("\n");
    get_maximun(array,10);
    free(array);
}

int main(){
    exer_2();
    return 0;
}
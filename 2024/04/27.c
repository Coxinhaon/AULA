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
void select_sort(int *wages,int size){
    int index_minimun;                              
    for(int i=0;i<size-1;i++){                      
        index_minimun = i;                          
        for(int j=i+1;j<size;j++){                  
            if(wages[index_minimun] > wages[j]){   
                index_minimun = j;                   
            }
        }
        swap(&wages[index_minimun],&wages[i]);      
    }
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

int main(){

    return 0;
}
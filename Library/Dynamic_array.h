#include <stdlib.h>
#include <stdio.h>

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
    typedef struct dynamic_array{
        int size;
        int *data;
        int capacity;
    }d_array;
    //typedef d_array struct dynamic_array; /// colocar apelido na struct
    void init_d_array(d_array *v){
        if (v){
            (*v).size = 0; /// qualquer coisa tentar com (*v).size = 0 ou v-->size;
            (*v).data = NULL;
            (*v).capacity = 0;
        }
    }
    d_array * construct_d_array(){
        d_array *v = (d_array*)malloc(sizeof(d_array));
        init_d_array(v);
        return v;
    }
    void insert_d_array(d_array *v,int new_value){
        if (!v){ 
            return;
        }
        if((*v).capacity == 0){
            (*v).data = (int*)malloc(sizeof(int)*1);
            (*v).capacity = 1;
        }
        if((*v).size >= (*v).capacity){
            (*v).capacity = (*v).capacity * 2;
            (*v).data =(int*)realloc((*v).data,(*v).capacity * sizeof(int));
        }
        (*v).data[(*v).size] = new_value;
        (*v).size ++;
    }
    void destruct_d_array(d_array *v){
        if(!v){ 
            return;
        }; 
        if ((*v).data){
            free((*v).data);
        }
        free(v);
    }
    void remove_d_array(d_array *v,int remove_value){
        if(!v){
            return;
        };
        for(int i = 0;i<(*v).size;i++){
            if ( (*v).data[i] == remove_value){
                for(int j = i;j < (*v).size-1;j++){
                    (*v).data[j] = (*v).data[j+1];
                }
                (*v).size --;
            }
        }
        if ((*v).size < (*v).capacity/2){
            (*v).capacity = (*v).size;
            (*v).data =(int*) realloc((*v).data,(*v).capacity * sizeof(int));
        }
    }
    int *  get_d_array(d_array *v,int index){
        if (index < 0 || index >= (*v).size){
            printf("out of range");
            return NULL;
        }
        return &((*v).data[index]);
    }
    // void sort_d_array(d_array *v){
    //     if (v){
    //         buublesort((*v).data;(*v).size);
    //     }
    // }
    int get_index_d_array(d_array *v,int search_value){
        if(!v){
            return NULL;
        }
        for(int i = 0;i < (*v).size;i++){
            if((*v).data[i] == search_value){
                return i;
            }
        }
        return NULL;
    }
    
    int * get_size_d_array(d_array *v){
        return (*v).size;
    }


#endif

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
    
    int  get_size_d_array(d_array *v){
        return (*v).size;
    }


#endif
#ifndef LIST_H
#define LIST_H
    struct node;
    typedef struct node node;
    struct node{
        int id;
        void * data;
        node * next;
    }
    struct list;
    typedef struct list list;
    struct list{
        int size;
        node * head;
    }
    list * construct_list(){
        list * new_list = malloc(sizeof(list));
        (*new_list).size = 0;
        (*new_list).head = NULL;
        return new_list;
    }
    void destruct_list(list * l){
        if(l){
            destruct_node((*l).head);
        }
        free(l);
    }
    void insert_list(list * l,int id){
        if(!p){
            return;
        }
        if(!(*l).head){
            (*l).head = construct_node();
            return;
        }
        // node ** next = &(*l).head;
        // while(*next){
        //     *next = &(**next).next; //(*next)->next 
        // }
        // *next = construct_node(id);
        node*n = construct_node(id);
        insert_node((*p).head,n); // insert up é só colocar (*p).head = insert_node_up()
    }
    void insert_node(node * h,node * n){
        if(!(*h).next){
            (*h).next = n;
        }else{
            insert_node((*h).next,n);
        }
    }
    node * insert_node_up(node *h,node *n){
        if((*n).id<(*h).id){
            (*n).next = h;
            return n;
        }
        if(!(*h).next){
            (*h).next = n;
            return h;
        }
        (*h).next = insert_node_up((*h).next,n)
        return h;
    }
    void insert_note_point(node **h,node *n){
        if ((*n).id<(**h).id){///(*h)->id
            (*n).next = *h;
            *h = n;
            return;
        }
        if (!(**h).next){ // (*h)->next
            (*h).next = n;
            return;
        }
        insert_note_point(&(*h).next,n);
    }
    void construct_node(int id){
        node * new_node = malloc(sizeof(node));
        (*new_node).id = id;
        (*new_node).next = NULL;
        return new_node;
    }
#endif
#ifndef SORT_ARRAY_H
#define SORT_ARRAY_H
    ///Algoritmo de ordenação
void merge(int *left_array,int* right_array,int left_size,int right_size){
        int *final_array = left_array;
        int i,j,k;
        int*temporary_left_array = (int*)malloc(left_size*sizeof(int));
        int*temporary_right_array = (int*)malloc(right_size*sizeof(int));
        for(int i=0;i < left_size;i++){
            temporary_left_array[i] = left_array[i];
        }
        for(int i=0;i < right_size;i++){
            temporary_right_array[i] = right_array[i];
        }
        i=j=k=0;
        while(i < left_size && j < right_size){
            if (temporary_left_array[i]<temporary_right_array[j]){
                final_array[k++] = temporary_left_array[i++];
            }else{
                final_array[k++] = temporary_right_array[j++];
            }
        }
        while(i < left_size){
            final_array[k++] = temporary_left_array[i++];
        }
        while(j < right_size){
            final_array[k++] = temporary_right_array[j++];
        }
        free(temporary_left_array);
        free(temporary_right_array);
    }
    void mergesort(int *array,int array_size){
        if(array_size < 2) {
            return;
        }
        int left_size = array_size/2;
        int right_size = array_size/2 + (array_size%2);
        mergesort(array,left_size);
        mergesort(array+left_size,right_size);
        merge(array,array+left_size,left_size,right_size);
    }
#endif

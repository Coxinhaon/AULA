#include <stdlib.h>
#include <stdio.h>
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

int binary_to_decimal(int binary,int size){
    if (size == 1){
        return (binary&1);
    }
    return (binary&1)*(1<<size-1)+binary_to_decimal(binary/10,size-1);

}
int binary_to_decimal_v2(int binary,int size){
    if (binary <= 1){
        return binary*(1<<size);
    }
    return (binary&1) * (1<<size) + binary_to_decimal_v2(binary/10,size + 1);
    
}
int main(){
    d_array *array = construct_d_array();
    int number;
    int odd_number=0;
    int *array_number;
    while(1){
        printf("escreva o numero ou 0 para parar");
        scanf("%i",&number);
        if(number <= 0){
            break;
        }else{
            insert_d_array(array,number);
        }
    }
    for (int i=0;i<get_size_d_array(array);i++){
        array_number = get_d_array(array,i);
        printf(" %i ",*array_number);
        if(*array_number & 1 == 1){
            odd_number += *array_number;
        }
    }
    printf("\nSoma dos impares %i",odd_number);
    destruct_d_array(array);
    return 0;
}

#include "Dynamic_array.h"
void exer_1(){
    d_array *v = construct_d_array();
    insert_d_array(v,10);
    insert_d_array(v,20);
    insert_d_array(v,30);
    insert_d_array(v,40);
    insert_d_array(v,50);
    for(int i = 0;i<(*v).size;i++){
        int *value = get_d_array(v,i);
        printf(" %i ",*value);
    }
    destruct_d_array(v);
}

void exer_2(){
    int value = 23;
    int *point = &value;
    *point = 10;
}
/// exer 3
void exer_3(){
    d_array * v = construct_d_array();
    int size;
    insert_d_array(v,10);
    insert_d_array(v,20);
    insert_d_array(v,30);
    insert_d_array(v,40);
    insert_d_array(v,50);
    size = get_size_d_array(v);
    printf("%i",size);
    printf(" %i ",sum_array(v,get_size_d_array(v)));
    destruct_d_array(v);
}
int sum_array(d_array *v,int size){
    int sum = 0;
    int *value;
    for(int i = 0;i < size;i++){
        *value = get_d_array(v,i);
        sum += *value;
        printf(" %i ",sum);
    }
    return sum;
}
/// exer 4
void exer_4(){
    d_array * v = construct_d_array();
    insert_d_array(v,10);
    insert_d_array(v,20);
    insert_d_array(v,30);
    insert_d_array(v,40);
    insert_d_array(v,50);
    int *high_value = highest_value(v,get_size_d_array(v));
    printf("%i",*high_value);
    destruct_d_array(v);
}
int  highest_value(d_array *v,int size){
    int *maior = get_d_array(v,0);
    for(int i = 1;i<size;i++){
        if (get_d_array(v,i)>maior){
            *maior = get_d_array(v,i);
        }
    }
    return *maior;
}
//exer 5
void exer_5(){
    double array[4];
    array[0] = 3.14;
    array[1] = 2.71;
    array[2] = 1.618;
    array[3] = 0.577;
}
//exer 6
void exer_6(){
    d_array *v = construct_d_array();
    int *value;
    insert_d_array(v,10);
    insert_d_array(v,20);
    insert_d_array(v,30);
    insert_d_array(v,40);
    insert_d_array(v,50);
    double_array(v,5);
    printf(" %i ",get_d_array(v,0));
    for(int i = 0;i<5;i++){
        *value = get_d_array(v,i);
        printf(" %i ",*value);
    }
    destruct_d_array(v);
}
void double_array(d_array *v,int size){
    int *value;
    for(int i=0;i<size;i++){
        *value = get_d_array(v,i);
        *value = *value * 2;
    }
}
void exer_7(){
    char names[4][30]={"Alice","bob","carol","david"};
}
//exer 8
void exer_8(){
    int value = 0;
    int * v = (int*)malloc(5*sizeof(int));
    for(int i =0;i<5;i++){
        value +=10;
        v[i]=value;
    }
    printf("%i",search_number(v,5,50));
    free(v);
}
int search_number(int *v,int size,int search_number){
    for(int i=0;i<size;i++){
        if(v[i] == search_number){
            return i;
        }
    }
    return -1;
}
void exer_9(){
    int value = 0;
    int pair,odd;
    int * v = (int*)malloc(5*sizeof(int));
    for(int i =0;i<5;i++){
        value +=10;
        v[i]=value;
    }
    count_pair(v,5,&pair,&odd);
    printf("Numeros par %i e impares é %i",pair,odd);
    free(v);
}
void count_pair(int *v,int size,int *pair,int *odd){
    int pair_flag=0;
    int odd_flag =0;
    for(int i =0;i<size;i++){
        if(v[i] % 2 == 0){
            pair_flag++;
        }else{
            odd_flag ++;
        }
    }
    *pair = pair_flag;
    *odd = odd_flag;
}
void exer_11(){
    int value = 0;
    int pair,odd;
    int * v = (int*)malloc(5*sizeof(int));
    for(int i =0;i<5;i++){
        value +=10;
        v[i]=value;
    }
    invert_values(v,5);
    for(int i=0;i<5;i++){
        printf(" %i ",v[i]);        
    }
    free(v);
}
void invert_values(int *v,int size){
    int *new_v = (int*)malloc(size*sizeof(int));
    int j=0;
    for(int i=0;i<size;i++){
        new_v[i] = v[i];
    }
    for (int i = size-1;i>=0;i--){
        v[j]= new_v[i];
        j++;
    }
}
void exer_12(){
    int value = 0;
    int * v = (int*)malloc(5*sizeof(int));
    for(int i =0;i<5;i++){
        value +=1;
        v[i]=value;
    }
    v[2]=44;

    free(v);
}
void exer_13(){
    int value = 0;
    int * v = (int*)malloc(5*sizeof(int));
    for(int i =0;i<5;i++){
        value +=1;
        v[i]=value;
    }
    remove_index(&v,5,1);
    for(int i =0;i<4;i++){
        printf(" %i ",v[i]);        
    }
    free(v);
}
void remove_index(int *v,int size,int remove_index){
    for(int j = remove_index;j<size-1;j++){
        v[j]= v[j+1];
    }
    v = (int*) realloc(v,(size-1)*sizeof(int));
}
int main(){
    // //exer 1
    //exer_1();
    ////exer 2
    //exer_2();
    ///exer 3
    //exer_3();
    //exer 4
    //exer_4();
    //exer 5
    //exer_5();
    //exer 6
    //exer_6();
    //exer 7
    //exer_7();
    //exer_8();
    //exer_9();
    //exer_11();
    //exer_12();
    exer_13();

    return 0;
}

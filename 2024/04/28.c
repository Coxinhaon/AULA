#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct product{
//     int cod;
//     char description[50];
//     float price;
// }product;
// void swap_products(product * product_1,product *product){
//     int cod_aux;
//     char desc_aux[50];
//     float price_aux;

//     cod_aux = product_1->cod;
//     product_1->cod = product->cod;
//     product->cod = cod_aux;

//     strcpy(desc_aux,product_1->description);
//     strcpy(product_1->description,product->description);
//     strcpy(product->description,desc_aux);

//     price_aux = product_1->price;
//     product_1->price = product->price;
//     product->price = price_aux;
// }
// void selectsort_products(product * products,int size){
//     int minor_index;
//     for(int i=0;i<size;i++){
//         minor_index = i;
//         for(int j=i+1;j<size;j++){
//             if(products[j].cod<products[minor_index].cod){
//                 minor_index = j;
//             }
//         }
//         swap_products(&products[minor_index],&products[i]);
//     }
// }
// void exer_1(){
//     product *products = malloc(12*sizeof(product));
//     for(int i =0;i<12;i++){
//         printf("escreva o codigo ");
//         scanf("%i",&products[i].cod);
//         printf("escreva a descrição ");
//         fflush(stdin);
//         gets(products[i].description);
//         printf("escreva o preço ");
//         scanf("%f",&products[i].price); 
//     }
//     selectsort_products(products,12);
//     for(int i=0;i<12;i++){
//         printf("\n Codigo: %i Descrição: %s Preço: %.2f",products[i].cod,products[i].description,products[i].price);
//     }
//     free(products);
// }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// typedef struct product{
//     int cod;
//     float price;
//     int quant;
//     product*next;
// }product;
    // struct node;
    // typedef struct node node;
struct product;
typedef struct product product;
struct product{
    int quant;
    int cod;
    float price;
    product *next;
};

product * contruct_product(){
    product * list = malloc(sizeof(product));
    list->cod = 0;
    list->price = 0;
    list->quant = 0;
    list->next = NULL;
    return list;
}

void add_product(product *list,int cod,float price,int quant){
    if(!(list)){
        return;
    }
    if(list->price == 0){
        list->cod = cod;
        list->price = price;
        list->quant = quant;
        return;
    }
    if(!(list->next)){
        list->next = malloc(sizeof(product));
        product *next = list->next;
        next->cod = cod;
        next->price = price;
        next->quant = quant;
        next->next = NULL;
        return;
    }
    add_product(list->next,cod,price,quant);
}

void print_products(product *list){
    if(!(list)){
        return;
    }
    if(!(list->next)){
        printf("\ncodigo: %i preco: %.2f quantidade: %i",list->cod,list->price,list->quant);
        return;
    }
    printf("\ncodigo: %i preco: %.2f quantidade: %i",list->cod,list->price,list->quant);
    print_products(list->next);

}

void remove_product(product **list,int cod){
    if(!(list)){
        return;
    }
    if((*list)->cod == cod){
        product *next = (*list)->next;
        free(*list);
        *list = next;
        return;
    } 
    if(!((*list)->next)){
        return;
    }
    remove_product(&(*list)->next,cod);
}
void add_product_sort(product ** list,int cod,float price,int quant){
    if(!(list)){
        return;
    }
    if((*list)->cod == 0 && (*list)->price == 0 && (*list)->quant == 0){
        (*list)->cod = cod;
        (*list)->price = price;
        (*list)->quant = quant;
        (*list)->next = NULL;
    }
    if( (*list)->next == NULL || (cod>(*list)->cod && (cod < (*list)->next->cod))){
        product * new = malloc(sizeof(product));
        new->cod = cod;
        new->price = price;
        new->quant = quant;
        new->next = (*list)->next;
        (*list)->next = new;
        return;
    }
    add_product_sort(&(*list)->next,cod,price,quant);
}
struct students;
typedef struct students students;
struct students{
    char name[50];
    float note;
    students *next;
    students *prev;
};

void add_student(students **list,char name[],float note){
    if(!(*list)){
        *list = malloc(sizeof(students));
        strcpy((*list)->name,name);
        (*list)->note = note;
        (*list)->next = NULL;
        (*list)->prev = NULL;
        return;
    }
    if(!((*list)->next)){
        students *new = malloc(sizeof(students));
        strcpy(new->name,name);
        new->note = note;
        new->next = NULL;
        new->prev = *list;
        (*list)->next = new;
        return;
    }
    add_student(&(*list)->next,name,note);
}
void add_student_back(students **list,char name[],float note){
    if(!(*list)){
        *list = malloc(sizeof(students));
        strcpy((*list)->name,name);
        (*list)->note = note;
        (*list)->next = NULL;
        (*list)->prev = NULL;
        return;
    }else{
        students *new =  malloc(sizeof(students));
        strcpy(new->name,name);
        new->note = note;
        new->next = *list;
        new->prev = NULL;
        *list = new;
    }
}
void add_student_sort(students **list,char name[],float note){
    if(!(*list)){
        *list = malloc(sizeof(students));
        strcpy((*list)->name,name);
        (*list)->note = note;
        (*list)->next = NULL;
        (*list)->prev = NULL;
        return;
    }
    if((note>=(*list)->note  && note <= (*list)->next->note)){
        students *new = malloc(sizeof(students));
        strcpy(new->name,name);
        new->note = note;
        new->prev = *list;
        (*list)->next->prev = new;
        new->next = (*list)->next;
        (*list)->next = new;
        return;
    }
    if(note>=(*list)->note && !(*list)->next){
        students *new = malloc(sizeof(students));
        strcpy(new->name,name);
        new->note = note;
        new->next = NULL;
        new->prev = *list;
        (*list)->next = new;
        return;
    }
    if(note<=(*list)->note && !(*list)->next){
        students *new = malloc(sizeof(students));
        strcpy(new->name,name);
        new->note = note;
        new->next = *list;
        new->prev = NULL;
        (*list)->prev = new ;
        *list = new;
        return;
    }
    if(note<=(*list)->note && note<=(*list)->next->note){
        students *new = malloc(sizeof(students));
        strcpy(new->name,name);
        new->note = note;
        new->prev = NULL;
        new->next = *list;
        (*list)->prev = new;
        *list = new;
        return;
    }
    add_student_sort(&(*list)->next,name,note);
}
void remove_student(students**list,char name[]){
    if(!(*list)){
        return;
    }
    
    if(!(strcmp((*list)->name,name))){
        students *next = (*list)->next;
        free(*list);
        *list = next;
        return;
    }
    remove_student(&(*list)->next,name);
}
void print_students(students *list){
    if(!list){
        return;
    }
    printf("%s %.2f\n",list->name,list->note);
    print_students(list->next);
}

void destruct_students(students **list){
    if(!(*list)->next){
        free(*list);
        return;
    }
    destruct_students(&(*list)->next);
    free(*list);
}

int main(){
    students *list=NULL;
    char name[20] = "jao carlos";
    add_student_sort(&list,name,55);
    add_student_sort(&list,name,22);
    add_student_sort(&list,name,11);
    add_student_sort(&list,name,44);
    add_student_sort(&list,name,33);
    print_students(list);
    destruct_students(&list);
    return 0;
}

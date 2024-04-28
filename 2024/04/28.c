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

int main(){
    product *list = contruct_product();
    add_product_sort(&list,12,123,22);
    add_product_sort(&list,10,1233,10);
    add_product_sort(&list,11,1233,10);
    add_product_sort(&list,13,1233,10);

    print_products(list);

    free(list);
    return 0;
}
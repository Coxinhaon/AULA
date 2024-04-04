#include <stdlib.h>
#include <stdio.h>

void swapNum(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void higherNumber(int *a,int *b){
    if (a > b){
        printf(" valor maior é o primeiro seu endereço é %i",&a);
    } else {
        printf(" valor maior é o segundo seu endereço é %i ",&b);
    }
}
void changeVar(int *a,float *b,char *c){
    *a = *a + 1;
    *b = *b + 1;
    *c = 'C';
}

int main(){
    // ///Exer 1
    // int num1 = 1;
    // int num = 0;
    // printf (" %i  %i",num1,num);
    // swapNum(&num1,&num);
    // printf("\n  %i  %i",num1,num);
    // //Exer 2
    // int num,num1;
    // printf("Escreva um valor");
    // scanf("%i",&num);
    // printf("Escreva o 2 valor");
    // scanf("%i",&num1);
    // higherNumber(&num,&num1);
    //Exer 3
    int a = 1;
    float b = 2;
    char c = '3';
    int *pointInt = &a;
    float *pointFloat = &b;
    char *pointChar = &c;
    printf(" %i  %f  %c",a,b,c);
    changeVar(pointInt,pointFloat,pointChar);
    printf("\n %i  %f  %c",a,b,c);


    return 0;
}

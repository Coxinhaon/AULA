#include <stdio.h>
#include <stdlib.h>
void pedirValor(int *a,int *b){
    printf("escreva o 1 valor:");
    scanf("%i",&*a);
    printf("escreva o 2 valor:");
    scanf("%i",&*b);
    printf("%i %i",*a,*b);
}
int main(){
    // //Exer 1
    // FILE *arq = fopen("exer1.txt","w");
    // int num1,num2,soma,count = 0;
    // for(int i = 0;i<5;++i){
    //     srand(time(NULL));
    //     num1 = rand()%100;
    //     num2 = rand()%100;
    //     printf("\nEscreva %i + %i:",num1,num2);
    //     fprintf(arq,"%i + %i = %i \n",num1,num2,num1+num2);
    //     scanf("%i",&soma);
    //     if(soma == num1 + num2){
    //         printf("Voce acertou");
    //         ++ count;
    //     }else{
    //         printf("Voce errou");
    //     }
    // }
    // fprintf(arq,"Voce acertou: %i ",count);
    // fclose(arq);
    // //FIM exer1
    // //exer 2:
    // float celsius,farenh;
    // int menu=1;
    // while (menu != 0){
    //     printf("escreva 1 para fahren; 2 para celsius; 0 para sair");
    //     scanf("%i",&menu);
    //     switch (menu)
    //     {
    //     case 1:
    //         printf("Escreva o valor em fahrenheit\n");
    //         scanf("%f",&farenh);
    //         celsius = (farenh - 32)* 5/9;
    //         if (celsius > 50){
    //             printf("very hot\n");
    //         }else if(celsius < 0){
    //             printf("very could\n");
    //         }else{
    //             printf("normal\n");
    //         }
    //         break;
    //     case 2:
    //         printf("Escreva o valor em celsius");
    //         scanf("%f",&celsius);
    //         if (celsius > 50){
    //             printf("very hot \n");
    //         }else if(celsius < 0){
    //             printf("very could \n");
    //         }else{
    //             printf("normal \n");
    //         }
    //         break;
    //     case 0:
    //         printf("thau");
    //         break;
    //     default:
    //         printf("valor invalido\n");
    //         break;
    //     }
    // }
    // //fim 2
    //exer 3
    int menu = 1;
    int num1,num2;
    while (menu != 0)
    {
        printf("Escreva\n1 == And\n2 == OR\n3 == NOT\n4 == XOR\n0 == Sair   ");
        scanf("%i",&menu);
        switch (menu)
        {
        case 1:
            printf("escreva o 1 valor:");
            scanf("%i",&num1);
            printf("escreva o 2 valor:");
            scanf("%i",&num2);
            printf("o valor do and é: %i ",(num1&num2));
            break;
        case 2:
            printf("escreva o 1 valor:");
            scanf("%i",&num1);
            printf("escreva o 2 valor:");
            scanf("%i",&num2);
            printf("o valor do or é: %i ",(num1|num2));
            break;
        case 3:
            printf("escreva o 1 valor:");
            scanf("%i",&num1);
            printf("o valor do not é: %i ",(~num1));
            break;
        case 4:
            printf("escreva o 1 valor:");
            scanf("%i",&num1);
            printf("escreva o 2 valor:");
            scanf("%i",&num2);
            printf("o valor do xor é: %i ",(num1^num2));
            break;
        default:
            break;
        }
    }
    
    return 0;
}
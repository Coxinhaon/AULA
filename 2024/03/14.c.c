#include <stdio.h>

int main(){
    int num,num1,menu = 1;
    while (menu!=0)
    {
        printf("Escreva\n1 == AND\n2 == OR\n3 == NOT\n4 == SHIFT LEFT\n0 == Sair ");
        scanf("%i",&menu);
        switch (menu)
        {
        case 1:
            printf("Escreva 1 valor\n");
            scanf("%i",&num);
            printf("Escreva 2 valor\n");
            scanf("%i",&num1);
            printf("o AND entre valor 1 e 2 é %i\n",(num&num1));
            break;
        case 2:
            printf("Escreva 1 valor\n");
            scanf("%i",&num);
            printf("Escreva 2 valor\n");
            scanf("%i",&num1);
            printf("o OR entre valor 1 e 2 e %i\n",(num|num1));
            break;
        case 3:
            printf("Escreva 1 valor\n");
            scanf("%i",&num);
            printf("valor NOT 1 e %i\n",~num);
            break;
        case 4:
            printf("Escreva 1 valor\n");
            scanf("%i",&num);
            printf("Escreva 2 valor\n");
            scanf("%i",&num1);
            printf("valor de SHIFT LEFT de num1 é %i\n",(num>>num1));
            break;
        case 0:
            printf("Tchau!!");
            break;
        default:
            printf("valor invalido\n");
            break;
        }
    }   
    return 0;
}
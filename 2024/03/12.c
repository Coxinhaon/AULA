#include <stdio.h>

int main(){
    // //exer 4:
    // int num;
    // printf("Digite um numero");
    // scanf("%i",&num);
    // if (num%2 == 0){
    //     printf("e par");
    // }else{
    //     printf("nao e par");
    // // }
    // // //fim 4
    // char nome[50],dtaNasc[20],cpf[12];
    // printf("escreva o seu nome: ");
    // gets(nome);
    // printf("escreva a dta nascimento: ");
    // fflush(stdin);
    // gets(dtaNasc);
    // printf("escreva o cpf: ");
    // gets(cpf);
    // printf("o aluno %s nascido em %s com o cpf %s concluiu o curso de TDS",nome,dtaNasc,cpf);
    // //exer 2
    int num,num1,menu = 1;
    printf("ESCREVA O VALOR 1");
    scanf("%i",&num);
    printf("escreva o valor 2");
    scanf("%i",&num1);
    while (menu != 0){
        printf("\n Escreva \n1 == or \n2 == not \n3 == xor\n4 == and\n5 == left shift\n0 == Sair ");
        scanf("%i",&menu);
        switch (menu){
        case 1:
            printf("o valor do or é %i",(num | num1));
            break;
        case 2:
            printf("o valor do not do primeiro é %i",(~num));
            break;
        case 3:
            printf("o vlaor do xor é %i",(num^num1));
            break;
        case 4:
            printf("o valor do and é %i",(num&num1));
            break;
        case 5:
            printf("o valor do a>>b é %i",(num>>num1));
            break;
        case 0:
            printf("Tchau!!");
            break;
        default:
        printf("valor invalido");
            break;
        }  
    }
    

    return 0;
}

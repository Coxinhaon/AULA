#include <stdio.h>
#include <Windows.h>

int main(){
    // // Exer 1
    // int guess;
    // do{
    //     printf("\ndigite um numero de 1 a 100");
    //     scanf("%i",&guess);
    //     switch (guess)
    //     {
    //     case 55:
    //         printf("\nvoce acertou o valor");
    //         break;
        
    //     default:
    //         printf("\nvalor incorreto");
    //         break;
    //     }
    // }while(guess!=55);
    // return 1;
    // // fim 1
    // // Exer 2
    // int Menu;
    // float Total,Value;
    // Total = 0;
    // do{
    //     printf("\n Digite \n 1 == Deposito \n 2 == Saque \n 0 == Sair");
    //     scanf("%i",&Menu);
    //     switch (Menu)
    //     {
    //     case 1:
    //         printf("\n Digite o quanto quer depositar");
    //         scanf("%f",&Value);
    //         Total += Value;
    //         break;
    //     case 2:
    //         printf("\n Digite o quanto quer sacar");
    //         scanf("%f",&Value);
    //         if( Total > 60 ){
    //             Total -= Value;
    //         }else{
    //             printf("Valor insuficiente para realizar saque");
    //         }
    //     default:
    //         break;
    //     }
    // }while(Menu != 0);
    // // Exer 3
    // int i=0;
    // do{
    //     printf("|||");
    //     sleep(1);       
    //     i += 1;
    // }while(i<25);
    // // Exer 4
    // int Password,Guess;
    // Password = 123;
    // do{
    //     printf("Escreva a senha");
    //     scanf("%i",&Guess);
    // }while(Guess!= Password);
    // Exer 5
    // int num1,num2,num3;
    // do{
    //     printf("escreva o 1 numero");
    //     scanf("%i",&num1);
    //     printf("escreva o 2 numero");
    //     scanf("%i",&num2);
    //     printf("escreva o 3 numero");
    //     scanf("%i",&num3);
    // }while(num1+num2+num3 != 45);
    // // Exer 1
    // int num;
    // printf("escreva um numeoro");
    // scanf("%i",&num);
    // for(int i = 0; i < num; ++i){
    //     if (i % 2 == 0){
    //         printf(" %i ",i);
    //     }
    // }
    // // Exer 2
    // int Total,Num;
    // Total = 0;
    // printf("\n escreva um valor");
    // scanf("%i",&Num);
    // for(int i = 0; i < Num; ++i){
    //     Total += i;
    // };
    // printf("Valor da soma %i ",Total);
    // // Exer 3
    // int Value;
    // printf("escreva o valor");
    // scanf("%i",&Value);
    // for(int i = 1;i < 11; i++){
    //     printf(" %i ",(i*Value));
    // }
    // Exer 4
    // int Value,NumberDivision;
    // printf("escreva o valor");
    // scanf("%i",&Value);
    // NumberDivision = 0;
    // for(int i = 0;i < Value;i++){
    //      if (Value % i == 0){
    //         NumberDivision+=1;
    //      }
    // }
    // if (NumberDivision < 3){
    //     printf("Numero Primo");
    // }else{
    //     printf("numeor não primo");
    // }
    // Exer 5
    // int Num;
    // printf("escreva o valor");
    // scanf("%i",&Num);
    // for(int i = 0;i< 101;++i){
    //     if (Num % i == 0){
    //         printf(" %i ",i);
    //     }
    // }
    // // Exer 6
    // for(int i = 0; i < 20;i++){
    //     printf("\n");
    //     for (int j = 0;j < i+1;j++){
    //         printf("*");
    //     }
    // }
    // // Exer 7
    // int Value,NumDigit=0;
    // printf("escreva o valor");
    // scanf("%i",&Value);
    // do
    // {
    //     Value = Value / 10;
    //     NumDigit += 1; 
    // } while (Value != 0);
    // printf("tem %i digito",NumDigit);
    // Exer 8
    for(int i = 0;i<101;i++){
        for(int j = i;j<101;j++){
            if (i % j == 0){
                printf("%i ",i);
            }
        }
    }
    // //Exer 9
    // int mean=0,N,Value;
    // printf("escreva o numero de numeros para fazer a media");
    // scanf("%i",&N);
    // for (int i = 0;i < N;i++){
    //     printf("\nescreva o valor %i",i+1);
    //     scanf("%i",&Value);
    //     mean += Value;
    // }
    // printf("\nmedia é %i",mean/N);

}
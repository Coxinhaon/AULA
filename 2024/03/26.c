#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

char word[10] = "batatinha";
char empty[10] = "_________";

int TestGuess(char guess){
    int flagLetterFound = 0;
    for(int i = 0;i<10;i++){
        if(word[i] == guess){
            empty[i] = word[i];
            flagLetterFound = 1;
        }
    }
    if (flagLetterFound == 1){
        return 0;
    }
    return 1;
}
void GetTime(){
    time_t mytime;
    mytime = time(NULL);
    printf(ctime(&mytime));
}
void Timer(){
    int time = 0;
    int menu;
    printf(" \n Escreva 1 para Comemçar e Ctrl + c para parar \n");
    scanf("%i",&menu);
    while (menu == 1){
        printf("\n%i",time);
        sleep(1);
        time ++;
    }
    
}
void Delayer(int seconds){
    for(int i = seconds;i>=0;--i){
        printf("\n %i",i);
        sleep(1);
    }
}

int main(){
    // // Exer 1
    // char guess;
    // for(int i = 6;i>0;i){
    //     printf("\n %s \n",empty);
    //     printf("\nEscreva uma letra ");
    //     scanf(" %c",&guess);
    //     i = i - TestGuess(guess);
    //     if (strcmp(empty,word)==0){
    //         printf("\nParabens");
    //         break;
    //     }else{
    //         printf("\nVoce tem %i vidas",i);
    //     }
    // }
    // EXer 2
    int menu;
    int exitLoop = 0;
    int seconds;
    while (1)
    {
        printf("Escreva \n 1 == Hora atual \n 2 == Temporizador \n 3 == Cronometro \n 0  = Sair ");
        scanf("%i",&menu);
        switch (menu)
        {
        case 0:
            exitLoop = 1;
            break;
        case 1:
            GetTime();
            break;
        case 2:
            printf("\n Escreva o valor em segundos: ");
            scanf("%i",&seconds);
            Delayer(seconds);
            break;
        case 3:
            Timer();
            break;
        
        default:
            printf("\nValor invalido");
            break;
        }
    }
    


    

    return 0;
}
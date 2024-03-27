#include <stdio.h>
#ifndef BINARY_H
#define BINARY_H
    int And(int a,int b){
        return a&b;
    }
    int Or(int a,int b){
        return a|b;
    }
    int Not(int a){
        return ~a;
    }
    int Xor(int a,int b){
        return a^b;
    }
    int ShiftRight(int a,int b){
        return a>>b;
    }
    int ShiftLeft(int a,int b){
        return a<<b;
    }
    int Nand(int a,int b){
        return ~(a&b);
    }
    int Nor(int a,int b){
        return ~(a|b);
    }
    int Nxor(int a,int b){
        return ~(a^b);
    }

#endif
#ifndef BANCO_H
#define BANCO_H
    float Deposit(float accountBalance,float depositValue){
        FILE *arq = fopen("extrato.txt","a");
        fprintf(arq,"Voce fez um deposito,seu saldo antigo é %.2f e depositou %.2f seu saldo atual é %.2f \n",accountBalance,depositValue,accountBalance + depositValue);
        fclose(arq);
        return accountBalance + depositValue;
    }
    float Withdraw(float accountBalance,float withdrawValue){
        if(withdrawValue > accountBalance){
            return accountBalance;
        }
        FILE *arq = fopen("extrato.txt","a");
        fprintf(arq,"Voce fez um saque,seu saldo antigo é %.2f e sacou %.2f seu saldo atual é %.2f \n",accountBalance,withdrawValue,accountBalance - withdrawValue);
        fclose(arq);
        return accountBalance - withdrawValue;
    }
    float Lending(float accountBalance,float loanValue){
        FILE *arq = fopen("extrato.txt","a");
        fprintf(arq,"Voce fez um emprestimo,seu saldo antigo é %.2f e pediu  %.2f seu saldo atual é %.2f e sua divida é %.2f \n",accountBalance,loanValue,accountBalance + loanValue,loanValue);
        fclose(arq);
        return accountBalance + loanValue;
    }
    void extract(){
        char line[100];
        FILE *arq = fopen("extrato.txt","r");
        while (fgets(line,sizeof(line),arq) != NULL){
            printf("%s",line);
        }
        fclose(arq);
    }

#endif

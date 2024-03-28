int table(int i,int value){
    if (i>10){
        return i;
    }
    printf("%i\n",value*i);

    table(i+1,value);
}
int ConvertToBinary(int a){
    if (a == 1 ){
        printf("1");
        return 0;
    }
    ConvertToBinary(a/2);
    printf("%i",a & 1);

}
int SumNum(int number){
    if(number == 1){
        return 1;
    } 
    return number + SumNum(number-1);
}
int ConvertToDecimal(int bin,int valor,int soma){
    if (bin == 0){
        return soma;
    }
    soma = soma + (bin % 2)*valor;
    ConvertToDecimal(bin/10,valor*2,soma);
    return soma;
}

int main(){
    // //Exer 1
    //table(0,2);
    //exer 2
    //ConvertToBinary(20);
    //exer 3
    //printf("\n%i",SumNum(10));
    printf("%i",ConvertToDecimal(1010,1,0));
    return 0;
}
#include <stdlib.h>
#include <stdio.h>

int main(){
    // //exer 1
    // float tri1,tri2,tri3,media;
    // printf("Valor do primeiro trimestre");
    // scanf("%f",&tri1);
    // printf("Valor do segundo trimestre");
    // scanf("%f",&tri2);
    // printf("Valor do terceiro trimestre");
    // scanf("%f",&tri3);
    // media = ((tri1 * 2) + (tri2 * 3) + (tri3 * 5))/10;
    // printf("A media é %.0f ",media);
    //EXER 2
    float celcisus,kelvin,fahre;
    printf("escreva o valor em celsius");
    scanf("%f",&celcisus);
    fahre = (celcisus *9 /5) + 32;
    printf("valor em fahre %.0f \n",fahre);
    kelvin = celcisus + 273.15;
    printf("o valor em kelvin %.2f",kelvin);

    return 0;
};

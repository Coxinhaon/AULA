#include <stdlib.h>
#include <stdio.h>

int ** create_matrix(int size_line,int size_collum){
    int value =0;
    int **v=(int*)malloc(5*sizeof(int*));
    for (int i=0;i<5;++i){
        v[i]=(int)malloc(5*sizeof(int));
        for (int j = 0;j<5;++j){
            value +=2;
            v[i][j]=value;
        }
    }
    return v;
}
void print_matrix(int ** v,int size_line,int size_collum){
    for(int i = 0;i<size_line;++i){
        for (int j = 0;j<size_collum;++j){
            printf( "%i ",v[i][j]);
        }
        printf("\n");
    }
}
void free_array(int **v,int size_line,int size_collum){
    for (int i=0;i<size_line;++i){
        free(v[i]);
    }
    free(v);
}



void exer_0(){
    int **array = create_matrix(2,2);
    print_matrix(array,4,4);
    free_array(array,4,4);
}
void exer_1(){
    int **array = create_matrix(4,4);
    int total_value = 0;
    for(int i=0;i<4;i++){
        for(int j = 0;j<4;j++){
            total_value += array[i][j];
        }
    }
    printf("valor total %i ",total_value);
    free_array(array,4,4);
}
void exer_2(){
    int total_value=0;
    int **array = create_matrix(4,4);
    for(int i=0;i<4;i++){
        for(int j = 0;j<4;j++){
            total_value += sizeof(array[i][j]);
        }
    }
    printf("Valor total  de espaço  %i ",total_value);
    free_array(array,4,4);
}
void exer_3(){
    int mean;
    int **array = create_matrix(3,3);
    for(int i=0;i<3;i++){
        mean = (array[i][0]+array[i][1]+array[i][2])/3;
        printf("valor da media da linha %i:%i",i+1,mean);
    }
    free_array(array,3,3);
}
void exer_4(){
    int **array_1 = create_matrix(3,2);
    int **array_2 = create_matrix(3,2);
    int **array_result = create_matrix(3,2);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            array_result[i][j] = array_1[i][j] + array_2[i][j];
        }
    }
    print_matrix(array_1,3,2);
    print_matrix(array_2,3,2);
    print_matrix(array_result,3,2);
    free_array(array_1,3,2);
    free_array(array_2,3,2);
    free_array(array_result,3,2);
}
void exer_5(){
    int **answer = create_matrix(4,4);
    int **response = create_matrix(4,4);
    int answer_line;
    for(int i=0;i<4;++i){
        for (int j = 0;j<4;j++){
            answer[i][j] = 0;
            response[i][j] = 0;
        }
    }
    response[0][1] = 1;
    response[1][2] = 1;
    response[2][3] = 1;
    response[3][0] = 1;
    for(int i=0;i<4;i++){
        printf("\n Pergunta %i \n",i + 1);
        for(int j = 0;j<4;j++){
            printf(" %i ",answer[i][j]);
        }
        printf("\nescreva 1 a 4 para escolher a resposta: ");
        scanf("%i",&answer_line);
        answer[i][answer_line-1] = 1;
    }
    printf("\nsuas resposta\n");
    print_matrix(answer,4,4);
    printf("\nresposta\n");
    print_matrix(response,4,4);
    answer_line = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(answer[i][j]&response[i][j]){
                answer_line ++;
            }
        }
    }
    printf("vc acertou %i questoes",answer_line);
    free_array(answer,4,4);
    free_array(response,4,4);
}


int main(){
    exer_5();
    return 0;
}
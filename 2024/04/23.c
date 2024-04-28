#include <stdio.h>
#include <stdlib.h>

int * create_array(int size){
    int * array = (int*)malloc(size * sizeof(int));
    return array;
}
void print_array(int *array,int size){
    for(int i=0;i<size;i++){
        printf(" %i ",array[i]);
    }
}
int ** create_matrix(int size_line,int size_collum){
    int value =0;
    int **v=(int**)malloc(size_line*sizeof(int*));
    for (int i=0;i<size_line;++i){
        v[i]=(int)malloc(size_collum*sizeof(int));
        for (int j = 0;j<size_collum;++j){
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
void free_matrix(int **v,int size_line,int size_collum){
    for (int i=0;i<size_line;++i){
        free(v[i]);
    }
    free(v);
}



void exer_1(){
    int size;
    int *array;
    printf("Escreva o valor do tamanho do array");
    scanf("%i",&size);
    array = create_array(size);
    for(int i=0;i<size;i++){
        printf("Escreva o valor do %i numero",i+1);
        scanf("%i",&array[i]);
    }
    print_array(array,size);
    free(array);
}
void exer_2(){
    char* line = (char*)malloc(100*sizeof(char));
    printf("escreva a palvara pra colocar no txt");
    fflush(stdin);
    gets(line);
    FILE* arq = fopen("palavra.txt","w");
    fprintf(arq,line);
    fclose(arq);
    FILE * arq = fopen("palavra.tx","r");

    free(line);
}

void exer_3(){
    char * line = (char*)malloc(50 * sizeof(char));
    printf("escreva uma frase asd ");
    scanf(" %s",line);
    printf("%s",line);
    free(line);
}
void exer_4(){
    int line,collum;
    int **matrix;
    printf("escreva o numero de linhas");
    scanf("%i",&line);
    printf("\n Escreva o valor de colunas");
    scanf("%i",&collum);
    matrix = create_matrix(line,collum);
    print_matrix(matrix,line,collum);
    free_matrix(matrix,line,collum);
}
void exer_5(){
    int **matrix_1 = create_matrix(5,5);
    int **matrix_2 = create_matrix(5,5);
    int **result_matrix = create_matrix(5,5);
    for (int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            result_matrix[i][j] = matrix_1[i][j] + matrix_2[i][j];
        }
    }
    printf("\nmatriz 1:\n");
    print_matrix(matrix_1,5,5);
    printf("\nmatriz 2:\n");
    print_matrix(matrix_2,5,5);
    printf("\nmatriz resultado:\n");
    print_matrix(result_matrix,5,5);

    free_matrix(matrix_1,5,5);
    free_matrix(matrix_2,5,5);
    free_matrix(result_matrix,5,5);
}
int main(){
    //exer_3();
    exer_5();
    return 0;
}
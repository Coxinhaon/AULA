#include <stdlib.h>
#include <stdio.h>

int * create_array(int size){
    int * array = (int*)malloc(size * sizeof(int));
    for(int i=0;i<size;i++){
        array[i] = i +1;
    }
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


int compare_words(char * word_1,char * word_2){
    int i = 0;
    while (*(word_1+i)!='\0' || *(word_2+i) != '\0'){
        if(*(word_1+i) != *(word_2+i)){
            return 0;
        }
        i++;
    }
    return 1;
}
void exer_2(){
    int **matrix = create_matrix(4,4);
    int *array = NULL;
    int size = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(!array){
                array = malloc(sizeof(int));
                array[0] = matrix[0][0];
                size ++;
            }else{
                size ++;
                realloc(array,size*sizeof(int));
                array[size-1] = matrix[i][j];
            }
        }
    }
    print_matrix(matrix,4,4);
    print_array(array,size);
    free_matrix(matrix,4,4);
    free(array);
}
void double_value(int * number){
    *number *=2;
}
void exer_3(){
    int number = 2;
    double_value(&number);
    printf("%i",number);
}
void exer_4(){
    int *array = create_array(5);
    print_array(array,5);
}
void exer_5(){
    char ***words = (char ***) malloc(3*sizeof(char**));
    for(int i=0;i<3;i++){
        words[i] = (char **) malloc (3*sizeof(char*));
        for (int j = 0;j<3;j++){
            words[i][j] = malloc(50*sizeof(char));
        }
    }
    printf("\n primeira linha de palavra \n");
    for(int i = 0;i<3;i++){
        printf(" escreva a palavra pika ");
        fflush(stdin);
        gets(words[0][i]);
    }
    printf("\n segunda linha de palavra \n");
    for(int i = 0;i<3;i++){
        printf(" escreva a palavra pika ");
        fflush(stdin);
        gets(words[1][i]);
    }
    for(int j=0;j<3;j++){
        if(compare_words(words[0][j],words[1][j])==1){
            words[2][j] = "Igual";
        }else{
            words[2][j] = "Diferente";
        }
    }
    for(int i=0;i<3;i++){
        printf(" %s ",words[2][i]);
    }
    for(int i=0;i<3;i++){
        for (int j = 0;j<3;j++){
            free(words[i][j]);
        }
        free(words[i]);
    }
    free(words);
}
int main(){
    //exer_2();
    //exer_3();
    //exer_4();
    exer_5();
    return 0;
}
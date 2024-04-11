#include "Dynamic_array.h"

void print_matrix(int ** v,int size_line,int size_collum){
    for(int i = 0;i<size_line;++i){
        for (int j = 0;j<size_collum;++j){
            printf( "%i ",v[i][j]);
        }
        printf("\n");
    }
}
int ** create_matrix(int size_line,int size_collum){
    int value =0;
    int **v=(int*)malloc(5*sizeof(int*));
    for (int i=0;i<5;++i){
        v[i]=(int)malloc(5*sizeof(int));
        for (int j = 0;j<5;++j){
            value = 0;
            v[i][j]=value;
        }
    }
    return v;
}
void exer_1(){
    int subjects,notes;
    printf("Escreva o numeros de materias\n");
    scanf("%i",&subjects);
    printf("Escreva o numero de notas\n");
    scanf("%i",&notes);
    int **v = create_matrix(subjects,notes);
    for(int i=0;i<subjects;++i){
        printf("Notas da %i materias\n",i+1);
        for(int j=0;j<notes;++j){
            printf("Escreva o valor da nota %i:\n",j+1);
            scanf("%i",&v[i][j]);
        }
    }
    print_matrix(v,subjects,notes);
    free(v);
}

int main(){
    //exer_1();
    int collum,line;
    int **v = create_matrix(4,4);
    v[0][0] = 0;
    v[1][0] = 1;
    v[2][0] = 2;
    v[3][0] = 3;
    v[0][1] = 1;
    v[0][2] = 2;
    v[0][3] = 3;
    printf("digite 4 para sair\n");
    while (line != 4 && collum != 4){
        print_matrix(v,4,4);
        printf("escreva a linha que deseja jogar");
        scanf("%i",&line);
        printf("escreva a coluna que deseja jogar");
        scanf("%i",&collum);
        v[line][collum] = 1;
        print_matrix(v,4,4);
        printf("escreva a linha que deseja jogar");
        scanf("%i",&line);
        printf("escreva a coluna que deseja jogar");
        scanf("%i",&collum);
        v[line][collum] = 2;
    }
    free(v);
    return 1;
}
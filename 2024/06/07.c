#include <stdlib.h>
#include <stdio.h>

typedef struct dynamic_array
{
    int * array;
    int size;
    int capacity;
}dynamic_array;

dynamic_array * constuctor_array()
{
    dynamic_array * array = malloc(sizeof(dynamic_array));
    array->array = NULL;
    array->size = 0;
    array->capacity = 0;

    return array;
}

void add_array(dynamic_array * array,int value)
{
    if(!array) return;
    if(!array->array)
    {
        array->capacity = 2;
        array->array = malloc(array->capacity*sizeof(int));
    }
    if(array->size == array->capacity)
    {
        array->capacity *=2;
        array->array = realloc(array->array,array->capacity*sizeof(int));
    }
    array->array[array->size++] = value;
}

void destruct_array(dynamic_array * array)
{
    free(array->array);
    free(array);
}

void merge(int *left_array,int * right_array,int left_size,int right_size)
{
    int i,j,k;
    int * temporary_left = malloc(left_size*sizeof(int));
    int * temporary_right = malloc(right_size*sizeof(int));

    for(int i=0;i < left_size;i++)
    {
            temporary_left[i] = left_array[i];
    }
    for(int i=0;i < right_size;i++)
    {
            temporary_right[i] = right_array[i];
    }

    i=j=k=0;

    while (i<left_size && j<right_size)
    {
        if(temporary_left[i]<temporary_right[i])
        {
            left_array[k++] = temporary_left[i++];
        }
        else
        {
            left_array[k++] = temporary_right[j++];
        }
    }
    while (i<left_size)
    {
        left_array[k++] = temporary_left[i++];
    }
    while (j<right_size)
    {
        left_array[k++] = temporary_right[j++];
    }
    free(temporary_left);
    free(temporary_right);
}
void mergesort(int * array,int size)
{
    if(size<2) return;
    int left_size = size/2;
    int right_size = size/2 + (size&1);
    mergesort(array,left_size);
    mergesort(array+left_size,right_size);
    merge(array,array+left_size,left_size,right_size);
}

void swap(int * value1,int *value2)
{
    int temp  = *value1;
    *value1 = *value2;
    *value2 = temp;
}

void selectsort(int *array,int size)
{
    int minor_index;
    for(int i =0;i<size-1;i++)
    {
        minor_index = i;
        for(int j = i+1;j<size;j++)
        {
            if(array[minor_index]>array[j])
            {
                minor_index = j;
            }
        }
        swap(&array[i],&array[minor_index]);
    }
}

void insertionSort(int *array,int size)
{
    int i,current,j;
    for(i=1;i<size;i++)
    {
        current = array[i];
        j = i - 1;
        while (j >= 0 && array[j]>current)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = current;
    }
}


int main()
{
    dynamic_array * array = constuctor_array();
    int menu = 1;
    while(menu != 0)
    {
        printf("escreva o numero que vc quer adicionar e 0 para acabar");
        scanf("%i",&menu);
        if(menu != 0) add_array(array,menu);
    }
    printf("quer usar qual algoritmo de ordenação?\n 1 == mergesort\n 2 == selectsort\n 3 == insertsort");
    scanf("%i",&menu);
    switch (menu)
    {
    case 1:
        mergesort(array->array,array->size);
        break;
    case 2:
        selectsort(array->array,array->size);
        break;
    case 3:
        insertionSort(array->array,array->size);
        break;
    default:
        printf("valor invalido");
        break;
    }
    for(int i=0;i<array->size;i++)
    {
        printf("%i ",array->array[i]);
    }

    destruct_array(array);
    return 1;
}

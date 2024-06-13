#include <stdio.h>
#include <stdlib.h>

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


void swap(int * v, int i, int j)
{
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void _quick_sort(int * v, int begin, int end)
{
	if(end <= begin)
	{
		return;
	}
	
	int i = begin;
	int j = end;
	
	while(i != j)
	{
		while(j > i && v[j] >= v[i])
		{
			j--;
		}
		swap(v, i, j);
		
		while(i < j && v[i] <= v[j])
		{
			i++;
		}
		swap(v, i, j);
	}
	
	_quick_sort(v, begin, i - 1);
	_quick_sort(v, i + 1, end);
}
void quick_sort(int * v, int size)
{
	if(size > 0)
	{
		_quick_sort(v, 0, size - 1);
	}
}

int main()
{
    dynamic_array * array = constuctor_array();

    add_array(array,3);
    add_array(array,2);
    add_array(array,4);
    add_array(array,5);


    quick_sort(array->array,array->size);

    for(int i=0;i<array->size;i++)
    {
        printf("%i ",array->array[i]);
    }

    destruct_array(array);
    return 1;
}
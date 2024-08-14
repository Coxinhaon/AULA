#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
    int x;
    int y;
    int data;
    Node * next;
    Node * down;
};

Node * construct_node(int data,int x,int y)
{
    Node * new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->down = new_node;
    new_node->next = new_node;
    new_node->x = x;
    new_node->y = y;
    return new_node;
}

typedef struct Sparse_Matrix
{
    Node * node;
    int size_x;
    int size_y;
}Sparse_Matrix;

Sparse_Matrix * construct_sparse(){
    Sparse_Matrix *new = (Sparse_Matrix*)malloc(sizeof(Sparse_Matrix));
    Node *node = construct_node(-1,-1,-1);
    new->node = node;
    new->size_x = 0;
    new->size_y = 0;
    return new;
}

void set_bigger(Sparse_Matrix * matrix,int x,int y)
{
    if(matrix->size_x < x) matrix->size_x = x;
    if(matrix->size_y < y) matrix->size_y = y;
}

void add_matrix_sparse(Sparse_Matrix * matrix,int data,int x,int y)
{
    set_bigger(matrix,x,y);
    Node * current = matrix->node;
    Node * first_node = current;
    Node * new_value = construct_node(data,x,y);
    for(int i=0;i<x;i++){
        if (current->next == first_node)
        {
            Node * new_node = construct_node(-1,-1,-1);
            current->next = new_node;
            new_node->next = first_node;
            printf("make a X\n");
        }
        current = current->next;
    };
    first_node = current;
    while (current->down->y<y && current->down != first_node);
    {
        current = current->down;
    }
    new_value->down = current->down;
    current->down = new_value;
    printf("current x = %i y = %i down \n",current->down->x,current->down->y);

    first_node = matrix->node;
    current = matrix->node;
    for(int i=0;i<y;i++)
    {
        if (current->down == first_node)
        {
            Node * new_node = construct_node(-1,-1,-1);
            current->down = new_node;
            new_node->down = first_node;
            printf("Make a Y\n");
        }
        current = current->down;
    };
    first_node = current;
    while (current->next->x<x && current->next != first_node)
    {
        current = current->next;
    }
    new_value->next = current->next;
    current->next = new_value;
    printf("current x = %i y = %i next\n",current->next->x,current->next->y);
}

int get_matrix(Sparse_Matrix * matrix,int x,int y)
{
    Node * current = matrix->node;
    if(x<y)
    {
        while (current && x>0)
        {
            current = current->next;
            if(current==matrix->node)return 0;            
        }
        Node * first = current;
        do
        {
            if(current->y == y)return current->data;
            current = current->down;
        }
        while (current->y<=y && current != first);
        return 0;
    }
    while (current && y>0)
    {
        current = current->down;
        if(current==matrix->node)return 0;            
    }
    Node * first = current;
    do
    {
        current = current->next;
        if(current->x == x)return current->data;
    }
    while (current->x<=x && current != first);
    return 0;
}

void destruct_down(Node * current)
{
    while (current)
    {
        Node * temp = current->down;
        free(current);
        current = temp;
    }; 
}

void destruct_sparce(Sparse_Matrix * matrix)
{
    Node * current = matrix->node;
    while (current)
    {
        Node * temp = current->next;
        destruct_down(current);
        current = temp;
    }
}

int main()
{
    Sparse_Matrix * matrix = construct_sparse();
    add_matrix_sparse(matrix,1,1,1);
    add_matrix_sparse(matrix,1,1,2);
    add_matrix_sparse(matrix,1,1,3);
    printf("\n");
    add_matrix_sparse(matrix,1,2,2);
    printf("\n");
    add_matrix_sparse(matrix,1,3,3);
    printf("x:%i Y:%i\n",matrix->size_x,matrix->size_y);
    for (int i=1;i<=matrix->size_y;i++)
    {
        for(int j=1;j<=matrix->size_x;j++)
        {
            printf("%i ",get_matrix(matrix,j,i));
        }
        printf("\n");
    }

    Node * current = matrix->node->next->down;

    while (current != matrix->node->next)
    {
        printf("%i ",current->data);
        current = current->next;
    }
    
    
    //destruct_sparce(matrix);
}


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
    int size;
    Node * node;
    int size_x;
    int size_y;
}Sparse_Matrix;

Sparse_Matrix * construct_sparse(){
    Sparse_Matrix *new = (Sparse_Matrix*)malloc(sizeof(Sparse_Matrix));
    new->size = 0;
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
    Node * current = matrix->node;
    Node * first_node = current;
    Node * new_value = construct_node(data,x,y);
    do
    {
        if (current->next == first_node)
        {
            Node * new_node = construct_node(-1,-1,-1);
            current->next = new_node;
            new_node->next = first_node;
        }
        current = current->next;
        x--;
    }
    while (x>0);
    first_node = current;
    do
    {
        current = current->next;
    }
    while (current->down->y<y && current != first_node);
    new_value->down = current->down;
    current->down = new_value;

    first_node = matrix->node;
    current = first_node;
    do
    {
        if (current->down == first_node)
        {
            Node * new_node = construct_node(-1,-1,-1);
            current->down = new_node;
            new_node->down = first_node;
        }
        current = current->down;
        y--;
    }
    while (y>0);
    first_node = current;
    do
    {
        current = current->next;
    }
    while (current->next->x<x && current != first_node);
    new_value->next = current->next;
    current->next = new_value;
    set_bigger(matrix,x,y);
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
        current = current->down;
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
    printf("x:%i Y:%i\n",matrix->size_x,matrix->size_y);
    destruct_sparce(matrix);
}


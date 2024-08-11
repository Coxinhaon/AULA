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
}Sparse_Matrix;

Sparse_Matrix * construct_sparse(){
    Sparse_Matrix *new = (Sparse_Matrix*)malloc(sizeof(Sparse_Matrix));
    new->size = 0;
    Node *node = construct_node(-1,-1,-1);
    new->node = node;
    return new;
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
}



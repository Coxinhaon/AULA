#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;

struct Node{
    
    Node * prev;
    int data;

};

Node * create_node(int data){

    Node * new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;

    return new_node;

};

typedef struct Stack{

    Node * top;
    int size;

}Stack;

Stack construct_stack(){

    Stack new_stack;

    new_stack.top = NULL;
    new_stack.size = 0;

    return new_stack;

};

void push(Stack * stack,int data){

    Node * new_node = create_node(data);

    new_node->prev = stack->top;
    stack->top = new_node;

    stack->size ++;

};

int pop(Stack * stack){

    Node * current = stack->top;

    stack->size --;

    int aux = current->data;

    stack->top = current->prev;
    free(current);

    return aux;

}

int peek(Stack * stack){

    return stack->top->data;

}

int getsize(Stack * stack){

    return stack->size;

}

void destruct(Stack * stack){

    destruct_node(stack->top);

}

void destruct_node(Node * current){

    if ( ! current )
        return;

    destruct_node(current->prev);
    free(current);

}


int main(){

    Stack stack = construct_stack();

    push(&stack,3);
    push(&stack,2);
    push(&stack,1);
    push(&stack,4);
    push(&stack,5);

    printf(" \n %i ",pop(&stack));
    printf(" \n %i ",peek(&stack));
    printf(" \n %i ",getsize(&stack));


    

    return 1;
}
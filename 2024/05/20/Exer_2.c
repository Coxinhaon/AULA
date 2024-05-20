#include <stdio.h>
#include <stdlib.h>


typedef struct Node Node;

struct Node
{
    Node * prev;
    int data;

};

Node *  construct_node(int data){
    Node * new = malloc(sizeof(Node));

    new->prev = NULL;
    new->data = data;

    return new;

}

typedef struct Stack{

    Node * head;
    int size;

}Stack;

Stack  construct_stack(){

    Stack new;

    new.head = NULL;
    new.size = 0;

    return new;
}



void push(Stack * stack,int value){

    Node *new = construct_node(value);

    new->prev = stack->head;

    stack->head = new;

    stack->size++;

};

int pop(Stack * stack){

    if ( stack->size > 0){

        Node * aux = stack->head;
        int auxdata = aux->data;
        stack->head = aux->prev;
        free(aux);
        stack->size--;

        return auxdata;

    }else{
        printf("ERROR NADA PRA REMOVER");
        return 0;
    }

}

int peek(Stack * stack){

    if( stack->size > 0){

        return stack->head->data;

    }else{

        printf("ERROR NADA PRA REMOVER");
        return 0;

    }

}

void destruct_stack(Stack * stack){

    destruct_node(stack->head);

}

void destruct_node(Node * current){

    if(current){

        return;
    }

    destruct_node(current->prev);
    free(current);


}



int main(){

    Stack  stack = construct_stack();

    push(&stack,1);
    push(&stack,2);
    push(&stack,3);
    push(&stack,4);

    printf("\n%i",pop(&stack));
    printf("\n%i",pop(&stack));

    destruct_stack(&stack);

    return 1;
}
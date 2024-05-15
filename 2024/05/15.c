#include <stdio.h>
#include <stdlib.h>



typedef struct  Node Node;
    
struct  Node{
    
    Node *prev;
    int data;

};

Node * create_node(int data,Node * prev){

    Node *new_node = malloc(sizeof(Node));

    new_node->data = data;
    new_node->prev = prev;

    return new_node;

}


typedef struct Queue{

    Node * top;
    Node * tail;    
    int size;

}Queue;

Queue  construct_queue(){

    Queue new_Queue;

    new_Queue.size = 0;
    new_Queue.tail = NULL;
    new_Queue.top = NULL;

    return new_Queue;

};

void enqueue(Queue * queue,int data){
    
    Node * new_node = create_node(data,NULL);

    if( !queue->top ){

        queue->top = new_node;
        queue->tail = new_node;

        queue->size ++;

        return;

    }

    queue->tail->prev = new_node;
    queue->tail = new_node;

    queue->size ++;

}

int dequeue(Queue * queue){

    int aux = queue->top->data;

    Node * node = queue->top;

    queue->top = node->prev;
    
    free(node);

    return aux;

}

int peek(Queue * queue){

    return queue->top->data;

}




int main(){

    Queue queue = construct_queue();


    enqueue(&queue,40);
    enqueue(&queue,10);
    enqueue(&queue,50);
    enqueue(&queue,30);
    enqueue(&queue,20);
    enqueue(&queue,10);

    printf(" %i ",dequeue(&queue));
    printf(" %i ",dequeue(&queue));
    printf(" %i ",dequeue(&queue));
    printf(" %i ",dequeue(&queue));
    printf(" %i ",dequeue(&queue));
    printf(" %i ",dequeue(&queue));
    printf(" %i ",dequeue(&queue));



    return 1;
}

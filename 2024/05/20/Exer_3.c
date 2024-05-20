#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    Node *next;
    Node *prev;
    int data;

};

Node * contruct_node(int data){

    Node * new = malloc(sizeof(Node));

    new->data = data;

    return new;

}

typedef struct Queue
{
    Node *head;
    Node *tail;
    int size;

}Queue;

Queue contruct_queue(){

    Queue new;

    new.head = NULL;
    new.tail = NULL;
    new.size = 0;

    return new;

}

void enqueue(Queue *queue,int data){

    Node* new = contruct_node(data);

    if(!queue->head){

        queue->head = new;
        queue->tail = new;
        queue->size ++;
        return;

    }

    new->prev = queue->tail;
    queue->tail->next = new;
    queue->tail = new;
    queue->size++;

}

int dequeue(Queue * queue){

    int aux = queue->head->data;
    queue->head = queue->head->next;
    free(queue->head->prev);
    return aux;

}

void destruct_queue(Queue * queue){

    destruct_node(queue->head);

}

void destruct_node(Node * current){

    if (!current){
        return;
    }

    destruct_node(current->next);
    free(current);
}


int main(){
    Queue queue = contruct_queue();

    enqueue(&queue,1);
    enqueue(&queue,2);
    enqueue(&queue,3);
    enqueue(&queue,4);
    enqueue(&queue,5);
    enqueue(&queue,6);

    printf("\n%i",dequeue(&queue));
    printf("\n%i",dequeue(&queue));
    printf("\n%i",dequeue(&queue));
    printf("\n%i",dequeue(&queue));

    destruct_queue(&queue);


    return 1;
}


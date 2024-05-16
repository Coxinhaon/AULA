#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    queue->size --;

    return aux;

}

int peek(Queue * queue){

    return queue->top->data;

}

void destruct(Queue * queue){

    destruct_node(queue->top);

}


void destruct_node(Node *  current){

    if ( !current )
        return;


    destruct(current->prev);
    free(current);

}

int main(){

    srand(time(NULL));

    Queue queue = construct_queue();
    enqueue(&queue,0);

    int time = 8;
    int people_quit,people_buy,people_entry;

    while ( queue.size != 0 ){

        time = (time + 1) % 24;

        people_entry = people_buy = people_quit = 0;

        printf("\n Hora: %i \n",time);

        printf("\n Numeros de pessoas na fila %i \n",queue.size);

        if( time > 8 && time < 17){

            for (int i = 0; i < rand()%50; i ++){

                if ( rand()%100 < 80){

                    enqueue(&queue,i);

                    people_entry ++;

                }

            }

            printf("\n Numero de pessoas que entraram: %i ",people_entry);

        }

        if( time > 17 && time < 22){

            for (int i = 0; i < rand()%100; i ++){

                if ( rand()%100 < 80){

                    enqueue(&queue,i);

                    people_entry ++;

                }

            }

            printf("\n Numero de pessoas que entraram: %i ",people_entry);

        }

        for (int i = 0; i < rand()%10; i ++ ){

            if ( rand()%100 < 20){

                dequeue(&queue);

                people_quit++;
            }
                
        }

        printf("\n Pessoas que sairam: %i ",people_quit);
        
        for (int i = 0; i < rand()%30; i ++){

            if ( rand()%100 < 80){

                dequeue(&queue);

                people_buy ++;

            }

        }

        printf("\n Pessoas que compraram: %i ",people_buy);
        


    }
    




    return 1;
}
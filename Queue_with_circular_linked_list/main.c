/*
Date: 2020/02/08
Author: Ian
Object: To implement queue with circular linked list in C.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{ // define node structure
    int data;
    struct node *link;
}node;

typedef struct queue{ // define queue structure
    node *rear;
}queue;

void init_queue(queue *);
int isEmpty(queue *);
void enqueue(queue *, int);
int dequeue(queue *);

void init_queue(queue *q){ //assign NULL to rear
    q->rear = NULL;
    return;
}

int isEmpty(queue *q){ // determine if queue is empty
    return (q->rear == NULL);
}

void enqueue(queue *q, int item){ // insert an item into queue
    node *tmp = (node *)malloc(sizeof(node));
    tmp->data = item;
    if(q->rear == NULL){ // In case queue is currently empty.
        tmp->link = tmp;
    }else{
        tmp->link = q->rear->link;
        q->rear->link = tmp;
    }
    q->rear = tmp;
    printf("insert %d into queue.\n", item);
    return;
}

int dequeue(queue *q){ // delete an item from queue
    if(isEmpty(q)){
        printf("Queue is empty!!\n");
        exit(1);
    }else{
        if(q->rear->link == q->rear){ // Queue currently has only one node.
            node *tmp = q->rear;
            int item = q->rear->data;
            q->rear = NULL;
            free(tmp);
            printf("delete %d from queue.\n", item);
            return item;
        }else{ // The number of nodes is greater than 1.
            node *tmp = q->rear->link;
            int item = q->rear->link->data;
            q->rear->link = q->rear->link->link;
            free(tmp);
            printf("delete %d from queue.\n", item);
            return item;
        }
    }
}

int main()
{
    queue *q = (queue *)malloc(sizeof(queue));
    init_queue(q);


    int i;
    for(i=1; i<=100; i++){ // insert 100 items into queue
        enqueue(q, i);
    }

    printf("----------------------------\n");

    while(!isEmpty(q)){ // remove all items from queue
        dequeue(q);
    }

    free(q); // release memory of queue
    return 0;
}

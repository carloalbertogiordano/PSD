#include <stdlib.h>
#include "queue.h"
#include "list.h"

#define MAXQUEUE 50

struct queue{
     Item elements[MAXQUEUE];
     int head;
     int tail;
};

Queue newQueue(){
    Queue q = malloc(sizeof(struct queue));
    q->head=0;
    q->tail=0;
    return q;
}

int isEmptyQueue(Queue q){
    //if(q->head == q->tail)
        //return 1;
    return q->head == q->tail ? 1 : 0;
}

int enqueue(Queue q, Item item){
    if((q->tail+1) % MAXQUEUE == q->head)
        return 0;
    
    q->elements[q->tail] = item;
    q->tail = (q->tail+1) % MAXQUEUE;
    
    return 1;
}

Item dequeue(Queue q){
    if(q->head == q->tail)
        return NULL;
    
    Item tmp = q->elements[q->head];
    (q->head) = (q->head+1) % MAXQUEUE;
    
    return tmp;
}

void printQueue(Queue q){
    int i;
    
    for(i = q->head; i != q->tail; i = (i+1) % MAXQUEUE)
        outputItem(q->elements[i]);
}

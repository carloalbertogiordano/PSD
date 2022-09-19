#include <stdlib.h>
#include "queue.h"
#include "list.h"

struct queue{
    List elements;
};

Queue newQueue(){
    Queue q = malloc(sizeof(struct queue));
    q->elements = newList();
    return q;
}

int isEmptyQueue(Queue q){
    return isEmpty(q->elements);
}

int enqueue(Queue q, Item item){
    return addListTail(q->elements,item);
}

Item dequeue(Queue q){
    return removeHead(q->elements);
}

void printQueue(Queue q){
    printList(q->elements);
}

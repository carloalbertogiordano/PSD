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

/*T(n) = T(n-1) + 3 quindi siamo nel caso 1.a T(n)=aT(n-1)+...+ b -> O(T(n))=Lineare con n*/

void reverseQueue (Queue q){
    if(isEmptyQueue(q))
        return;
    Item it;
    it = dequeue(q);
    reverseQueue(q);
    enqueue(q, it);
}

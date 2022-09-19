#include <stdlib.h>
#include "queue.h"
#include "stack.h"

struct queue {
    Stack s1;
    Stack s2;
};

Queue newQueue() {
    Queue q = malloc(sizeof(struct queue));
    q->s1 = newStack();
    q->s2 = newStack();
    return q;
}

int isEmptyQueue(Queue q){
    return isEmptyStack(q->s1);
}

int enqueue(Queue q, Item item) {

    while (!isEmptyStack(q->s1)) {
        
        push(q->s2, top(q->s1));
        pop(q->s1);

    }
    
    push(q->s1, item);

    while (!isEmptyStack(q->s2)) {
        
        push(q->s1, top(q->s2));
        pop(q->s2);

    }
    return 1;
}

Item dequeue(Queue q) {
    
    Item item = top(q->s1);
    pop(q->s1);
    return item;

}

void printQueue(Queue q){
    printStack(q->s1);
}

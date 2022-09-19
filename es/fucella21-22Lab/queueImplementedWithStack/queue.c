#include "stack.h"
#include "item.h"
#include "queue.h"
#include <stdlib.h>

struct queue{
  Stack s1;
  Stack s2;
};

Queue newQueue(){
  struct queue *q = malloc(sizeof(struct queue));
  q->s1 = newStack();
  q->s2 = newStack();
  return q;
}

int isEmptyQueue(Queue q){
  return (isEmptyStack(q->s1) && isEmptyStack(q->s2)) ? 1:0;
}

void enqueue(Queue q, Item i){
  push(q->s1, i);
}

Item dequeue(Queue q){
  while (!isEmptyStack(q->s1)) {
    push(q->s2, top(q->s1));
    pop(q->s1);
  }
  Item tmp = top(q->s2);
  pop(q->s2);
  while (!isEmptyStack(q->s2)) {
    push(q->s1, top(q->s2));
    pop(q->s2);
  }
  return tmp;
}

void printQueue(Queue q){
  while (!isEmptyStack(q->s1)) {
    push(q->s2, top(q->s1));
    pop(q->s1);
  }
  while (!isEmptyStack(q->s2)) {
    push(q->s1, top(q->s2));
    outputItem(top(q->s2));
    pop(q->s2);
  }
}

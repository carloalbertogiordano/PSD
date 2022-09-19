#include <stdlib.h>
#include "list.h"
#include "item.h"
#include "stack.h"

struct stack {
  List elements;
};

Stack newStack(){
  Stack s = malloc(sizeof(struct stack));
  s->elements = newList();
  return s;
}

int isEmptyStack (Stack s){
  return isEmpty(s->elements);
}

int push(Stack st, Item i){
  addHead(st->elements, i);
  return 1;
}

int pop (Stack s){
  Item a = removeHead(s->elements);
  return a == NULL ? 0:1;
}

Item top(Stack s){
  return getHead(s->elements);
}

void printStack(Stack s){
  printList(s->elements);
}

int sizeStack(Stack s){
  return sizeList(s->elements);
}

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

void push(Stack st, Btree i){
  addHead(st->elements, i);
}

Btree pop (Stack s){
  Btree a = removeHead(s->elements);
  return a == NULL ? NULL:a;
}

Btree top(Stack s){
  return getHead(s->elements);
}

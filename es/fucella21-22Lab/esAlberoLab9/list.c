#include "list.h"
#include "item.h"
#include <stdlib.h>
#include <stdio.h>

struct list{
    int size;
    struct node *head;
};

struct node{
    Item value;
    struct node *next;
};

List newList() {
  List l = malloc(sizeof(struct list));
  l->head = NULL;
  l->size = 0;
}

int isEmpty(List l){
  return l->size == 0 ? 1:0;
}

void addHead(List l, Item elem){
  struct node *n = malloc(sizeof(struct node));
  n->value = elem;
  n->next = l->head;
  l->head = n;
  (l->size)++;
}

Item removeHead(List l){
  if(isEmpty(l)) return NULL;//If the list is NULL we need to return NULL because there is no first node
  struct node *t;
  Item oldNodeVal = l->head->value;
  t = l->head;
  l->head = l->head->next;
  free(t);
  (l->size)--;
  return (oldNodeVal);
}

Item getHead(List l){
  return l->head;
}

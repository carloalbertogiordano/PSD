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
  if(isEmpty(l))
    return NULL;
	return (l->head->value);
}

void printList(List l){
  struct node *p;
  for(p=l->head; p != NULL; p=p->next){
    outputItem(p->value);
  }
}

int searchItemPos(Item t, List l){
  struct node *n = l->head;
  Item tmp;

  for(int i = 0; i < l->size; i++){
    if(cmpItem(t, n->value) == 0){
      return i;
    }
    n = n->next;
  }
  return -1;
}

int addListItem(List l, Item e, int pos){
  struct node *p;
	int i;

	if(pos<0 || pos>(l->size)) return 0;

	if(pos==0){
		addHead(l,e);
		return 1;
	}
	else{
		for(p = l->head, i=0; i < pos-1; i++, p = p->next);

		struct node *newNode=malloc(sizeof(struct node));
		newNode->value=e;
		newNode->next=p->next;
		p->next=newNode;
		(l->size)++;
		return 1;
	}
}

int addListTail (List l, Item e){
	return addListItem(l,e,l->size);
}

void reverseList(List l){
  struct node *p,*prev=NULL,*temp;
	for(p = l->head; p != NULL; prev = p, p = temp)
	{
		temp=p->next;
		p->next=prev;
	}
	l->head=prev;
}

List cloneList(List l){
	struct node *p;
	List new=newList();
	for(p = l->head; p != NULL; p = p->next)
		addListTail(new,p->value);
	return new;
}

/* Funziona cerca elemento nella lista*/

Item searchList(List l, Item item, int *pos){
  *pos=0;
  struct node *p;
  for(p = l->head; p != NULL; p = p->next, (*pos)++)
    if(cmpItem(item, p->value) == 0)
      return p->value;
  *pos = -1;

  return NULL;
}

/* Funzione rimuovi elemento dalla lista */

Item removeListItem(List l, Item item){
	if(isEmpty(l))
		return NULL;
	Item pp;
  struct node *p;
	struct node *prev;
  for(p = l->head; p != NULL; prev = p, p = p->next)
    if(cmpItem(item, p->value) == 0)
    	if(p == l->head)
				return removeHead(l);
			else{
				prev->next = p->next;
				pp=p->value;
				free(p);
				(l->size)--;
				return pp;
			}

	return NULL;
}

Item removeListItemPos(List l, int pos){
	if(isEmpty(l))
		return NULL;
	int i=0;
	Item pp;
  struct node *p;
	struct node *prev;
	for(p = l->head; p != NULL; prev = p, p = p->next, i++)
    if(i == pos)
    	if(p == l->head)
				return removeHead(l);
			else{
				prev->next = p->next;
				pp=p->value;
				free(p);
				(l->size)--;
				return pp;
			}

	return NULL;
}

int sizeList(List l){ return l->size;}

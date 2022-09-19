#include"list.h"
#include <stdio.h>
#include <stdlib.h>

struct list
{
    int size;
    struct node *head;
};

struct node
{
    Item value;
    struct node *next;
};

List newList()
{
    List l=malloc(sizeof(struct list));
    l->size=0;
    l->head=NULL;
    return l;
}


int isEmpty(List l)
{
    if(l->size==0)
        return 1;
    return 0;
}


void addHead(List l, Item elem)
{
    struct node *n= malloc(sizeof(struct node));
    n->value=elem;
    n->next=l->head;
    l->head=n;
    (l->size)++;
}


Item removeHead(List l)
{
    Item elem;
    struct node *t;
    if(isEmpty(l))
        return NULL;
    t=l->head;
    l->head=t->next;
    elem=t->value;
    free(t);
    (l->size)--;
    return elem;
}


Item getHead(List l)
{
    if(isEmpty(l))
        return NULL;
    return l->head->value;
}


int sizeList(List l)
{
    return l->size;
}


void printList(List l)
{
    struct node* p;
    for(p=l->head;p!=NULL;p=p->next)
        outputItem(p->value);
} 


Item searchListItem(List l, Item item, int *pos)
{
	struct node* p;
    *pos=0;
    
    for(p=l->head; p!=NULL; p=p->next, (*pos)++)
    	if(cmpItem(item, p->value)==0)
    		return p->value;
    		
    (*pos)=-1;
    
    return NULL;
}

Item removeListItem(List l, Item item)
{
	if(isEmpty(l))
		return NULL;
	
	struct node *prev;
	struct node *p;
	Item val;
		
	for(p=l->head; p!=NULL; prev=p, p=p->next)
        if(cmpItem(item, p->value)==0)
        	if(p == l->head)
        		return removeHead(l);
        	else{
        		prev->next = p->next;
        		val = p->value;
        		free(p);
        		(l->size)--;
        		return val;
        	}
        	
    return NULL;
        	
}


Item removeListPos(List l, int pos)
{
	if(isEmpty(l))
		return NULL;
	
	struct node *prev;
	struct node *p;
	Item val;
	int i=0;
		
	for(p=l->head; p!=NULL; prev=p, p=p->next, i++)
        if(i==pos)
        	if(p == l->head)
        		return removeHead(l);
        	else{
        		prev->next = p->next;
        		val = p->value;
        		free(p);
        		(l->size)--;
        		return val;
        	}
        	
    return NULL;
        	
}

int addListPos(List l, Item e, int pos)
{
    if(pos >= 0 && pos<= l->size)
    {
        struct node *p;
        struct node *new = malloc(sizeof(struct node));
        int i;

        if(pos == 0)
        {
            addHead(l, e);
            return 1;
        }

        for(p = l->head, i = 0; i < pos-1 ; p = p->next, i++); 

        new->next = p->next;
        p->next = new;
        new->value = e;
        (l->size)++;

        return 1;
    }
    else return 0;
}

int addListTail(List l, Item e)
{
    return addListPos(l, e, l->size);
}

void reverseList(List l)
{
    struct node *prev, *p, *temp;

    for(prev = NULL, p = l->head ; p != NULL ; prev = p, p = temp)
    {
        temp = p->next;
        p->next = prev;
    }
    l->head = prev;
}

List cloneList(List l)
{
    List l1 = newList();
    struct node *p;

    for(p = l->head ; p != NULL ; p = p->next)  
        addListTail(l1, p->value);
    

    return l1;
}

List cloneListItem(List l)
{
    List l1 = newList();
    struct node *p;

    for(p = l->head ; p != NULL ; p = p->next)  
        addListTail(l1, cloneItem(p->value));
    

    return l1;
}

void printNodeRic (struct node *p) {

    if (p != NULL) {
        outputItem(p->value);
        printNodeRic(p->next);
    }
}

void printListRec (List l) {
    
    struct node *p;
    p = l->head;

    if (isEmpty(l)) {
        printf("La lista è vuota!!\n");
    }
    else {
        printNodeRic(p);
    }

}

struct node *getNodeSearch (struct node *p, Item i, int *pos) {

    if (p != NULL) {
        if (cmpItem(i, p->value) == 0)
            return p;
        *(pos)++;
        return getNodeSearch(p->next, i, pos);
    }

    return NULL;

}

Item searchListRic (List l, Item i, int *pos) {

    struct node *p;

    if (isEmpty(l))
        return NULL;
    
    p = getNodeSearch(l->head, i, pos);

    if (p != NULL)
        return p->value;
    else
        return NULL;
}

void countingItem (struct node *p, Item i, int *counter) {

    if (p != NULL) {
        if (cmpItem(p->value, i) == 0)
            (*counter)++;
        countingItem(p->next, i, counter);
    }

}

int countItemList (List l, Item i) {

    int counter = 0;

    if (isEmpty(l))
        return -1;
    
    countingItem(l->head, i, &counter);

    return counter;

}

void freeNode (struct node *p, int *counter) {

    struct node *temp;
    
    if (p != NULL) {
        temp = p->next;
        free(p);
        (*counter)++;
        freeNode(temp, counter);
    }

}

void destroyList (List l) {

    int counter = 0;

    freeNode(l->head, &counter);
    l->size -= counter;
    
}

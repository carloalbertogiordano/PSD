#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"


struct list {
    int size;
    struct node *head;
};

struct node {
    Item value;
    struct node *next;
};


List newList() {
    List list = malloc(sizeof(list));

    if (list == NULL) {
        fprintf(stderr, "Impossibile allocare memoria per la lista\n");
        exit(EXIT_FAILURE);
    }
        

    list->size = 0;
    list->head = NULL;

    return list;
}


int isEmpty(List list) {
    if (list->size > 0)
        return 1;

    return 0;
}


void addHead(List list, Item item) {
    struct node *n = malloc(sizeof(struct node));

    if (n == NULL) {
        fprintf(stderr, "Impossibile allocare memoria per la testa della lista\n");
        exit(EXIT_FAILURE);
    }
        

    n->value = item;
    n->next = list->head;

    list->head = n;
    (list->size)++;
}


Item removeHead(List list) {
    Item el;
    struct node *n;

    if (isEmpty(list))
        return NULL;

    n = list->head;
    list->head = n->next;
    el = n->value;

    free(n); // Cancello il puntatore della testa
    (list->size)--;

    return el;
}


Item getHead(List list) {
    if (isEmpty(list))
        return NULL;

    return list->head->value;
}


int sizeList(List list) {
    return list->size;
}


void printList(List list) {
    struct node *p;

    for (p = list->head; p != NULL; p = p->next)
        outputItem(p->value);
}


Item searchListItem(List list, Item item, int *pos) {
    struct node *p;
    *pos = 0;

    for (p = list->head; p != NULL; p = p->next, (*pos)++)
        if (!cmpItem(p->value, item))
                return p->value;

    (*pos) = -1;

    return NULL;
}


Item removeListItem(List list, Item item) {
    if (isEmpty(list))
        return NULL;

    struct node *prev;
    struct node *p;
    Item val;

    for (p = list->head; p != NULL; prev = p, p = p->next)
        if (!cmpItem(p->value, item)) {
             if (p == list->head)
                return removeHead(list);
            else {
                prev->next = p->next;
                val = p->value;
                free(p);
                (list->size)--;
                return val;
            }
        }
           

    return NULL;
}


Item removeListPos(List list, int pos) {
    if (isEmpty(list))
        return NULL;

    struct node *prev;
    struct node *p;
    Item val;
    int i = 0;

    for (p = list->head; p != NULL; prev = p, p = p->next, i++)
        if (i == pos) {
            if (p == list->head)
                return removeHead(list);
            else {
                prev->next = p->next;
                val = p->value;
                free(p);
                (list->size)--;
                return val;
            }
        }
            

    return NULL;
}


void sortList(List list) {
    struct node *p;
    struct node *min;

    for (p = list->head; p->next != NULL; p = p->next) {
        min = minList(p);
        swapItem(&p->value, &min->value);
    }
    
}


struct node * minList(struct node *p) {
    struct node *next;
    struct node *min = p;

    for (next = p->next; next != NULL; next = next->next) {
        if (cmpItem(min->value, next->value) > 0)
            min = next;
    }

    return min;
}


int addListPos(List list, Item item, int pos) {
    if (pos == 0) {
        addHead(list, item);
        return 1;
    } else if (pos < 0 || pos > list->size)
        return 0;

    struct node *p;
    int i = 0;
        
    for (p = list->head; i < pos - 1; p = p->next, i++);

    struct node *new = malloc(sizeof(struct node));

    if (new == NULL) {
        fprintf(stderr, "Impossibile allocare memoria per il nuovo nodo.\n");
        exit(EXIT_FAILURE);
    }
        

    new->value = item;
    new->next = p->next;
    p->next = new;
    (list->size)++;
    
    return 1;
}


int addListTail(List list, Item item) {
   return addListPos(list, item, list->size);
}


void reverseList(List list) {
    struct node *prev = NULL;
    struct node *p;
    struct node *temp;

    for (p = list->head; p != NULL; prev = p, p = temp) {
        temp = p->next;
        p->next = prev;
    }

    list->head = prev;
}


void destroyList(List list) {
    struct node *p;

    for (p = list->head; list->head != NULL; p= p->next) {
        list->head = p->next;
        free(p);
    }
        
    list->head = NULL;
}
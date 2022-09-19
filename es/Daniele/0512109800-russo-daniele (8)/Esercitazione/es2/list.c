#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "utils.h"


typedef struct list
{
    struct node* head;
    int size;
}list;

typedef struct node
{
    Item item;
    struct node* next;
}node;




// DEFINIZIONE FUNZIONI NON VISIBILI
node *getMinNode(node *p, node* currentMin);



List newList()
{
    List new=malloc(sizeof(list));

    new->head=NULL;
    new->size=0;

    return new;
}




int isEmptyList(List list)
{
    return list->size==0;
}




void addHeadList(List list, Item item)
{
    node* new=malloc(sizeof(node));

    if(new)
    {
        new->item=item;
        new->next=list->head;
        list->head=new;
        list->size++;
    }
}




int addTailList(List list, Item item)
{
    node *p, *prev;

    if(list->size==0)
    {
        addHeadList(list, item);
        return 1;
    }

    for(p=list->head; p!=NULL; prev=p, p=p->next);

    p=malloc(sizeof(node));

    if(p)
    {
        p->item=item;
        p->next=NULL;
        prev->next=p;
        list->size++;

        return 1;
    }
    return 0;
}




Item removeHeadList(List list)
{
    node *tmp=list->head;
    Item deletedItem=tmp->item;
    
    list->head=list->head->next;
    free(tmp);
    list->size--;

    return deletedItem;
}




Item getHeadList(List list)
{
    return list->head->item;
}




int getSizeList(List list)
{
    return list->size;
}




void outputList(List list)
{
    node *p;

    for(p=list->head; p!=NULL; p=p->next)
        outputItem(p->item);
}




Item searchList(List list, Item item, int *pos)
{
    node *p;

    for(*pos=0, p=list->head; p!=NULL; (*pos)++, p=p->next)
        if(cmpItemsTarga(p->item, item)==0)
            return p->item;

    *pos=-1;
    return NULL;
}




Item removeListForValue(List list, Item item)
{
    Item deletedItem;
    node *p, *prev;

    for(p=list->head; p!=NULL; prev=p, p=p->next)
        if(cmpItemsTarga(p->item, item)==0)
            if(p==list->head)
                return removeHeadList(list);
            else
            {
                prev->next=p->next;
                deletedItem=p->item;
                free(p);
                list->size--;

                return deletedItem;
            }

    return NULL;
}







void selectionSort(List list)
{
    node *p;

    for(p=list->head; p->next!=NULL; p=p->next)
        swap(&(p->item), &(getMinNode(p, p)->item));
}




// FUNZIONE NON VISIBILE
node *getMinNode(node *p, node* currentMin)
{
    if(p==NULL)
        return currentMin;

    if(cmpItemsAnnoP(p->item, currentMin->item)<0)
        currentMin=p;

    return getMinNode(p->next, currentMin);
}






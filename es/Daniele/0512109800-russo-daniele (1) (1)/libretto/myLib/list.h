#include "item.h"

typedef struct list *List;

List newList();
int isEmpty(List);
void addHead(List, Item);
Item removeHead(List);
Item getHead(List);
int sizeList(List);
void printList(List);
Item searchListItem(List, Item, int *);
Item removeListItem(List, Item);
Item removeListPos(List, int);
void sortList(List);
struct node *minList(struct node *);
int addListPos(List, Item, int);
int addListTail(List, Item);
void reverseList(List);
void destroyList(List);
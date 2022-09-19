#include "item.h"

typedef struct list *List;
List newList();
int isEmpty(List);
void addHead(List, Item );
Item removeHead(List);
Item getHead(List);
void printList(List);
int searchItemPos(Item, List);
int addListItem(List, Item , int);
int addListTail(List, Item);
void reverseList(List);
List cloneList(List);
int sizeList(List);
Item removeListItemPos(List, int);
Item removeListItem(List, Item);
Item searchList(List, Item, int *);

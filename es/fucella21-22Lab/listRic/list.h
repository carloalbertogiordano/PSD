#include "item.h"

typedef struct list *List;
List newList();
int isEmpty(List l);
void addHead(List l, Item elem);
Item removeHead(List l);
Item getHead(List l);
void printList(List l);
int searchItemPos(Item t, List l);
int addListItem(List l, Item item, int pos);
int addListTail (List l, Item e);
void reverseList(List l);
List cloneList(List l);
int sizeList(List l);
Item removeListItemPos(List l, int pos);
Item removeListItem(List l, Item item);
Item searchList(List l, Item item, int *pos);
void printListRic(List);
int countItemRic(List, Item);
Item searchItemRic(List,  Item);
void dealloclistRec(List);

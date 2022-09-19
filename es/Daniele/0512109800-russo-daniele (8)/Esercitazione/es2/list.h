#include "item.h"

typedef struct list* List;


List newList();
int isEmptyList(List list);
void addHeadList(List list, Item item);
int addTailList(List list, Item item);
Item removeHeadList(List list);
Item getHeadList(List list);
int getSizeList(List list);
void outputList(List list);
Item searchList(List list, Item item, int *pos);
Item removeListForValue(List list, Item item);
void selectionSort(List list);
#include "item.h"
#include "utils.h"


void swap(Item *a, Item *b)
{
    Item tmp=*a;
    *a=*b;
    *b=tmp;
}
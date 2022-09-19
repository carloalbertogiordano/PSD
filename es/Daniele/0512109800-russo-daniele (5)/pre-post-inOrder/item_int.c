#include <stdio.h>
#include <stdlib.h>
#include "item.h"


Item inputItem() {
        int *itemInt = malloc(sizeof(int));

        if (itemInt == NULL)
                fprintf(stderr, "Impossibile allocare memoria!\n");

        scanf("%d", itemInt);

        return itemInt;
}


void outputItem(Item item) {
        int *itemInt = item;
       
        printf("%d\t", *itemInt);
}


int cmpItem(Item itemA,Item  itemB) {
        int *itemIntA = itemA;
        int *itemIntB = itemB;

        return *itemIntA - *itemIntB;
}

Item cloneItem(Item e)
{
        int *itemInt = malloc(sizeof(int));
        int *p = e;
        *itemInt = *p;
        return itemInt;
}
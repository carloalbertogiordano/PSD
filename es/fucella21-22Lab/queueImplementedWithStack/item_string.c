#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"

#define MAX 20

Item inputItem() {
        char *itemString = malloc(MAX * sizeof(char));
        if (itemString == NULL) fprintf(stderr, "Err: cannot allocate required memory\n");
        scanf("%s", itemString);
        return itemString;
}

void outputItem(Item item) {
        char *itemString = item;
        printf("%s ", itemString);
}


int cmpItem(Item itemA,Item  itemB) {
        char *itemStringA = itemA;
        char *itemStringB = itemB;
        return strcmp(itemStringA, itemStringB);
}

int isAllocatedMemory(Item a){ int size = sizeof(a); return size==0 ? 1:0; }

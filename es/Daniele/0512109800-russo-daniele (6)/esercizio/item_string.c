#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"

#define MAX 20

Item inputItem() {
        char *itemString = malloc(MAX * sizeof(char));

        if (itemString == NULL)
                fprintf(stderr, "Impossibile allocare memoria!\n");

        scanf("%s", itemString);

        return itemString;
}


void outputItem(Item item) {
        char *itemString = item;

        printf("%s\t", itemString);
}


int cmpItem(Item itemA,Item  itemB) {
        char *itemStringA = itemA;
        char *itemStringB = itemB;

        return strcmp(itemStringA, itemStringB);
}

Item cloneItem(Item item){
  char *itemStr2 = malloc(MAX * sizeof(char));

  strcpy(itemStr2, item);

  return itemStr2;
}

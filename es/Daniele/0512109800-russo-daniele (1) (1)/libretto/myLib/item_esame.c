#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "esame.h"

Item inputItem() {

    return inputEsame();

}

void swapItem(Item *itemA, Item *itemB) {

    void *temp = *itemA;
    *itemA = *itemB;
    *itemB = temp;

}

void outputItem(Item item) {

    Esame es = item;

    printf("Denominazione Esame -> %s\n", getDenominazione(es));
    printf("Data Esame -> %d/%d/%d\n", getGiorno(es), getMese(es), getAnno(es));
    if (getVoto(es) == 30 &&  getLode(es) == true)
        printf("Voto -> %d con Lode\n", getVoto(es));
    else
        printf("Voto -> %d\n", getVoto(es));

}

int cmpItem (Item itemA, Item itemB) {

    Esame itemEsameA = itemA;
    Esame itemEsameB = itemB;

    return strcmp(getDenominazione(itemEsameA), getDenominazione(itemEsameB));
    
}

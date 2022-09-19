#include <stdio.h>
#include "item.h"
#include "list.h"

#define DIM 10


int main(){
    
    int i, pos, ele;
    Item elem;
    List l = newList();
    List l1 ;
    
    for(i=0;i<5;i++){
        printf("Inserisci %d elemento -> ", i + 1);
        elem=inputItem();
        addListTail(l, elem);
    }
    printListRec(l);
    printf("\n");

    printf("Inserisci l'elemento da cercare -> ");
    elem = inputItem();
    if (searchListRic(l, elem, &pos) != NULL)
        printf("Elemento trovato!\n");
    else
        printf("Elemento non trovato!\n");
    
    printf("Inserisci l'elemento da vedere -> ");
    elem = inputItem();

    printf("L'elemento e' ripetuto %d volte!\n", countItemList(l, elem));

    destroyList(l);

    printf("La dimensione della lista attualmente e' -> %d\n", sizeList(l));
    
    if (getHead(l) == NULL)
        printf("La lista e' vuota!\n");

    return 0;
}

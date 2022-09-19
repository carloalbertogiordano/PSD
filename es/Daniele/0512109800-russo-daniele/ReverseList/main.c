#include <stdio.h>
#include "item.h"
#include "queue.h"

int main(){

    int i;
    Item e;
    Queue q = newQueue();

    for(i=0;i<5;i++){
        printf("Inserisci un elemento: ");
        e = inputItem();
        if(!enqueue(q,e))
            fprintf(stderr,"Errore!!");
        printf("\n");

    }
    printQueue(q);
    printf("\n");
    reverseQueue(q);
    printQueue(q);
    printf("\n");
    return 0;
}

#include <stdio.h>
#include "item.h"
#include "queue.h"

int main(){

    int i,q;
    Item elem;
    Queue queue = newQueue();

    for(i=0;i<5;i++){
        printf("Inserisci un elemento: ");
        elem = inputItem();
        if(!enqueue(queue,elem))
            fprintf(stderr,"Impossibile accodare");
        printQueue(queue);
        printf("\n");

    }

    for(i=0;i<5;i++){
        dequeue(queue);
        printQueue(queue);
        printf("\n");
    }
	
	if(isEmptyQueue(queue)==1)
		printf("La coda e vuota;\n");
		
    return 0;
}

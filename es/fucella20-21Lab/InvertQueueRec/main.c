#include <stdio.h>
#include "item.h"
#include "queue.h"
#include <stdlib.h>

int main(){
	int i = 0;
	Queue q;
	Item a;
	q = newQueue();

	for(i = 0; i < 5; i++){
		printf("\nInsert value : ");
		a = inputItem();
		enqueue(q,a);
		printf("Queue : \t");
		printQueue(q);
	}

	printf("\n\n");

	invertQueueRec(q);
	printQueue(q);
	free(q);
}
